#include "binary_trees.h"
/**
 * binary_tree_size -  return the size of a tree
 * @tree: tree to check
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, rl = 0, lm = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		lm = binary_tree_size(tree->left);
		rl = binary_tree_size(tree->right);
		size = rl + lm + 1;
	}
	return (size);
}
