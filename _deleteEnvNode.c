/**
 * _deleteEnvNode - delete an environment variable node
 *
 * @prmHead: first node
 * @prmName: name
 *
 * Return: error code (1 for success, -1 for failure)
 */
int _deleteEnvNode(environment_t *prmHead, char *prmName)
{
    environment_t *beforeNode, *afterNode, *currentNode, *firstNode;
    unsigned int length, currentIndex;

    firstNode = prmHead;
    currentIndex = _getEnvIndex(prmHead, prmName);

    if (firstNode == NULL) return -1;
    
    length = _listEnvLen(firstNode);

    if (length == 0 || currentIndex >= length) return -1;

    if (currentIndex == 0) {
        prmHead = prmHead->next;
        free(firstNode);
        return 1;
    }

    beforeNode = _getEnvNodeAtIndex(firstNode, currentIndex - 1);
    afterNode = (currentIndex == length - 1) ? NULL : _getEnvNodeAtIndex(firstNode, currentIndex + 1);
    currentNode = _getEnvNodeAtIndex(firstNode, currentIndex);

    beforeNode->next = afterNode;
    
    // Clean up memory
    free(currentNode->name);
    free(currentNode->value);
    free(currentNode->global);
    free(currentNode);

    return 1;
}

