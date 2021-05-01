#include "holberton.h"
/**
 * wildcmp - compares two strings and returns
 *
 * @string: string to compare.
 * @pattern: string 2 which contains wildcards.
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */

int wildcmp(char *string, char *pattern)
{
	if (*pattern == '\0' && *string == '\0')
		return (1);

	if (*pattern == *string)
		return (wildcmp(string + 1, pattern + 1));

	if (*pattern == '*')
	{
		if (*(pattern + 1) == '*')
			return (wildcmp(string, pattern + 1));
		return (wildcmp(string + 1, pattern) || wildcmp(string, pattern + 1));
	}
	return (0);
}
