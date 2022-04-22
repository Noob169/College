#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;

void inorder(Node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%d\t", t->data);
        inorder(t->right);
    }
}

void postorder(Node *t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d\t", t->data);
    }
}

void preorder(Node *t)
{
    if(t!=NULL)
    {
        printf("%d\t", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void leaf(Node *root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        printf("%d ",root->data);
    leaf(root->left);
    leaf(root->right);
}

Node* insert( Node *root, int data ) {
		
	if(root == NULL) //if tree is empty or if the node is a leaf
    {
	
        Node* t = (Node*)malloc(sizeof(Node));

        t->data = data;

        t->left = NULL;
        t->right = NULL;
        return t;   //returns the address of the root node or the node where the data is entered
	  
	} 
    else //if root node is already created
    {  
		Node *t;
        if(data>root->data)
        {
            t=insert(root->right,data);
            root->right = t;
        }
        else 
        {
            t=insert(root->left,data);
            root->left = t;
        }
	
		return root;
	}
}

void main()
{
    int n, d=0;
    Node *root = NULL;
    printf("Enter the number of nodes that you want to create:\n");
    scanf("%d", &n);
    int i=1;
    while(i<=n)
    {
        printf("Enter the data:\n");
        scanf("%d",&d);
        root = insert(root,d);
        i++;
    }
    printf("\nThe preordered sequence:\n");
    preorder(root);
    printf("\nThe inordered sequence:\n");
    inorder(root);
    printf("\nThe postordered sequence:\n");
    postorder(root);
    printf("\nThe leaves of the program are:\n");
    leaf(root);
}