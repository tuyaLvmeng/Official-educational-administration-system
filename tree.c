#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TYPE int

typedef struct Node
{
	TYPE data;
	struct Node* left;
	struct Node* right;
}Node;

Node* creat_node(TYPE data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}


//添加
void _add_node(Node** root,Node* node)
{
	if(NULL==node) return;
	if(*root==NULL)
	{
		*root = node;
		return;
	}

	if((*root)->data<=node->data)
	_add_node(&(*root)->right,node);
	else
	_add_node(&(*root)->left,node);
}

//添加
void add_node(Node** root,TYPE data)
{
	Node* node = creat_node(data);
	_add_node(root,node);
}

//删除
void delete_tree(Node** root,TYPE data)
{
	if((*root)==NULL) return;
	if((*root)->data==data)
	{
		Node* temp = *root;
		*root = temp->left;
		_add_node(root,temp->right);
		free(temp);
		return;
	}
	else if((*root)->data<=data)
	delete_tree(&(*root)->right,data);
	else
	delete_tree(&(*root)->left,data);

}

//二叉树的高度
int high_tree(Node* root)
{
	if(NULL==root) return 0;
	int lf=high_tree(root->left);
	int lr=high_tree(root->right);
	return 1+(lf>lr?lf:lr);
}

//二叉树的密度
int density_tree(Node* root)
{
	if(NULL==root) return 0;

	int l=density_tree(root->left);
	int r=density_tree(root->right);
	return 1+l+r;
}

//中序遍历
void show_tree(Node* root)
{
	if(root==NULL) return;

	show_tree(root->left);
	printf("%d ",root->data);
	show_tree(root->right);
}

int main()
{
	Node* root = NULL;
	add_node(&root,9);
	add_node(&root,6);
	add_node(&root,4);
	add_node(&root,2);
	add_node(&root,8);
	show_tree(root);
	printf("\n");
	delete_tree(&root,11);
	show_tree(root);
	printf("\n%d",high_tree(root));
	printf("\n%d",density_tree(root));

}
