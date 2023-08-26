#include "monty.h"

char *value = "";
stack_t **stack;

/**
 * read_monty_file - reads a monty file
 * @filename: file to read
 */
void read_monty_file(const char *filename)
{
	int fd;
	ssize_t chars_read;
	char buffer[BUFFERSIZE], *buffer_pos;
	char *line, *newline_pos;
	int line_number = 1;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free_all();
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	buffer_pos = buffer;
	while ((chars_read = read(fd, buffer, BUFFERSIZE)) > 0 &&
		   line_number < MAX_LINES)
	{
		buffer[chars_read] = '\0';
		while (*buffer_pos != '\0')
		{
			newline_pos = strchr(buffer_pos, '\n');
			if (newline_pos != NULL)
			{
				*newline_pos = '\0';
				line = buffer_pos;
				buffer_pos = newline_pos + 1;
			}
			else
			{
				line = buffer_pos;
				buffer_pos += strlen(buffer_pos);
			}
			execute_cmds(line, line_number);
			line_number++;
		}
	}
	buffer_pos = buffer;
	close(fd);
}
/**
 * tokenize_line - breaks line into small tokens
 * @line:line to be tokenized
 * Return: pointer to the args array containing tokens
 */
char **tokenize_line(char *line)
{
	char **args = (char **)malloc((MAX_LINE_LENGTH + 1) * sizeof(char *));
	char *token;
	int ac = 0, i;

	if (args == NULL)
	{
		free_all();
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < MAX_LINE_LENGTH + 1; i++)
	{
		args[i] = NULL;
	}
	token = strtok(line, " \t\n");
	while (token != NULL && ac < MAX_LINE_LENGTH - 1)
	{
		args[ac] = token;
		ac++;
		token = strtok(NULL, " \t\n");
	}
	args[ac] = NULL;
	return (args);
}

/**
 * execute_cmds - executes monty command
 * @line: line with opcodes
 * @line_number: monty instructions line number
 */

void execute_cmds(char *line, unsigned int line_number)
{
	char *instruction, **args;
	int i = 0, j = 0;
	instruction_t ops[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pop", handle_pop},
		{"pint", handle_pint},
		{"add", handle_add},
		{"swap", handle_swap},
		{NULL, NULL}};

	args = tokenize_line(line);
	i = 0;
	while (args[i] != NULL)
	{
		j = 0;
		instruction = args[i];
		value = args[(i + 1)];
		while (ops[j].opcode != NULL)
		{
			if (strcmp(ops[j].opcode, instruction) == 0)
			{
				i += 2;
				ops[j].f(stack, line_number);
				break;
			}
			j++;
		}
		if (instruction && ops[j].opcode == NULL)
		{
			free(args);
			free_all();
			dprintf(2, "L%d: unknown instruction %s\n", line_number, instruction);
			exit(EXIT_FAILURE);
		}
	}
	free(args);
}
