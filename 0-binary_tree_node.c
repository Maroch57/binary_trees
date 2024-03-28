#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Create new binary tree node
 * @parent: Pointer to the parent node of the new node
 * @value: Value to put in the new node
 * Return: Pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	/* allocate memory to the root node */
	newnode = malloc(sizeof(binary_tree_t));

	if (newnode == NULL)
		return (NULL);

	/* node with value but no children */
	newnode->parent = parent;
	newnode->n = value;
	newnode->left = NULL;
	newnode->right = NULL;

	return (newnode);
}
