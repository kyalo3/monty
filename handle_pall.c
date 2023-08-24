#include "monty.h"
/**
 * handle_pall - Print all elements of the stack.
 * @head: Pointer to the top of the stack.
 * @line_number: Line number in the script where the opcode was found.
 *
 * Description: Prints all the integer elements currently in the stack,
 * from the top to bottom, followed by a newline.
 * If the stack is empty, this function does nothing.
 */
void handle_pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	(void)line_number;
	while (current != NULL)
	{
		dprintf(1, "%d\n", current->n);
		current = current->next;
	}
}
