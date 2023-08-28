#include "monty.h"

/**
 * free_all - Frees the memory associated with the stack nodes
<<<<<<< HEAD
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
=======
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
>>>>>>> main
}
