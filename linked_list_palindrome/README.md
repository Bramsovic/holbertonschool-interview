# Linked List Palindrome

Technical interview preparation project.

## Task

Write a function in C that checks if a singly linked list is a palindrome.

```c
int is_palindrome(listint_t **head);
```

## Return Value

- `1` if the linked list is a palindrome
- `0` if the linked list is not a palindrome

An empty list is considered a palindrome.

## Files

- `0-is_palindrome.c` - contains the `is_palindrome` function
- `lists.h` - contains the linked list structure and function prototypes

## Compilation

The files are compiled on Ubuntu 14.04 LTS with:

```sh
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

## Requirements

- Betty style
- No global variables
- No more than 5 functions per file
- All prototypes must be declared in `lists.h`
- Header files must be include guarded
