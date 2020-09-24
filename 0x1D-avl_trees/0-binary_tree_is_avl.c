#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * tree_is_bst - measures heigh of binary search tree
 *
 * @tree: tree to be measured
 * @num: value
 * Return: height of tree
 */
int tree_is_bst(const binary_tree_t *tree, int *num)
{
	int minbin = INT_MIN;

	if (tree == NULL)
		return (1);
	if (num == NULL)  /* num in minimum */
		num = &minbin;
	if (!tree_is_bst(tree->left, num))
		return (0); /* return 0 if nothing to the left */
	if (tree->n <= *num)  /* if less than num at *num */
		return (0);
	*num = tree->n;
	/* return value on the right side */
	return (tree_is_bst(tree->right, num));


}

/**
 * bt_height - measures heigh of binary search tree
 *
 *@tree: tree to be measured
 * Return: height of tree
 */
int bt_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (1);
	if (tree)
	{
		if (tree->left)
			left += bt_height(tree->left) + 1;
		if (tree->right)
			right += bt_height(tree->right) + 1;
	}
	return (left > right ? left : right);
}


/**
 * binary_tree_is_avi - checks if a bunary tree is valid
 *
 * @tree: Pointer to the node to print
 *
 * Return: 1 if valid, 0 if not valid
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	/* check NULL cases */
	if (tree == NULL)
		return (0);
	if (tree_is_bst(tree, NULL))
		return (0);
	if (bt_height(tree, 0) < 0)
		return (0);
	return (1);
}
