#include "binary_trees.h"


/**
 *binary_tree_delete - Deletes an entire binary tree
 *
 *@tree: Pointer to the root node of the tree to delete
 *Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
binary_tree_t *temp1;
binary_tree_t *temp2;
binary_tree_t *temp3 __attribute__((unused));

if (tree == NULL)
return;
temp1 = tree->left;

while (temp1 != NULL)
{
if (temp1->left != NULL)
{
while (temp1->left != NULL)
temp1 = temp1->left;
if (temp1->parent->right != NULL)
{
temp2 = temp1->parent->right;
}
else
temp2 = temp1->parent;
free(temp1);
temp2->left = NULL;
temp1 = temp2;
}

else if (temp1->right != NULL)
{
temp1 = temp1->right;
if (temp1->left != NULL)
{
while (temp1->left != NULL)
temp1 = temp1->left;
if (temp1->parent->right != NULL)
temp2 = temp1->parent->right;
else
temp2 = temp1->parent;
free(temp1);
temp2->left = NULL;
temp1 = temp2;
}
}

else
{
temp2 = temp1->parent;
free(temp1);
if (temp2 != NULL && temp1 == temp2->right)
temp2->right = NULL;
else if (temp2 != NULL && temp1 == temp2->left)
temp2->left = NULL;
temp1 = temp2;
if (temp2 == NULL)
tree = NULL;
}
}
return;
}
