#include "search_algos.h"
#include <math.h>
#include <stdio.h>

/**
 * jump_list - Searches for a value in a sorted singly linked list using jump search
 * @list: Pointer to the head of the list
 * @size: The number of nodes in the list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, prev_index;
	listint_t *prev, *curr;

	if (list == NULL || size == 0)
		return (NULL);

	step = sqrt(size);
	prev = list;
	curr = list;

	while (curr->next != NULL && curr->index < step)
		curr = curr->next;

	while (curr->index < size && curr->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		prev = curr;
		prev_index = curr->index;
		for (; curr->index < prev_index + step && curr->next != NULL; curr = curr->next)
			;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev->index, curr->index);

	while (prev != NULL && prev->index <= curr->index && prev->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		prev = prev->next;
	}

	if (prev != NULL && prev->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		return (prev);
	}

	return (NULL);
}
