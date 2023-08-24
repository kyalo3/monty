#include "monty.h"

void handle_pall(stack_t **head, int number)
{
    /*(void)number;*/
    stack_t *current = *head;

    (void)number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
