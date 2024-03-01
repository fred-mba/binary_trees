#include "binary_trees.h"

/**
 * bst_remove - Removes a node from the binary search tree
 *
 * @root: Pointer to the root node of the tree where you'll remove the node
 * @val: Value to remove from the tree
 *
 * Return: Pointer to new root node after removing the desired value
 */

bst_t *bst_remove(bst_t *root, int val)
{
	bst_t *temp;

	if (!root)
		return (NULL);

	if (val < root->n)
		root->left = bst_remove(root->left, val);
	else if (val > root->n)
		root->right = bst_remove(root->right, val);
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = bst_find_successor(root->right);

		root->n = temp->n;

		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}

/**
 * bst_find_successor - Finds the in-order successor of a node
 *
 * @node: Pointer to the node for which to find the successor
 *
 * Return: Pointer to the in-order successor node
 */

bst_t *bst_find_successor(bst_t *node)
{
	while (node && node->left)
		node = node->left;

	return (node);
}
