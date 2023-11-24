#include "main.h"
/**
 * binary_to_uint - function converts a binary number to an unsigned int.
 * @b: pointer to a string containing a binary number
 *
 * Return: unsigned int with decimal value of binsry number, or 0 if error
 */
unsigned int binary_to_uint(const char *b)
{
	
	unsigned int num = 0;

	num = 0;
	if (!b)
		return (0);
	while (*b)
	
	{
		if (*b!= '0' && *b!= '1')
			return (0);
		num = num *2+(*b++ - '0');
	}
	return (num);
}
