#include "monty.h"

/**
 * free_all - Frees the memory associated with the stack nodes
 * @head: Double pointer to the head of the stack
 */
void free_all(stack_t **head)
{
	stack_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
