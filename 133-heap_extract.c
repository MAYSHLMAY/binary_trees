#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t h_l = 0;
	size_t h_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h_l = 1 + tree_height(tree->left);

	if (tree->right)
		h_r = 1 + tree_height(tree->right);

	if (h_l > h_r)
		return (h_l);
	return (h_r);
}
/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t h_l = 0;
	size_t h_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h_l = 1 + tree_size_h(tree->left);

	if (tree->right)
		h_r = 1 + tree_size_h(tree->right);

	return (h_l + h_r);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tp1, *tp2;

	if (!root)
		return;

	tp1 = root;

	while (1)
	{
		if (!tp1->left)
			break;
		if (!tp1->right)
			tp2 = tp1->left;
		else
		{
			if (tp1->left->n > tp1->right->n)
				tp2 = tp1->left;
			else
				tp2 = tp1->right;
		}
		if (tp1->n > tp2->n)
			break;
		value = tp1->n;
		tp1->n = tp2->n;
		tp2->n = value;
		tp1 = tp2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
