#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_node - add a new node to the binary tree.
 *
 * @parent: parent variable.
 * @value: value to put in the node.
 *
 * Return: pointer to the new node, NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(*node));
	if (!node)
		return NULL;
	node->n = value;
	node->right = NULL;
	node->left = NULL;
	node->parent = parent;
	return (node);
}
