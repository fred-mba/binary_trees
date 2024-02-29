#include "binary_trees.h"

/**
 * binary_tree_node - pointer to the whole binary tree
 * @parent: pointer to the parrent node
 * @value: the value to put in the new node
 * Description: creates a binary tree node
 *
 * Return: pointer to the new node, or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL) /*fails to allocate memory*/
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
