#include "main.h"

/**
 * read_textfile- Reads a text file and print to STDOUT.
 * @filename: name of text file being read
 * @letters: number of letters to be read and print
 * Return: w- actual number of bytes read and printed
 * 	0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t o;
	ssize_t w;
	ssize_t r;

	if (filename == NULL);
		return (0);

	buf = malloc(sizeof(char) * letters);
	o = open(filename, O_RDONLY);
	r = read(o, buf, letters);
	w = write(STDOUT_FILENO, buf, r);

	if (o == -1 || r == -1 || w == -1 || w != r) 
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(o);
	return (w);
}
