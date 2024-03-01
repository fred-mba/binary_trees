#include "binary_trees.h"

/**
 * sorted_array_to_avl - Sorts array to avl tree
 *
 * @array: Pointer to the first element in the array
 * @size: Size of the array
 *
 * Return: AVL tree from sorted array
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return sorted_array_to_avl_helper(array, 0, size - 1);
}

/**
 * sorted_array_to_avl_helper - Helper function to convert sorted to avl
 *
 * @array: Pointer to the first element in the array
 * @start: The start index of the array
 * @end: The end index of the array
 *
 * Return: The Root of the built avl tree
 */

avl_t *sorted_array_to_avl_helper(int *array, size_t start, size_t end)
{
	size_t mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(NULL, array[mid]);

	if (!root)
		return (NULL);

	root->left = sorted_array_to_avl_helper(array, start, mid - 1);
	root->right = sorted_array_to_avl_helper(array, mid + 1, end);

	return (root);
}
