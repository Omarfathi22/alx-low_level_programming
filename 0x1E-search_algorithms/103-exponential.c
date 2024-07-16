#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the binary search algorithm
 *
 * @array: A pointer to the first element of the array to search in
 * @left: The starting index of the subarray to search in
 * @right: The ending index of the subarray to search in
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if the value is not found
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
    size_t mid, i;

    if (!array)
        return (-1);

    while (left <= right)
    {
        printf("Searching in array: ");
        for (i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        mid = left + (right - left) / 2;
        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 *
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where the value is located, or -1 if the value is not found
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t left, right;

    if (!array)
        return (-1);

    if (array[0] == value)
        return (0);

    while (bound < size && array[bound] <= value)
    {
        printf("Value checked array[%ld] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    left = bound / 2;
    right = (bound < size) ? bound - 1 : size - 1;
    printf("Value found between indexes [%ld] and [%ld]\n", left, right);

    return binary_search(array, left, right, value);
}
