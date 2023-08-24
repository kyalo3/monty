#include "monty.h"

/**
 * handle_pint - Prints the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void handle_pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        dprintf(2, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
