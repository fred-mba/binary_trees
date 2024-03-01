#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if AVL, 0 if not or root is NULL
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	if (binary_balance(tree) >= -1 && binary_balance(tree) <= 1)
		return (1);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: 0 if tree is NULL, otherwise balance factor
 */

int binary_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
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

	left_subtree = tree->left ? 1 + binary_tree_height(tree->left) : 1;

	right_subtree = tree->right ? 1 + binary_tree_height(tree->right) : 1;

	return ((left_subtree > right_subtree) ? left_subtree : right_subtree);
}

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
