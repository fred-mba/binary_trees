#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Lowest ancestor of the two, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	while (first)
	{
		temp = second;

		while (temp)
		{
			if (first == temp)
				return ((binary_tree_t *)first);

			temp = temp->parent;
		}

		first = first->parent;
	}

	return (NULL);
}
