#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned long integer is a palindrome
 * @n: Number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long divisor;

	divisor = 1;

	while (n / divisor >= 10)
		divisor *= 10;

	while (n != 0)
	{
		if ((n / divisor) != (n % 10))
			return (0);

		n = (n % divisor) / 10;
		divisor /= 100;
	}

	return (1);
}
