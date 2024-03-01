#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a binary search tree
 *
 * @tree: Double pointer to the root node of the BST to insert value
 * @value: The value to store in the node being created
 *
 * Return: Pointer to the created node, otherwise NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
			return (bst_insert(&((*tree)->left), value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node((*tree)->right, value);
			return ((*tree)->right);
		}
		else
			return (bst_insert(&((*tree)->right), value));
	}

	return (NULL);
}
