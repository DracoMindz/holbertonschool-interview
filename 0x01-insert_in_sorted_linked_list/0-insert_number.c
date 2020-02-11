#!/bin/bash
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"


/**
 * insert_node - inserts numberinto a node
 * @head- headof linked list
 * @number - item to be inserted
 * Return: Always 0.
 */
listint_t *insert_node(listint_t **head, int number)
{
  listint_t *temp= *head, *new;

  newNode = malloc(sizeof(listint_t));
  new->n = number;
  if (newNode == NULL)
    {
      return (NULL);
    }
  if (*head == NULL)
    {
      newNode->next = *head;
      *head = newNode;
      return (newNode)
    }
  else if (*head && (*head)->n > number)
    {
      newNode->next = *head;
      *head = newNode;
      return (newNode);
    }
  else
    {
      if (temp->next->n && temp->next < number)
	{
	  temp = temp->next;
	}
      newNode->next = temp->next;
      temp->next = newNode;
      return (newNode);
    }
}
      
  
