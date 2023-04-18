#include "main.h"

/**
 * create_file - Creates a file.
 *
 * @filename: Pointer to the name of the file.
 * @text_content: Pointer to string to write.
 *
 * Return: -1 on failure, 1 on success.
 */
int create_file(const char *filename, char *text_content)
{
int o, w, len = 0; /* File descriptor, write count */
			      /* and length of text_content */

	if (filename == NULL) /* Check if filename is NULL */
		return (-1); /* Return -1 for failure */

	if (text_content != NULL) /* Check if text_content is not NULL */
	{
		for (len = 0; text_content[len];) /* Calculate length of text_content */
			len++;
	}

	o = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	/* Open file with flags */
	w = write(o, text_content, len); /* Write text_content to file */

	if (o == -1 || w == -1) /* Check for errors in opening or writing to file */
		return (-1); /* Return -1 for failure */

	close(o); /* Close file descriptor */

	return (1); /* Return 1 for success */
}
