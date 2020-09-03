#include "list.h"


/**
 * add_node_end - add new node to end of double circular linked list
 *
 * @list: A double pointer to the end of the linkd list
 * @str: string to copy into new node
 *
 * Return: Address of new node or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *l_node, *n_node;

	if (!list)
		return (NULL);
	if (!str)
		return (NULL);

	n_node = malloc(sizeof(List));
	if (!n_node)
		return (NULL);
	n_node->str = strdup(str);
	if (!n_node->str)
	{
		free(n_node);
		return (NULL);
	}
	if (*list == NULL)
	{
		n_node->next = n_node->prev = n_node;
		*list = n_node;

		return (n_node);
	}
	else
	{
		/*list pointing to previous */
		l_node = (*list)->prev;
		l_node->next = n_node;
		n_node->next = *list;
		n_node->prev = l_node;
		(*list)->prev = n_node;

		return (n_node);
	}
	/*return (n_node);*/
}


/**
 * add_node_begin - add new node to beginning of double circular linked list
 *
 * @list: A double pointer to the head of the linkd list
 * @str: string to copy into new node
 *
 * Return: Address of new node or NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *l_node, *n_node;

	if (!list)
		return (NULL);
	if (!str)
		return (NULL);

	n_node = malloc(sizeof(List));
	if (!n_node)
		return (NULL);
	n_node->str = strdup(str);
	if (!n_node->str)
	{
		free(n_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		n_node->next = n_node->prev = n_node;
		*list = n_node;

		return (n_node);
	}
	else
	{
		/*list pointing to previous */
		l_node = (*list)->prev;
		/* l_node->next = l_node; */
		n_node->next = (*list);
		n_node->prev = l_node;
		(*list)->prev = l_node->next;
		l_node->next = n_node;
		*list = n_node;

		return (n_node);
	}
	/*return (n_node);*/
}
