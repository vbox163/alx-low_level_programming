#include "main.h"

/**
 * flip_bits - Find the number of bits needed to flip to change
 * one number to the other
 * @n: First number to check bits
 * @m: Second number to check bits
 *
 * Return: Number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int nlen; /* Number of bits in n */
	unsigned long int mlen; /* Number of bits in m */
	unsigned long int flip; /* Number of bits to flip */
	unsigned long int storen; /* Store n for manipulation */
	unsigned long int storem; /* Store m for manipulation */

	/* Initialize variables */
	nlen = mlen = flip = 0;
	storen = n;
	storem = m;

	/* Count number of bits in n */
	while (n > 0)
	{
		n = n >> 1; /* Shift n right by 1 to count next bit */
		nlen++; /* Increment nlen for next iteration */
	}

	/* Count number of bits in m */
	while (m > 0)
	{
		m = m >> 1; /* Shift m right by 1 to count next bit */
		mlen++; /* Increment mlen for next iteration */
	}

	m = storem; /* Restore m from storem for comparison */
	n = storen; /* Restore n from storen for comparison */

	/* Compare number of bits in m and n */
	if (mlen > nlen)
		flip = compare_bits(m, n, mlen, &flip);
	else
		flip = compare_bits(n, m, nlen, &flip);

	return (flip); /* Return the number of bits to flip */
}

/**
 * compare_bits - Compare bits of two numbers and count differences
 * @a: First number to compare bits
 * @b: Second number to compare bits
 * @len: Number of bits to compare
 * @flip: Pointer to number of bits to flip
 *
 * Return: Number of bits to flip
 */
unsigned int compare_bits(unsigned long int a, unsigned long int b,
						  unsigned long int len, unsigned int *flip)
{
	/* Loop until all bits are processed */
	while (len > 0)
	{
		/* Compare least significant bits of a and b */
		if ((a & 1) != (b & 1))
			*flip += 1; /* Increment flip for different bits */
		a = a >> 1; /* Shift a right by 1 to process the next bit */
		b = b >> 1; /* Shift b right by 1 to process the next bit */
		len--; /* Decrement len for next iteration */
	}

	return (*flip); /* Return the number of bits to flip */
}
