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
	int palin;

	palin = got_pali(head, *head);
	return (palin);
}

/**
 * got_pali - checks if is palindrome
 * @left: address of pointer
 * @right: half to compare
 * Return: 1 if palindrome, 0 i f not palindrome
 */
int got_pali(listint_t **left, listint_t *right)
{
	int ispal, ispalList;

	if (right == NULL)
		return (1);
	ispal = got_pali(left, right->next);
	if (ispal == 0)
		return (0);
	if (right->n == (*left)->n)
		ispalList = 1;
	else
		ispalList = 0;
	*left = (*left)->next;
	return (ispalList);
}
