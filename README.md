# Check if a string is a valid IPv4 address or not

Our "Fizz Buzz" interview question is to ask a candidate to validate an IPv4 address in Python.
We have a 50/50 split of candidates using regex versus left to right scanning.

This is my solution in C which attempts to avoid requiring using a C library.
There's a few constraints: IP addresses must be in dotted quad form, and each octet
must not have leading zeroes. It also runs in constant time as it bounds each
octet substring to at most 3 characters, only checking at most 4 octets.

# Build & test

```
make
./main
```

# Expected output

```
Valid IPv4 addresses:

  -- '0.0.0.0' is valid
  -- '127.0.0.1' is valid
  -- '127.127.0.1' is valid
  -- '127.127.127.127' is valid
  -- '1.0.0.1' is valid

Invalid IPv4 addresses:

  -- '(null)' is invalid
  -- '' is invalid
  -- 'abcd' is invalid
  -- '1.1' is invalid
  -- '1.1.1' is invalid
  -- '1.1.1.1.1' is invalid
  -- '1.1.1.1.' is invalid
  -- '01.0.0.1' is invalid
  -- '256.0.0.1' is invalid
  -- 'a.b.c.d' is invalid
  -- '1024.1.1.1' is invalid
  -- '-0.0.0.0' is invalid
  -- '+0.0.0.0' is invalid
  -- '0 .0.0.0' is invalid
  -- ' 0.0.0.0' is invalid
```
