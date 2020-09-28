#include "slide_line.h"
#include "stdio.h"
/**
 * slide_line - slides and merges an array of integers
 *
 * @line: line of int
 * @size: size of the line
 * @direction: indicates which direction to slide
 *
 * Return: 1 on success, or 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (!line)
		return (0);
	slide_all(line, size, direction);
	treat_line(line, size, direction);
	slide_all(line, size, direction);
	return (1);
}

/**
 * treat_line - sums two consécutif numbers
 *
 * @line: line of int
 * @size: size of the line
 * @direction: indicates which direction to slide
 *
 * Return: nothing.
 */
void treat_line(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_LEFT)
		for (i = 0; i < size - 1; i++)
		{

			if (line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
		}
	else
		for (i = size - 1; i > 0; i--)
			if (line[i] == line[i - 1])
			{
				line[i] *= 2;
				line[i - 1] = 0;
			}
}

/**
 * slide_all - sums two consécutif numbers
 *
 * @line: line of int
 * @size: size of the line
 * @direction: indicates which direction to slide
 *
 * Return: nothing.
 */
void slide_all(int *line, size_t size, int direction)
{
	size_t i, num_zeros = 0;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
		{
			if (line[i] == 0)
				num_zeros++;
			if (line[i] && num_zeros)
			{
				line[i - num_zeros] = line[i];
				line[i] = 0;
			}
		}
	}
	else
	{
		for (i = size - 1; i >= 1; i--)
		{
			if (line[i] == 0)
				num_zeros++;
			if (line[i] && num_zeros)
			{
				line[i + num_zeros] = line[i];
				line[i] = 0;
			}
		}
		if (line[i] == 0)
			num_zeros++;
		if (line[i] && num_zeros)
		{
			line[i + num_zeros] = line[i];
			line[i] = 0;
		}
	}
}
