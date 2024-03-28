#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst - Helper function to check if a binary tree is a valid BST
 *
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value the nodes in the tree can take
 * @max: Maximum value the nodes in the tree can take
 *
 * Return: 1 or 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left = is_bst(tree->left, min, tree->n);
	right = is_bst(tree->right, tree->n, max);

	return (left && right);
}
