#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read a text file and print it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 * Otherwise - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;	/* File descriptors for input/output */
	char *buffer;		/* Buffer to store read data */

	if (filename == NULL)	/* Check if filename is NULL */
		return (0);

	buffer = malloc(sizeof(char) * letters);	/* Allocate memory for buffer */
	if (buffer == NULL)	/* Check if memory allocation failed */
		return (0);

	o = open(filename, O_RDONLY);	/* Open file for reading */
	r = read(o, buffer, letters);	/* Read data from file into buffer */
	w = write(STDOUT_FILENO, buffer, r);	/* Write data from buffer to stdout */

	if (o == -1 || r == -1 || w == -1 || w != r)	/* Check for errors */
	{
		free(buffer);	/* Free memory allocated for buffer */
		return (0);
	}

	free(buffer);	/* Free memory allocated for buffer */
	close(o);	/* Close file */

	return (w);	/* Return number of bytes read and printed */
}
