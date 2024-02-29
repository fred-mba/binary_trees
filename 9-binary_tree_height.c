#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: If tree is NULL, function must return 0
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_H;
	size_t right_H;

	if (tree == NULL)
	{
		return (0);
	}

	left_H = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_H = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_H > right_H ? left_H : right_H);

}
