/**
 * _createEnvNode - create a new node for an environment variable linked list
 *
 * @prmGlobal: global environment value
 *
 * Return: new element
 */
environment_t *_createEnvNode(char *prmGlobal)
{
    if (prmGlobal == NULL) {
        return NULL;
    }

    environment_t *newNode = malloc(sizeof(environment_t));
    if (newNode == NULL) {
        return NULL;
    }

    newNode->name = _getenvname(prmGlobal);
    newNode->value = _getenvvalue(prmGlobal);
    newNode->global = _strdup(prmGlobal);
    newNode->next = NULL;

    return newNode;
}

