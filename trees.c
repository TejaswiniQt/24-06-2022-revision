/****************Implementation of Binary tree*********************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}tree;



tree *create();
void preorder(tree *root);
void postorder(tree *root);
void inorder(tree *root);

int main()
{
	tree *root = NULL;
	root = create();
	printf("Pre-order is:\n");
	preorder(root);
	printf("\n");
	printf("Post-order is:\n");
	postorder(root);
	printf("\n");
	printf("In-order is:\n");
	inorder(root);
	printf("\n");

	return 0;
}


tree *create()
{
	int data;
	tree *newnode = (tree *)malloc(sizeof(tree));
	if(newnode == NULL)
	{
		printf("Memory not allocated\n");
		return NULL;
	}
	printf("Enter the data(enter -1 for no node):");
	__fpurge(stdin);
	scanf("%d",&data);
	if(data == -1)
	{
		return NULL;
		free(newnode);
	}
	newnode->data = data;
	printf("Enter the left child node of %d :",data);
	newnode->left = create();
	printf("Enter the right child of %d :",data);
	newnode->right = create();
	return newnode;
}


void preorder(tree *root)
{
	if(root != NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(tree *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

void inorder(tree *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

