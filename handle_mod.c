#include "monty.h"

/**
 * handle_mod - computes the rest of the division
 * of the second top element of the stack by
 * the top element of the stack.
 * @head: double pointer to the head of the stack
 * @line_number: line number of the instruction in the file
 */
void handle_mod(stack_t **head, unsigned int line_number)
{
	stack_t *top1, *top2;

	if (*head == NULL || (*head)->next == NULL)
	{
		free_all();
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top1 = *stack;
	top2 = (*stack)->next;
	top2->n = top2->n % top1->n;
	*stack = top2;
	free(top1);
}
