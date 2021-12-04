#include "binary_trees.h"


/**
 *binary_tree_postorder - Goes through a binary tree using postorder
 *transversal
 *
 *@func: And func is a pointer to a function to call for each node.
 *The value in the node must be passed as a parameter to this function.
 *@tree: Pointer to the root node of the tree to transverse
 *Return: Nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
binary_tree_t *temp;
int i;
int j;
int k;
binary_tree_t **arr;

/* checks if tree is empty */
if (tree == NULL || func == NULL)
return;

/* counts how many times root has been seen or reached */
j = 0;

k = 0;

/* stores addresses of visited nodes */
arr = malloc(sizeof(binary_tree_t *) * 1);
if (arr == NULL)
return;
arr[0] = NULL;

temp = (binary_tree_t *)tree;
 
/**
 * loops through element in the  tree
 * noting that the root can only be reached twice
 * for a complete transversal
*/
for(i = 0; j < 2; i++)
{
if (temp->left != NULL)
{
if (isvisited(temp, arr, k+1, 10) == 0 || temp->left == NULL)
{
if (isvisited(temp, arr, k+1, 20) == 0 || temp->right == NULL)
{
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
temp = temp->parent;
if (binary_tree_is_root(temp) == 1)
{
j += 1;
if (j == 2)
{
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
temp = NULL;
break;
}
else
temp = temp->right;
continue;
}
}
else
{
temp = temp->right;
continue;
}
} 

/* isvisited first statement */
else
{
while (0 == 0)
{
while (temp->left != NULL)
temp = temp->left;

if (temp->right != NULL)
{
temp = temp->right;
continue;
}

if (binary_tree_is_leaf(temp) == 1)
{
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
temp = temp->parent;
break;
}
}
}

if (isvisited(temp, arr, k+1, 20) == 0 || temp->right == NULL)
{
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
temp = temp->parent;
}
else
temp = temp->right;

}

else if (temp->right != NULL)
{
if (isvisited(temp, arr, k+1, 20) == 0 || temp->right == NULL)
{
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
temp = temp->parent;
}
}

else
{
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
temp = temp->parent;
}
}

for (i = 0; i < k+1; i++)
  free(arr[i]);
free(arr);
return;
}

/** 
 *Checks if a node has been been previously visited
 *
 *@node: node to check
 *@arr: arr of visited nodes
 *@len: len of this array
 *Return: 0 if node has been visited, 2 if the node
 *is the root node else 1
 */
int isvisited(binary_tree_t *node, binary_tree_t **arr, int len, int ind)
{
int c;
c = 0;
if (ind == 20)
{
for (c = 0; c < len; c++)
{
if (binary_tree_is_root(node) == 1)
return (2);
else if (node->right == arr[c])
return (0);
}
}
else if (ind == 10)
{
for (c = 0; c < len; c++)
{
if (binary_tree_is_root(node) == 1)
return (2);
else if (node->left == arr[c])
return (0);
}
}

return (1);
}

/**
*binary_tree_is_leaf - Checks if a node is a leaf
*@node: Pointer to the node to check
*
*Return: 1 if node is a leaf and 0 otherwise
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
if (node == NULL)
return (0);
if (node->left == NULL && node->right == NULL)
return (1);
return (0);
}

/**
*binary_tree_is_root - Checks if a given node is a root
*@node: Pointer to the node to check
*
*Return: 1 if node is a root and 0 otherwise
*/
int binary_tree_is_root(const binary_tree_t *node)
{
if (node == NULL)
return (0);
if (node->parent == NULL)
return (1);
return (0);
}
