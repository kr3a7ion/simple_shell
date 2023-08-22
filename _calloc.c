/**
 * _calloc - allocates memory for an array
 *
 * @prmNumber: number of elements
 * @prmSize: size of each element
 *
 * Return: pointer to allocated and initialized memory, or NULL on failure
 */
void *_calloc(unsigned int prmNumber, unsigned int prmSize)
{
    void *ptr = NULL;

    if (prmNumber != 0 && prmSize != 0) {
        ptr = malloc(prmSize * prmNumber);
        if (ptr != NULL) {
            ptr = _memset(ptr, 0, prmNumber * prmSize);
        }
    }

    return ptr;
}

