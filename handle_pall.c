#include "monty.h"

void handle_pall(stack_t **head, unsigned int line_number)
{
    stack_t *current;

    (void)line_number;
    current = *head;
    while (current != NULL)
    {
        dprintf(1, "%d\n", current->n);
        current = current->next;
    }
}
