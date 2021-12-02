#include "binary_trees.h"


/**
 *binary_tree_insert_right - Inserts a node as the right-child of another node
 *@parent: Pointer to the node to insert the right-child in.
 *@value: Value to store in the new node.
 *Return: Pointer to the new node or null on failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *newrightnode;
if (parent == NULL)
return (NULL);
newrightnode = malloc(sizeof(binary_tree_t));
if (newrightnode == NULL)
return (NULL);
newrightnode->n = value;
newrightnode->parent = parent;
newrightnode->right = NULL;
newrightnode->left = NULL;
if (parent->right == NULL)
parent->right = newrightnode;
else
{
newrightnode->right = parent->right;
parent->right->parent = newrightnode;
parent->right = newrightnode;
}
return (newrightnode);
}
