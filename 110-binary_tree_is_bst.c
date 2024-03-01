#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root of the node to check
 *
 * Return: 1 if valid BST, 0 if not or if root is NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *prev = NULL;

	return (is_bst_util(tree, &prev));
}

/**
 * is_bst_util - Helper function to check if binary tree is a valid BST
 *
 * @tree: Pointer to the root node of the tree
 * @prev: Pointer to the previously visited node
 *
 * Return: 1 if tree is BST, otherwise 0
 */

int is_bst_util(const binary_tree_t *tree, const binary_tree_t **prev)
{
	if (!tree)
		return (1);

	if (!is_bst_util(tree->left, prev))
		return (0);

	if (*prev != NULL && tree->n <= (*prev)->n)
		return (0);

	*prev = tree;

	return (is_bst_util(tree->right, prev));
}
