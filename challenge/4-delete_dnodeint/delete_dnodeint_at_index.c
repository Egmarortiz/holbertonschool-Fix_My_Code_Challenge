#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *node;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    node = *head;
    for (i = 0; node != NULL && i < index; i++)
        node = node->next;

    if (node == NULL)
        return (-1);

    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        *head = node->next;

    if (node->next != NULL)
        node->next->prev = node->prev;

    free(node);

    return (1);
}
