#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *to_delete;
    unsigned int p = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    to_delete = *head;

    while (p < index && to_delete != NULL)
    {
        to_delete = to_delete->next;
        p++;
    }

    if (to_delete == NULL)
        return (-1);

    if (index == 0)
    {
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        (*head) = to_delete;
        (*head)->prev->next = (*head)->next;
        if ((*head)->next != NULL)
            (*head)->next->prev = (*head)->prev;
    }

    return (1);
}
