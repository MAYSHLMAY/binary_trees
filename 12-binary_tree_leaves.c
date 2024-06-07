#include "binary_trees.h"
/**
 * binary_tree_leaves -  returns the number of leaves in a tree
 * @tree: tree to check
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lf = 0, lm = 0, rl = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		lm = binary_tree_leaves(tree->left);
		rl = binary_tree_leaves(tree->right);
		lf = lm + rl;
		return ((!lm && !rl) ? lf + 1 : lf + 0);
	}
}
