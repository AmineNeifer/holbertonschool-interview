#include "palindrome.h"
#include <stdio.h>
/**
 * is_palindrome - checks if a given unsigned integer is a palindrome
 *
 * @n: unsigned long which we are going to check if it is a palindrome
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long tens = 1;
	int last, first, i, o;

	if (n < 10)
		return (1);
	o = order(n);
	for (i = 0; i < o; i++)
		tens *= 10;
	last = n / tens;
	first = n % 10;

	if (last == first)
	{
		n /= 10;
		n %= 10;
		return (is_palindrome(n));
	}
	return (0);
}
/**
 * last_digit - checks for the last digit's order in n
 *
 * @n: unsigned long
 *
 * Return: 2 if n = 230, 3 if n = 2303 ...
 */
int order(unsigned long n)
{
	int tens = 0;
	unsigned long i = n;

	while (i / 10 != 0)
	{
		tens++;
		i /= 10;
	}
	return (tens);
}
