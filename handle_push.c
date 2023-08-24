#include "monty.h"
#include <stdbool.h>

/**
 * is_integer - checks if a string represents a valid integer
 * Desc: checks if a strig rep a valid integer
 * @str: string
 * @*str: string pointer
 * Return: true if the string is a valid integer, false otherwise
 */
bool is_integer(const char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (false);

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}

	return (true);
}

/**
 * handle_push - adds n element to the top of the stack
 * @head: pointer to the head of a stack
 * @line_number: line number of the monty instructions file
 */
void handle_push(stack_t **head, unsigned int line_number)
{
	char *arg = value;
	stack_t *new_node;
	int n_value;

	if (arg == NULL || is_integer(arg))
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n_value = atoi(arg);
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n_value;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}
