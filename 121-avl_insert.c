#include "binary_trees.h"

/**
 * avl_insert - A function that inserts a value in an AVL tree
 *
 * @tree: Double pointer to the root node of the AVL tree for inserting value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, otherwise NULL on failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	int balance = 0;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
		(*tree)->left = avl_insert(&((*tree)->left), value);
	else if (value > (*tree)->n)
		(*tree)->right = avl_insert(&((*tree)->right), value);
	else
		return (*tree);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));
	if (balance < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));

	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left(*tree);
		return (binary_tree_rotate_right(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right(*tree);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}
