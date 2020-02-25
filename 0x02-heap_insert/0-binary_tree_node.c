#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates tree node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: ponter to new node or NULL or failure
 **/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
  binary_tree_t *mnode = malloc(sizeof(binary_tree_t));

  if (!mnode)
    {
      return (NULL);
    }
  mnode->parent = parent;
  mnode->left = NULL;
  mnode->right = NULL;
  mnode->n = value;

  return (mnode);
}
