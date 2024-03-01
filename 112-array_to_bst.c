#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, otherwise NULL
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{
			binary_delete(root);
			return (NULL);
		}
	}

	return (root);
}

/**
 * binary_delete - Deletes an entire binary tree
 *
 * @tree: Pointer to the root of the tree to Delete
 */

void binary_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_delete(tree->left);
	binary_delete(tree->right);

	free(tree);
}
