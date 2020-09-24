#include "binary_trees.h"


/**
 * bt_height - measures heigh of binary search tree
 *
 *@tree: tree to be measured
 *@height: height of tree
 * Return: height of tree
 */
int bt_height(binary_tree_t const *tree, int height)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (height);
	if (tree->left)
		left += bt_height(tree->left, height) + 1;
	if (tree->right)
		right += bt_height(tree->right, height) + 1;
	/* difference between heights cannot be more than one */
	if (left - right > 1)
		return (-1);
	if (left - right < -1)
		return (-1);
	return (left > right ? left : right);
}

/**
 * tree_is_bst - measures heigh of binary search tree
 *
 * @tree: tree to be measured
 * @num: value
 * Return: height of tree
 */
size_t tree_is_bst(binary_tree_t const *tree, int *num)
{
	int minbin = INT_MIN;


	if (num == NULL)  /* num in minimum */
		num = &minbin;
	if (tree == NULL)
		return (1);
	if (!tree_is_bst(tree->left, num))
		return (0); /* return 0 if nothing to the left */
	if (tree->n <= *num)  /* if less than num at *num */
		return (0);
	*num = tree->n;
	/* return value on the right side */
	return (tree_is_bst(tree->right, num));
}


/**
 * binary_tree_is_avl - checks if a bunary tree is valid
 *
 * @tree: Pointer to the node to print
 *
 * Return: 1 if valid, 0 if not valid
 */
int binary_tree_is_avl(binary_tree_t const *tree)
{
	/* check NULL cases */
	if (tree == NULL)
		return (0);
	if (!tree_is_bst(tree, NULL))
		return (0);
	if (bt_height(tree, 0) < 0)
		return (0);
	return (1);
}
