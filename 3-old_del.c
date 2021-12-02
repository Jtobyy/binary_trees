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
if (tree == NULL)
return;
temp1 = tree->left;
temp2 = tree->right;
while(temp1 != NULL)
{
temp2 = temp1->left;
free(temp1);
temp1 = temp2;
}
temp1 = tree->right;
while(temp1 != NULL)
{
temp2 = temp1->right;
free(temp1);
temp1 = temp2;
}
free(tree);
return;
}

