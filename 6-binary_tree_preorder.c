#include "binary_trees.h"


/**
 *binary_tree_preorder - Goes through a binary tree using preorder
 *transversal
 *
 *@func: And func is a pointer to a function to call for each node.
 *The value in the node must be passed as a parameter to this function.
 *@tree: Pointer to the root node of the tree to delete
 *Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
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

/* transverse the root first */
(*func)(tree->n);
temp = (binary_tree_t *)tree;
 
/**
 * loops through element in the  tree
 * noting that the root can only be reached twice
 * for a complete transversal
*/
for(i = 0; j < 2; i++)
{
/* checks if current node has a left child */
if (temp->left != NULL)
{
/**
 * if it does, finds the leftmost child while transversing
 * or visiting each of this children until a leaf node is found.
*/
while (0 == 0)
{
while (temp->left != NULL)
{
temp = temp->left;
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
}
/** 
 * if a leftmost child has a right child
 * visit that child too until.
 */
if (temp->right != NULL)
{
temp = temp->right;
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
}

if (binary_tree_is_leaf(temp) == 1)
  break;
}

/**
 *If this current node doesnt have a right child nor a left child.
 *Move backwards until a node with a right child that has not
 *been visited is found.
 *This is the usefulness of arr.
 */
temp = temp->parent;
while (isvisited(temp, arr, k+1) == 0 || temp->right == NULL)
  temp = temp->parent;
if (isvisited(temp, arr, k+1) == 2)
{
j += 1;
if (j == 2)
break;
}

temp = temp->right;
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
}

else if (temp->right != NULL)
{
temp = temp->right;
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
}

else
{
temp = temp->parent;
while (isvisited(temp, arr, k+1) == 0 || temp->right == NULL)
  temp = temp->parent;
if (isvisited(temp, arr, k+1) == 2)
{
j += 1;
if (j == 2)
break;
}

temp = temp->right;
(*func)(temp->n);
arr[k] = temp;
k++;
arr = reallocarray(arr, k+1, sizeof(binary_tree_t));
arr[k] = NULL;
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
int isvisited(binary_tree_t *node, binary_tree_t **arr, int len)
{
int c;
c = 0;
for (c = 0; c < len; c++)
{
if (binary_tree_is_root(node) == 1)
return (2);
else if (node->right == arr[c])
return (0);
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
