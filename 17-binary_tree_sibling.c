#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: If node is NULL or the parent is NULL, return NULL
 *			If node has no sibling, return NULL
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent_node = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent_node = node->parent;

	/*if left & right child belong to the parent(*node)*/
	if (parent_node->left == node)
		return (parent_node->right);

	else
		return (parent_node->left);
}
