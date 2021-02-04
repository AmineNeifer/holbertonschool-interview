#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sorted_array_to_avl - convert a sorted array to an AVL
 *
 * @array: array to convert.
 * @size: size of the array.
 *
 * Return: pointer to the root node of the created AVL tree, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	return (sortedArrayToBST(array, 0, size - 1, NULL));
}
/**
 * sortedArrayToBST - recursive function to change sorted array to BST.
 *
 * @array: array to convert.
 * @start: start idx of the part of the array to convert part of tree.
 * @end: end idx of the part of the array to convert part of tree.
 * @par: parent node (pointer).
 *
 * Return: returns root of BST created.
 */
avl_t *sortedArrayToBST(int *array, int start, int end, avl_t *par)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;

	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);
	root->n = array[mid];
	root->parent = par;
	root->left = sortedArrayToBST(array, start, mid - 1, root);
	root->right = sortedArrayToBST(array, mid + 1, end, root);
	return (root);
}
