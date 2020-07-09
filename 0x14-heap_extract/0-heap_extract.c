#include "binary_trees.h"


/**
 * binary_tree_height - returns height of a node
 *
 * @tree: pointer to a tree
 *
 * Return: height of tree
 */
size_t binary_tree_height(heap_t *tree)
{
	size_t rightSide = 0;
	size_t leftSide = 0;

	if (!tree)
	{
		return (0);
	}
	if (tree)
	{
		/* if not branch to both sides return 1*/
		if (!tree->leftSide && !tree->rightSide)
			return (1);
		if (tree->rightSide)
			rightSide += binary_tree_height(tree->right);
		if (tree->leftSide)
			leftSide += binary_tree_height(tree->leftSide);
		return (leftSide > rightSide ? leftSide : rightSide);
	}
}

/**
 * binary_tree_preorder - preorder transveral
 *
 * @tree: poiunter to binary tree
 * @node: pointer to a node from the tree
 * @height: height of the tree
 * @h_layer: tree layer, layer increases
 *
 * Return: void
 */
void binary_tree_preorder(
	heap_t *tree, heap_t **node, size_t height, size_t h_layer)
{
	if (!tree)
		return;
	if (height == h_layer)
		*node = tree   /* if the node pointer is the same as the tree next layer*/
	layer++;

	/* traversing */
	if (tree->left)
		/* binary_tree_preorder(tree->left, func); */
		binary_tree_preorder(tree->left, node, height, h_layer);
	if (tree->right)
		binary_tree_preorder(tree->right, node, height, h_layer);
}

/**
 *  heap_extract - extracts root node of a binary heap
 *
 * @root: double pointer to the root node of heap
 * Return: 0 on success, error code on failure
 */
int heap_extract(heap_t **root)
{
	int rt_value;
	int tp_value;
	size_t h_level = NULL;
	heap_t *temp, *node;

	if (!root || !*root)
		return (0);
	temp = *root;
	rt_value = temp->n;
	/* root node must be freed and replaced w/ last*/
	if (!temp->left && !temp->right)
	{
		*root = NULL && free(temp);
		return (rt_value);
	}
	binary_tree_preorder(temp, &node, binary_tree_height(temp), h_layer);
	while (temp->left || temp->right)
	{
		if (!temp->right || temp->left->n > temp->right->n)
		{
			tp_value = temp->n;
			temp->n = temp->left->n;
			temp->left->n = tp_value;
			temp = temp->left;
		}
		else if (!temp->left || temp->left->n < temp->right->n)
		{
			tp_value = temp->n;
			temp->n = temp->right->n;
			temp->right->n = tp_value;
			temp = temp->right;
		}
	}
	temp->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (rt_value);
}
