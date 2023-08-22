#include "shell.h"

/**
 * _addEnvNodeEnd - add a new node
 *
 * @prmHeadNode: first node
 * @prmGlobal: global environment value
 *
 * Return: last element
 */
environment_t *_addEnvNodeEnd(
    environment_t **prmHeadNode,
    char *prmGlobal
) {
    if (prmHeadNode == NULL) {
        return NULL;
    }

    environment_t *new = _createEnvNode(prmGlobal);
    if (new == NULL) {
        return NULL;
    }

    environment_t *last = NULL;
    
    if (*prmHeadNode != NULL) {
        last = _getLastEnvNode(*prmHeadNode);
        if (last == NULL) {
            free(new);
            return NULL;
        }
        last->next = new;
    } else {
        *prmHeadNode = new;
    }

    return new;
}

