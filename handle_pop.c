#include "monty.h"
/**
 * handle_pop - Remove the top element of the stack.
 * @head: Pointer to the top of the stack.
 * @line_number: Line number in the script where the opcode was found.
 *
 * Description: Removes the top element of the stack. If the stack is empty,
 * print the error message "L<line_number>: can't pop an empty stack",
 * followed by a newline, and exit with the status EXIT_FAILURE.
 */
void handle_pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		free_all();
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(temp);
}
