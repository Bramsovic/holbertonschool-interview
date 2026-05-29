# Linked List Cycle

This project contains a C function that checks whether a singly linked list has
a cycle.

## Files

- `0-check_cycle.c`: implements `check_cycle`
- `lists.h`: header file with the list structure and function prototypes

## Prototype

```c
int check_cycle(listint_t *list);
```

## Return Value

- `0` if the linked list has no cycle
- `1` if the linked list has a cycle

## Compilation

```sh
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```

