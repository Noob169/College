#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct list {

    int data;
    struct node *left;
    struct node *right;

}node;

node* insert(node* root, int data)
{
	if(root==NULL)
    {
    node* x = (node*)malloc(sizeof(node));
    x->data = data;
    x->left = NULL;
    x->right = NULL;
    return x;
	}
	else {

		node* cur;
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
		return root;
	}
}

void inorder(node *root) {
        if(root==NULL)
        return;
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);

    }

void preorder(node *root) {
        if(root==NULL)
        return;
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

void postorder(node *root) {
        if(root==NULL)
        return;
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);

    }

int main()
{
    int n,i;
    int item;
    printf("Enter value of n: ");
    scanf("%d",&n);
    printf("Enter values:\n");
    scanf("%d",&item);
    node *root=(node*)malloc(sizeof(node));
    root->data = item;
    root->left = NULL;
    root->right = NULL;
    for(i=1;i<n;i++)
    {
        scanf("%d",&item);
        root=insert(root,item);
    }
    printf("Preorder:\n");
    preorder(root);
    printf("\n");
    printf("Inorder:\n");
    inorder(root);
    printf("\n");
    printf("Postorder:\n");
    postorder(root);
    printf("\n");
    return 0;
}
void printLeaf(node* root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        printf("%d ",root->data);
    printLeaf(root->left);
    printLeaf(root->right);
}