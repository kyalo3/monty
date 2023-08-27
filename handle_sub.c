#include "monty.h"

/**
 * handle_sub - subtracts the top element of the stack from
 * the second top element of the stac
 * @head: double pointer to the head of the stack
 * @line_number: line number of the instruction in the file
 */
void handle_sub(stack_t **head, unsigned int line_number)
{
	stack_t *top1, *top2;

	if (*head == NULL || (*head)->next == NULL)
	{
		free_all();
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top1 = *stack;
	top2 = (*stack)->next;
	top2->n = top2->n - top1->n;
	*stack = top2;
	free(top1);
}
