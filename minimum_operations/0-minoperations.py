#!/usr/bin/python3
"""Minimum operations module."""


def minOperations(n):
    """Return the fewest copy/paste operations needed to produce n H chars.

    Starting with one ``H``, each useful sequence is a "Copy All" followed by
    one or more "Paste" operations. Splitting ``n`` into factors gives the
    minimum number of operations, which is the sum of its prime factors.
    """
    if not isinstance(n, int) or n < 2:
        return 0

    operations = 0
    factor = 2

    while factor * factor <= n:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    if n > 1:
        operations += n

    return operations
