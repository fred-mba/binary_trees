#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary tree search
 *
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 *
 * Return: Pointer to the node containing value == value,
 *			if tree is NULL or nothing is found, NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else if (value > tree->n)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}
