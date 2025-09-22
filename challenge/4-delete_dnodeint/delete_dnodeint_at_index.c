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

    if (!head || !*head)
        return (-1);

    to_delete = *head;
    while (p < index && to_delete)
    {
        to_delete = to_delete->next;
        p++;
    }

    if (!to_delete)
        return (-1);

    if (index == 0)
    {
        *head = to_delete->next;
        if (*head)
            (*head)->prev = NULL;
    }
    else
    {
        to_delete->prev->next = to_delete->next;
        if (to_delete->next)
            to_delete->next->prev = to_delete->prev;
    }

    free(to_delete);
    return (1);
}
