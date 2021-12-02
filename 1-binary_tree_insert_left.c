#include "binary_trees.h"


/**
 *binary_tree_insert_left - Inserts a node as the left-child of another node
 *@parent: A pointer to the node to insert the left child in
 *@value: The value to store in the new node
 *Return: A pointer to the created node, or NULL on failure or if
 *parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *newleftnode;
if (parent == NULL)
return (NULL);
newleftnode = malloc(sizeof(binary_tree_t));
if (newleftnode == NULL)
return (NULL);
newleftnode->n = value;
newleftnode->parent = parent;
newleftnode->right = NULL;
newleftnode->left = NULL;
if (parent->left == NULL)
parent->left = newleftnode;
else
{
newleftnode->left = parent->left;
parent->left->parent = newleftnode;
parent->left = newleftnode;
}
return (newleftnode);
}
