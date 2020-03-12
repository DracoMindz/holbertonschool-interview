#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * is_palindrome - singly linked list
 * @head: address of pointer
 *
 * Return: 1 if palindrome, 0 i f not palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *temp = *head;

	return (got_pali(*head, &temp));

}
/**
 * got_pali - reverse checks if is palindrome
 * @head: address of pointer
 * @nnode: half to compare
 * Return: 1 if palindrome, 0 i f not palindrome
 */
int got_pali(listint_t *nnode, listint_t **head)
{
	int paliResult = 1;

	if (!nnode)
		return (1);
	paliResult = got_pali(nnode->next, head);
	if (paliResult == 0)
		return (1);

	if
		((nnode->n == (*head)->n) && (*head = (*head)->next))
		return (1);
	return (0);
}
