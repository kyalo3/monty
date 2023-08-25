#include "monty.h"

/**
 * free_all - Frees the memory associated with the stack nodes
 */
void free_all(void)
{
	stack_t *current = *stack;
	stack_t *next;

	if (stack == NULL || *stack == NULL)
		return;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
	free(*stack);
	free(stack);
}
