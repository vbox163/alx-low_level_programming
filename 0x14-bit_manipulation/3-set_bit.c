#include <stdio.h>
#include "main.h"

/**
 * set_bit - Set the value of a bit at a given index to 1
 * @n: Pointer to the unsigned long int to modify
 * @index: The index of the bit to set to 1
 *
 * Return: 1 if successful, -1 if an error occurs
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int revnum; /* Reversed number for bit manipulation */
	unsigned long int num; /* Final number with bit set to 1 */
	unsigned long int count; /* Variable to keep track of bit position */
	unsigned long int oldn; /* Copy of original number for manipulation */

	revnum = count = num = 0; /* Initialize variables */
	oldn = *n; /* Store original number in oldn for manipulation */
	if (index > 63) /* Check if index is out of range (0-63) */
		return (-1); /* Return -1 for error */
	while (count < 63) /* Loop until all bits of oldn are processed */
	{
		revnum = revnum << 1; /* Shift revnum left by 1 for next bit */
		if (count == index) /* Check if count matches index */
			revnum += 1; /* Set bit at index to 1 in revnum */
		else
			revnum += oldn & 1; /* Copy least significant bit of oldn to revnum */
		count++; /* Increment count for next iteration */
		oldn = oldn >> 1; /* Shift oldn right by 1 to process the next bit */
	}
	while (count > 0) /* Loop until all bits of revnum are processed */
	{
		num = num << 1; /* Shift num left by 1 for next bit */
		num += revnum & 1; /* Copy least significant bit of revnum to num */
		revnum = revnum >> 1; /* Shift revnum right by 1 to process the next bit */
		count--; /* Decrement count for next iteration */
	}
	*n = num; /* Update n with the new value of num */
	return (1); /* Return 1 for success */
}
