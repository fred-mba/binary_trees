#include "binary_trees.h"
/**
 * tree_is_bst - Helper function to check if a subtree is a valid BST
 * @node: pointer to root node
 * @prev_value: smalest value than any node value in the tree
 * Return: 1 for an empty subtree, 0 if value and subtree exists
*/
int tree_is_bst(const binary_tree_t *node, int *prev_value)
{
	if (node == NULL)
		return (1); /*BST is valid if a single node exists*/

	/*Check the left subtree*/
	if (!tree_is_bst(node->left, prev_value))
	{
		return (0);
	}

	/*Check the current node's value*/
	if (*prev_value >= node->n)
	{
		return (0);
	}

	/*Update the previous value to the current node's value*/
	*prev_value = node->n;

	/*Check the right subtree*/
	return (tree_is_bst(node->right, prev_value));
}

/**
 * binary_tree_is_bst -  checks if a binary tree is a valid
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 1 if tree is a valid BST, and 0 otherwise
 *		If tree is NULL, return 0
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev_value;

	if (tree == NULL)
		return (0);

	prev_value = -1; /*Initializing with smallest value*/

	return (tree_is_bst(tree, &prev_value));
}
