#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through a binary tree
 *		using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: If tree or func is NULL, do nothing
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;

	/*Calcute the height of the tree*/
	height = binary_tree_height(tree);

	for (level = 1; level <= height + 1; level++)
	{
		traversal_level(tree, func, level);
	}

}

/**
 * traversal_level - helper function for level-order traversal
 * @tree: pointer to the current node
 * @func: pointer for the function to call each node
 * @level: current level in the traversal
*/
void traversal_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 1)
	{
		func(tree->n); /*call the function in the current node*/
	}
	else if (level > 1)
	{
		/*Recursively call the function on the left/right at the next level*/
		traversal_level(tree->left, func, level - 1);
		traversal_level(tree->right, func, level - 1);
	}
}
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
