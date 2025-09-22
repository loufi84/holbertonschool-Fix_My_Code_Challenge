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
    unsigned int p = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    while (*head != NULL && p < index)
    {
        *head = (*head)->next;
        p++;
    }

    if (*head == NULL)
        return (-1);

    if (p == 0)
    {
        dlistint_t *to_delete = *head;
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(to_delete);
    }
    else
    {
        dlistint_t *to_delete = *head;
        (*head)->prev->next = (*head)->next;
        if ((*head)->next != NULL)
            (*head)->next->prev = (*head)->prev;
        free(to_delete);
    }

    return (1);
}
