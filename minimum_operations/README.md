#!/usr/bin/python3
# Minimum Operations

This project contains a Python function that calculates the fewest number of
`Copy All` and `Paste` operations needed to produce exactly `n` `H`
characters, starting from one `H`.

## File

- `0-minoperations.py`: defines `minOperations(n)`.

## Approach

The minimum number of operations is the sum of the prime factors of `n`.
Each factor represents one `Copy All` operation plus the required number of
`Paste` operations to multiply the current number of characters by that factor.
