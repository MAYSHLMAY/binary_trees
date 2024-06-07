#include "binary_trees.h"

/**
 * binary_trees_ancestor -  checks an ancestor
 * @first: First node
 * @second: Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *ptmp, *qtmp;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	ptmp = first->parent;
	qtmp = second->parent;
	if (ptmp == NULL || first == qtmp || (!ptmp->parent && qtmp))
	{
		return (binary_trees_ancestor(first, qtmp));
	}
	else if (qtmp == NULL || ptmp == second || (!qtmp->parent && ptmp))
	{
		return (binary_trees_ancestor(ptmp, second));
	}
	return (binary_trees_ancestor(ptmp, qtmp));
}
