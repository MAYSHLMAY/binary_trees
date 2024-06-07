#include "binary_trees.h"

/**
 * binary_tree_height -  measures the height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lm = 0;
	size_t rl = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			lm = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			rl = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((lm > rl) ? lm : rl);
	}
}
