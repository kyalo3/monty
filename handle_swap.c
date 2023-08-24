#include "monty.h"

/**
 * handle_swap - swaps the top two elements of the stack
 * @head: double pointer to the head of the stack
 * @line_number: line number of the instruction in the file
 */
void handle_swap(stack_t **head, unsigned int line_number)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        dprintf(2, "L%d: can't swap, stack too short\n", line_number);
        free_all(*head);
        exit(EXIT_FAILURE);
    }

    int temp = (*head)->n;
    (*head)->n = (*head)->next->n;
    (*head)->next->n = temp;
}
