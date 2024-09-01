#include <stdio.h>
#include "check_ip.h"

int main(int argc, char **argv)
{
    int exit_code = 0;

    char *valid[] = {
        "0.0.0.0",
        "127.0.0.1",
        "127.127.0.1",
        "127.127.127.127",
        "1.0.0.1",
    };

    printf("Valid IPv4 addresses:\n\n");

    for (size_t i = 0; i < (sizeof(valid) / sizeof(valid[0])); i++)
    {
        if (is_valid_ipv4(valid[i]))
        {
            printf("  -- '%s' is valid\n", valid[i]);
        }
        else
        {
            exit_code = 1;
            printf("  -- '%s' is invalid (should be valid)\n", valid[i]);
        }
    }

    printf("\nInvalid IPv4 addresses:\n\n");

    char *invalid[] = {
        NULL,
        "",
        "abcd",
        "1.1",
        "1.1.1",
        "1.1.1.",
        "1.1.1.1.",
        "1.1.1.1.1",
        "01.0.0.1",
        "256.0.0.1",
        "a.b.c.d",
        "1024.1.1.1",
        "-0.0.0.0",
        "+0.0.0.0",
        "0 .0.0.0",
        " 0.0.0.0",
    };

    for (size_t i = 0; i < (sizeof(invalid) / sizeof(invalid[0])); i++)
    {
        if (!is_valid_ipv4(invalid[i]))
        {
            printf("  -- '%s' is invalid\n", invalid[i] ? invalid[i] : "(null)");
        }
        else
        {
            exit_code = 1;
            printf("  -- '%s' is valid (should be invalid)\n", invalid[i] ? invalid[i] : "(null)");
        }
    }

    return exit_code;
}
