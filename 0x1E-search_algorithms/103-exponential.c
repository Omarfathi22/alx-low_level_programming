#include <stdio.h>
#include "search_algos.h"

int binary_search(int *array, size_t low, size_t high, int value);

/**
 * exponential_search - Searches for a value in a sorted array using
 *                      exponential search algorithm.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if not found or NULL.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t low, high;

    if (array == NULL || size == 0)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    low = bound / 2;
    high = (bound < size) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", low, high);

    return (binary_search(array, low, high, value));
}

/**
 * binary_search - Searches for a value in a sorted array using
 *                 binary search algorithm.
 * @array: Pointer to the first element of the array.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if not found.
 */
int binary_search(int *array, size_t low, size_t high, int value)
{
    size_t mid;
    size_t i;

    while (low <= high)
    {
        printf("Searching in array: ");
        for (i = low; i <= high; i++)
        {
            printf("%d", array[i]);
            if (i < high)
                printf(", ");
        }
        printf("\n");

        mid = low + (high - low) / 2;
        if (array[mid] == value)
            return (mid);
        if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return (-1);
}