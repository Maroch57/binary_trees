#include "binary_trees.h"

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 * If the address stored in root= NULL, the created node must become root node
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	/*
	 * Traverse tree to first empty slot based on binary
	 * representation of number of leaves.
	 * Example -
	 * If there are 12 nodes in a complete tree, there are 5 leaves on
	 * 4th tier of tree. 5; 101 in binary. 1 corresponds to
	 * right, 0 to left.
	 * first empty node is 101 == RLR, *root->right->left->right
	 */

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - measures size of a binary tree
 * @tree: tree to measure size of
 *
 * Return: size of tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
