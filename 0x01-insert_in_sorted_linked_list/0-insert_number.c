#include "lists.h"
/**
 * insert_node - inserts numberinto a node
 * @head: head of linked list
 * @number: item to be inserted
 * Return: NUll or address of new node
 */
listint_t *insert_node(listint_t **head, int number)
{
  listint_t *temp = *head, *new;

  new = malloc(sizeof(listint_t));
  if (new == NULL)
    return (NULL);
  new->n = number;
  if (*head == NULL)
    {
      new->next = *head;
      *head = new;
      return (new);
    }
  else if (*head && (*head)->n > number)
    {
      new->next = *head;
      *head = new;
      return (new);
    }
  else
    {
      if (temp->next && temp->next->n < number)
	{
	  temp = temp->next;
	}
      new->next = temp->next;
      temp->next = new;
      return (new);
    }
}
