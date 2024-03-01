#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if the binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 if NULL or not complete
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_complete(tree, 0, binary_tree_size(tree)));
}

/**
 * is_complete - A helper function to help check for a complete tree
 *
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @size: Number of nodes in the tree
 *
 * Return: 1 if complete, 0 if not or root is NULL
 */


int is_complete(const binary_tree_t *tree, int index, int size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
			is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure it's depth
 *
 * Return: If NULL, return 0, otherwise the size of tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	count = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);

	return (count);
}
