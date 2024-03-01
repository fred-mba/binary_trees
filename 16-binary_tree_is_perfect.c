#include "binary_trees.h"
/**
 * binary_tree_is_perfect - Checks if binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 0 if tree is NULL, otherwise 1 if full and 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		if (!tree->left && !tree->right)
			return (1);

		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}


/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure it's height
 *
 * Return: If NULL, return 0, otherwise the height of tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_subtree = 0;
	size_t right_subtree = 0;

	if (!tree)
		return (0);

	left_subtree = tree->left ? 1 + binary_tree_height(tree->left) : 0;

	right_subtree = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((left_subtree > right_subtree) ? left_subtree : right_subtree);
}
