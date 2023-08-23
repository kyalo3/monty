#include "monty.h"
#define BUFFERSIZE 1024
/**
 * read_monty_file - reads a monty file
 * @filename: file to read
 */

void read_monty_file(const char *filename)
{
	ssize_t fd, chars_read, chars_written;
	char buffer[BUFFERSIZE];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((chars_read = read(fd, buffer, BUFFERSIZE)) > 0)
	{
		chars_written = write(STDOUT_FILENO, buffer, chars_read);
		if (chars_written == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * main - get file
 * @ac: number of arguments
 * @av: arguments
 * Return: 0 (success)
 */

int main(int ac, char **av)
{
	(void)av;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_monty_file(av[1]);
	return (0);
}
