#include "monty.h"
/**
 * handle_push - adds n element to the top of the stack
 * @head: pointer to the head of a stack
 * @number: value to be pushed
 */
void handle_push(stack_t **head, int number)
{
    stack_t *new_node;

    new_node = (stack_t *)malloc(sizeof(stack_t));
    if (!new_node)
    {
        dprintf(2, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = number;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        new_node->next = NULL;
        *head = new_node;
    }
    else
    {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}