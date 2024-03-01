#include "binary_trees.h"
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete(tree, 0, binary_tree_size(tree)));
}

/**
 * is_complete - check for a complete tree
 * @tree: Pointer to the root node of the tree to check
 * @level: Index of the current node
 * @size: Number of nodes in the tree
 *
 * Return: 1 if complete, 0 if not or root is NULL
 */


int is_complete(const binary_tree_t *tree, int level, int size)
{
	if (!tree)
		return (1);

	if (level >= size)
		return (0);

	return (is_complete(tree->left, 2 * level + 1, size) &&
			is_complete(tree->right, 2 * level + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: If tree is NULL, the function must return 0
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size;
	size_t right_size;

	if (tree == NULL)
	{
		return (0);
	}

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
	/*+1 is addition for the current node*/
}
