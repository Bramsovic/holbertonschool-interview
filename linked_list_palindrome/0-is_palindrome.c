#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *second, *prev, *next, *first, *restored;
	int palindrome = 1;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast != NULL)
		second = slow->next;
	else
		second = slow;

	prev = NULL;
	while (second != NULL)
	{
		next = second->next;
		second->next = prev;
		prev = second;
		second = next;
	}

	second = prev;
	first = *head;
	while (second != NULL)
	{
		if (first->n != second->n)
		{
			palindrome = 0;
			break;
		}
		first = first->next;
		second = second->next;
	}

	second = prev;
	restored = NULL;
	while (second != NULL)
	{
		next = second->next;
		second->next = restored;
		restored = second;
		second = next;
	}

	return (palindrome);
}
