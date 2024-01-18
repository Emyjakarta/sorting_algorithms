#include "sort.h"
/**
 * insertion_sort_list-function that sorts
 * a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *sorted = NULL;
	listint_t *new = *list;
	listint_t *next = NULL;
	listint_t *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (new != NULL)
	{
		next = new->next;
		if (sorted == NULL || sorted->n >= new->n)
		{
			new->next = sorted;
			new->prev = NULL;
			if (sorted != NULL)
			{
				sorted->prev = new;
			}
			sorted = new;
			print_list(*list);
		}
		else
		{
			temp = sorted;
			while (temp->next != NULL && temp->next->n < new->n)
			{
				temp = temp->next;
			}
			new->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = new;
			temp->next = new;
			new->prev = temp;
			print_list(*list);
		}
		new = next;
	}
	*list = sorted;
}
