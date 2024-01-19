#include "sort.h"
/**
 * switch_nodes-swaps two nodes
 * @list: doubly linked list
 * @node1: first node to be swapped
 * @node2: second node to be swapped
 */
void switch_nodes(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;

}
/**
 * insertion_sort_list-function that sorts
 * a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i = NULL, *new = NULL, *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		new = i->prev;
		while (new != NULL && i->n < new->n)
		{
			switch_nodes(list, &new, i);
			print_list(*list);
		}
	}
}
