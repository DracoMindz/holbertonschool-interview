# 0x1A. Double Circular Linked List
Specializations - Interview Preparation ― Algorithms

Data structure for this project:

```
/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
  char *str;
  struct List *prev;
  struct List *next;
} List;
```
### Tasks
___
**0.Add Nodes**

Create the source file 0-add_node.c that contains funtions:
```
Add a new node to the end of a double circular linked list.

Add a new node to the beginning of a double circular linked list.
```
Note: Given Print_List function to print information oabout each element of a list.
```
print_ list
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * print_list - Print informations about each element of a list
 *
 * @list: A pointer to the head of the linkd list
 *
 * Return: void
 */
void print_list(List *list)
{
    List *tmp;

    tmp = list;
    while (tmp)
    {
        printf("%s\n", tmp->str);
        printf("\t->prev: %s\n", tmp->prev ? tmp->prev->str : "NULL");
        printf("\t->next: %s\n", tmp->next ? tmp->next->str : "NULL");
        tmp = tmp->next;
        if (tmp == list)
            break;
    }
}
```
