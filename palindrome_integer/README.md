# Palindrome Integer

## Description

This project contains a function that checks whether an unsigned integer is a
palindrome.

A number is a palindrome when it can be read the same way from left to right and
from right to left.

## Prototype

```c
int is_palindrome(unsigned long n);
```

## Return Value

- `1` if `n` is a palindrome
- `0` otherwise

## Requirements

- Ubuntu 14.04 LTS
- `gcc 4.8.4`
- Compilation flags:

```sh
gcc -Wall -Werror -Wextra -pedantic
```

- No global variables
- No dynamic memory allocation
- Betty style compliant

## Files

- `0-is_palindrome.c`: contains the `is_palindrome` function
- `palindrome.h`: contains the function prototype

## Example

```sh
gcc -Wall -Wextra -Werror -pedantic -o palindrome 0-main.c 0-is_palindrome.c
./palindrome 121
```

Output:

```text
121 is a palindrome.
```
