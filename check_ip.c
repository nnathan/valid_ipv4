#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

static inline unsigned long digits_to_num(char *s, size_t num_digits)
{
    assert(num_digits >= 1);
    assert(num_digits <= 3);

    unsigned long v = 0;

    switch (num_digits)
    {
        case 3:
            v += (s[0] - '0') * 100;
            v += (s[1] - '0') *  10;
            v += (s[2] - '0') *   1;
            break;
        case 2:
            v += (s[0] - '0') *  10;
            v += (s[1] - '0') *   1;
            break;
        case 1:
            v += (s[0] - '0');
            break;
        default:
            break;
    }

    return v;
}

bool is_valid_ipv4(char *addr)
{
    if (!addr)
    {
        return false;
    }

    char *start = addr;
    char *p = addr;

    int num_components = 0;

    bool startswith_0 = false;

    while (*p != '\0')
    {
        if ((p - start) == 0)
        {
            if (*p == '0')
            {
                startswith_0 = true;
                p++;
                continue;
            }
            else if (*p == '1' || *p == '2')
            {
                p++;
                continue;
            }

            return false;
        }

        assert((p - start) >= 1);

        if (*p == '0')
        {
            /* 001.1.1.1 */
            if (startswith_0)
            {
                return false;
            }

            /* 1230.1.1.1 */
            if ((p - start) >= 3)
            {
                return false;
            }

            /* 10.100.1.1 */
            p++;
            continue;
        }

        if (*p >= '1' && *p <= '9')
        {
            /* 01.1.1.1 */
            if (startswith_0)
            {
                return false;
            }

            /* 1234.0.0.0 */
            if ((p - start) >= 3)
            {
                return false;
            }

            p++;
            continue;
        }

        if (*p == '.')
        {
            /* 123.123.123.123. */
            if (num_components == 3)
            {
                return false;
            }

            assert((p - start) >= 1);
            assert((p - start) <= 3);

            unsigned long v = digits_to_num(start, p - start);

            if (v > 255)
            {
                return false;
            }

            num_components++;
            p++;
            start = p;
            startswith_0 = false;
            continue;
        }

        return false;
    }

    /* 123 / 123.123 / etc. */
    if (num_components != 3)
    {
        return false;
    }

    /* 123.123.123. */
    if ((p - start) == 0)
    {
        return false;
    }

    /* 123.123.123.123 */
    unsigned long v = digits_to_num(start, p - start);

    if (v > 255)
    {
        return false;
    }

    return true;
}
