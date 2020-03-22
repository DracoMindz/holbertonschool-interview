#include<stdio.h>
#include"lists.h"
/**
 * check_cycle - detect cyle in singly linked list
 * @list: singlt linked list to check
 *
 * Description: detect singly linked list
 * Return: 0 if cycle, 1 if not cycle
 */
int check_cycle(listint_t *list)
{
	/* create two pointers to traverse list */
	listint_t *ptr_coyote; /* slow pointer */
	listint_t *ptr_rrunner; /* fast pointer */

	ptr_coyote = list;
	ptr_rrunner = list;

	while (ptr_coyote != NULL && ptr_rrunner != NULL && ptr_rrunner->next != NULL)
	/* while pointer are not pointing to NULL */
	{
		ptr_coyote = ptr_coyote->next; /* pointer to first node */
		ptr_rrunner = ptr_rrunner->next->next; /* pointer to second node */
		if (ptr_coyote == ptr_rrunner) /* are pointers pointing to the same thing */
		{
			return (1); /* found a loop */
		}
	}
	return (0); /* no loop found */
}
