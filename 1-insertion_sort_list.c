#include "sort.h"
/**
 * switch_nodes-swaps two nodes
 * @list: doubly linked list
 * @node1: first node to be swapped
 * @node2: second node to be swapped
 */
void switch_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1 = NULL, *next2 = NULL;

	if (node1 == NULL || node2 == NULL)
	{
		return;
	}
	prev1 = node1->prev;
	next2 = node2->next;

	if (prev1 != NULL)/*checks if node 1 is the head node*/
		prev1->next = node2;
	if (next2 != NULL)/*checks if node 2 is the head node*/
		next2->prev = node1;

	node1->next = next2;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = prev1;

	if (prev1 == NULL)
		*list = node2;
}
/**
 * insertion_sort_list-function that sorts
 * a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{

	/*listint_t *sorted = NULL;*//*sorted list*/
	listint_t *present = *list;/*present node being inserted*/ 
	listint_t *prev = NULL;/*previous node to be inserted*/
	/*listint_t *temp = NULL;*//*temporary node*/

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (present != NULL)
	{
		prev = present->prev;
		while (prev && prev->n > present->n)
		{
			switch_nodes(list, prev, present);
			print_list(*list);
			prev = present->prev;
		}
		present = present->next;
	}
}
