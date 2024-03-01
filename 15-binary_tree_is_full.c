#include "binary_trees.h"
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
