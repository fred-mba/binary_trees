#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (tree == NULL)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	if (height_left == height_right)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);

		return (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right));
	}
	return (0);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, the function must return 0
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int check_left, check_right;

	if (tree == NULL)
		return (0);

	/*If currrent node is a leaf, both children are NULL, return 1*/
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively check if the left and right subtrees are full */
	check_left = binary_tree_is_full(tree->left);
	check_right = binary_tree_is_full(tree->right);

	return (check_left && check_right);
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
