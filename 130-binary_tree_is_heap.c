 #include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * max_check - goes through a binary tree cheking ropt as max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 **/
int max_check(const binary_tree_t *tree)
{
	int tp1 = 1, tp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tp1 = max_check(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tp2 = max_check(tree->right);
	}
	return (tp1 && tp2);
}
/**
 * binary_tree_is_heap - checks if a binary tree is heap
 * @tree: pointer to the node
 * Return: 1 in case BTS /  0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tp;

	if (!tree)
		return (0);

	tp = binary_tree_is_complete(tree);
	if (!tp)
		return (0);
	return (max_check(tree));
}
