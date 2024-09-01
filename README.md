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

# Other Notable Implementations

[skeeto](https://github.com/skeeto) has a very compact and impressively readable version of an IPv4 parser that can be found [here](https://github.com/skeeto/scratch/blob/2af9b076117838b93fc2fddeac423a0ac1985db2/prips/prips.c#L227-L259) (only supports dotted quads).

lwIP has an implementation of an IPv4 parser that is very liberal and supports addresses that can usually be passed to the `ping` command, which is called [ip4addr_aton](https://git.savannah.nongnu.org/cgit/lwip.git/tree/src/core/ipv4/ip4_addr.c?h=STABLE-2_1_x#n133).
