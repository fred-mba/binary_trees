#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common
 *						ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: If no common ancestor was found,
 *			the function must return NULL
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	const binary_tree_t *ancestor = NULL;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}
	while (first)
	{
		ancestor = second;

		while (ancestor)
		{
			if (first == ancestor)
				return ((binary_tree_t *)first);
			ancestor = ancestor->parent;
		}
		/*return pointer to the LCA of the two nodes*/
		first = first->parent;
	}
	return (NULL);
}
