#include "binary_trees.h"
/**
 * binary_tree_levelorder - Travels the binary tree using level order traversal
 * @tree: Pointer to the root node of tree to traverse
 * @func: Pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int tree_height, level;

	if (!tree || !func)
		return;

	tree_height = binary_tree_height(tree);

	for (level = 0; level <= tree_height; level++)
	{
		traverse_level(tree, level, func);
	}
}

/**
 * traverse_level - Helper function to traverse a specific level of the tree
 * @node: Pointer to the current node
 * @level: Current height or level of tree to traverse
 * @func: Pointer to the function to call for each node
 */

void traverse_level(const binary_tree_t *node, int level, void (*func)(int))
{
	if (!node)
		return;

	if (level == 0)
		func(node->n);

	traverse_level(node->left, level - 1, func);
	traverse_level(node->right, level - 1, func);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure it's height
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
