#include "binary_trees.h"
/**
 * new_node -  creates a new_node in a linked_list
 * @node: Type pointer of node to be created
 * Return: the node created
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *new;

	new =  malloc(sizeof(link_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->node = node;
	new->next = NULL;

	return (new);
}
/**
 * free_q -  free the nodes at the linked list
 * @head: Node of the linked_list
 */
void free_q(link_t *head)
{
	link_t *tmp_node;

	while (head)
	{
		tmp_node = head->next;
		free(head);
		head = tmp_node;
	}
}
/**
 * _push -  pushes a node into the stack
 * @node: Type pointer of node of the tree
 * @head: Type head node of in the stack
 * @tail: Type tail node of in the stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *nw;

	nw = new_node(node);
	if (nw == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->next = nw;
	*tail = nw;
}
/**
 * _pop -  pops a node into the stack
 * @head: Type head node of in the stack
 */
void _pop(link_t **head)
{
	link_t *tmp_node;

	tmp_node = (*head)->next;
	free(*head);
	*head = tmp_node;
}
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: Type pointer of node of the tree
 * Return: 1 if is complete 0 if it is not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int fg = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (fg == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			fg = 1;
		if (head->node->right != NULL)
		{
			if (fg == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
		}
		else
			fg = 1;
		_pop(&head);
	}
	return (1);
}
