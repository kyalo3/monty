#include "monty.h"

void handle_pop(stack_t **head, unsigned int line_number)
{
    stack_t *temp;

    (void)line_number;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *head;
    *head = (*head)->next;
    free(temp);
}
