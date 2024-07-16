#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using jump search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where value is located, or -1 if not found or NULL
 */
int jump_search(int *array, size_t size, int value)
{
    size_t jump;
    size_t prev;
    size_t start;
    size_t end;
    size_t i;

    jump = sqrt(size);
    prev = 0;

    if (array == NULL || size == 0)
        return (-1);

    while (prev < size && array[prev] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", (unsigned long)prev, array[prev]);
        prev += jump;
    }

    start = prev - jump;
    end = (prev < size) ? prev : size;

    printf("Value found between indexes [%lu] and [%lu]\n", (unsigned long)start, (unsigned long)(end - 1));

    for (i = start; i < end; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", (unsigned long)i, array[i]);
        if (array[i] == value)
            return (i);
    }

    return (-1);
}
