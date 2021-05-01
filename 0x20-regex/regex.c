#include "regex.h"
#include <stdio.h>
/**
 * regex_match - checks whether a given pattern matches a given string.
 *
 * @str: string to compare.
 * @pattern: pattern to campare to.
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0' && *str == '\0')
		return (1);
	if (*pattern == '\0' || *str == '\0')
		return (0);
	if (*pattern == '.' && *(pattern + 1) == '*' && *(pattern + 2) == '\0')
		return (1);
	if (*(pattern + 1) == '*')
	{
		if (*(pattern) == '.')
		{
			return (regex_match(str, pattern + 2) || regex_match(str + 1, pattern));
		}
		if (*(pattern) != *str)
			return (regex_match(str, pattern + 2));
		if (*(pattern) == *str && *(str + 1) == *str)
			return (regex_match(str + 1, pattern));
		if (*(str + 1) != *str)
			return (regex_match(str + 1, pattern + 2));
	}
	if (*pattern == *str || *pattern == '.')
	{
		return (regex_match(str + 1, pattern + 1));
	}
	return (0);
}
