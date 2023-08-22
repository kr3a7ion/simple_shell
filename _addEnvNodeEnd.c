#include "shell.h"

/**
 * addEnvNodeEnd - Add a new node to the end of the linked list.
 *
 * @head: Pointer to the head node.
 * @global: Global environment value.
 *
 * Return: Pointer to the newly added node.
 */
environment_t *addEnvNodeEnd(environment_t **head, char *global) {
    if (head == NULL)
        return NULL;

    environment_t *newNode = createEnvNode(global);
    if (newNode == NULL)
        return NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        environment_t *lastNode = getLastEnvNode(*head);
        if (lastNode == NULL) {
            free(newNode);
            return NULL;
        }
        lastNode->next = newNode;
    }

    return newNode;
}

