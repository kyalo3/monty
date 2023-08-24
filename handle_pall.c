#include "monty.h"

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
