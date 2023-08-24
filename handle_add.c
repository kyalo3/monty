#include "monty.h"

/**
 * handle_add - adds the top two elements of the stack
 * @head: double pointer to the head of the stack
 * @line_number: line number of the instruction in the file
 */
void handle_add(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n += (*head)->n;
	handle_pop(head, line_number);
}
