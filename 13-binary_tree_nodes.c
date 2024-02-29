#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the nodes with at least
 *                    1 child in a binary tree
 * @tree: pointer to the root node of the tree to count
 *       the number of nodes
 * Return: 0 if tree is NULL
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_left;
	size_t nodes_right;

	if (tree == NULL)
	{
		return (0);
	}

	nodes_left = binary_tree_nodes(tree->left);
	nodes_right = binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
	{
		nodes_left = binary_tree_nodes(tree->left);
		nodes_right = binary_tree_nodes(tree->right);

		return ((nodes_left + nodes_right) + 1);
		/*+1 if current node has one child*/
	}
	return (0); /*current node has no leaf*/
}
