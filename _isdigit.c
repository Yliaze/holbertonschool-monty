#include "monty.h"

/**
 * _isdigit - checks for a digit
 * (0 through 9).
 *
 * @c: The character in ASCII code
 *
 * Return: 1 for digit. 0 otherwise.
 */
int _isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}