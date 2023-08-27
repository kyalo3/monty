#include "monty.h"

char *value = "";
stack_t **stack;
char **args = NULL;
char *line = NULL;

/**
 * read_monty_file - reads a monty file
 * @filename: file to read
 */
void read_monty_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;

	line = NULL;
	if (file == NULL)
	{
		free_all();
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		execute_cmds(line, line_number);
		line_number++;
	}
	free(line);
	fclose(file);
}

/**
 * tokenize_line - breaks line into small tokens
 * @line:line to be tokenized
 */
void tokenize_line(char *line)
{
	char *token;
	int ac = 0, i;

	args = (char **)malloc((MAX_LINE_LENGTH + 1) * sizeof(char *));
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
}

/**
 * execute_cmds - Tokenizes and executes monty commands
 * @line: line with opcodes
 * @line_number: monty instructions line number
 */

void execute_cmds(char *line, unsigned int line_number)
{
	char *instruction;
	int i = 0;

	tokenize_line(line);
	for (i = 0; args[i] != NULL;)
	{
		instruction = args[i];

		if (strcmp(instruction, "push") == 0)
		{
			value = args[++i];
			i++;
		}
		else
		{
			i++;
		}
		if (instruction[0] != '#')
			execute_opcode(instruction, line_number);
		else
			break;
	}
	free(args);
}

/**
 * execute_opcode - Executes a specific opcode
 * @opcode: The opcode to execute
 * @line_number: The line number of the instruction
 */
void execute_opcode(const char *opcode, unsigned int line_number)
{
	int j = 0;
	instruction_t ops[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pop", handle_pop},
		{"pint", handle_pint},
		{"add", handle_add},
		{"swap", handle_swap},
		{"nop", handle_nop},
		{"sub", handle_sub},
		{"div", handle_div},
		{"mul", handle_mul},
		{"mod", handle_mod},
		{NULL, NULL}};

	while (ops[j].opcode != NULL)
	{
		if (strcmp(ops[j].opcode, opcode) == 0)
		{
			ops[j].f(stack, line_number);
			return;
		}
		j++;
	}
	free_all();
	dprintf(2, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
