/* - Some Turkish Phrases - 
Algoritma ağacın kök düğümüyle başlar ve şu şekilde devam eder:
1. Sol alt ağaçta gezmek.
2. Sağ alt ağaçta gezmek.
3. Kök düğümü ziyaret etmek.
*/

#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    printf("%d ", node->data);
}

node *insertElement(node *tree, int val)
{
	node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	
	if(tree==NULL)
	{
		tree=ptr;
	}
	else
	{
		if(val<tree->data)
			tree->left = insertElement(tree->left, val);
		else
			tree->right = insertElement(tree->right, val);
	}
	return tree;
}

node *findElement(node *tree, int val)
{
	node *ptr;
	if(tree->data == val || tree == NULL)
		return tree;
	else
	{
		if(val<tree->data)
			return findElement(tree->left,val);
		else
			return findElement(tree->right,val);
	}
	
	return tree;
}
node *findLargestElement(node *tree)
{
	if( (tree == NULL) || (tree->right == NULL))
		return tree;
	else
		return findLargestElement(tree->right);
}

node *deleteElement(node *tree, int val)
{
	node *temp;
	if(tree==NULL)
		return tree;
	else if( val < tree->data)
		tree->left = deleteElement(tree->left, val);
	else if ( val> tree->data)
		tree->right = deleteElement(tree->right, val);
	else if ( tree->left != NULL && tree->right != NULL)
	{
		temp =  findLargestElement(tree->left);
		tree->data = temp->data;
		tree->left = deleteElement(tree->left,temp->data);
	}
	else
	{
		if(tree->left == NULL && tree->right == NULL)
			tree = NULL;
		else if( tree->left != NULL)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return tree;
}

/* Driver program to test above functions*/
int main()
{
	struct node* searchVal;
    struct node* root = newNode(1);
    insertElement(root,2);
    insertElement(root,8);
    insertElement(root,6);
	
	searchVal = findElement(root, 2);
	deleteElement(root,searchVal->data);
	//printf("searchVal = %d",searchVal->data);
    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);
 
    return 0;
}
