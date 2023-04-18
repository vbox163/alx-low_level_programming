#include <stdio.h>
#include "main.h"

/* Function to print binary representation of an unsigned long int */
void print_binary(unsigned long int n)
{
	unsigned long int revnum; /* Reversed binary representation */
	unsigned long int count; /* Number of bits in the binary representation */

	revnum = count = 0;
	if (n == 0)
		putchar('0');
	while (n > 0)
	{
		revnum = revnum << 1;
		revnum += n & 1;
		count++;
		n = n >> 1;
	}
	while (revnum > 0)
	{
		putchar((revnum & 1) + '0');
		revnum = revnum >> 1;
		count--;
	}
	if (count > 0)
	{
		while (count != 0)
		{
			putchar('0');
			count--;
		}
	}
}
