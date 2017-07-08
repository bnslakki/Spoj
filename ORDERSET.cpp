// AVL tree ORDERSET SPOJ
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct node
{
	node* left;
	int data;
	node* right;
	int height;
	int size; // no of nodes in subtree
};
node* create(int data)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->height = 1;
	temp->left = NULL;
	temp->right = NULL;
	temp->size = 1;
	return temp;
}
int ht(node* root)
{
	if (!root)
		return 0;
	else
		return root->height;
}
int get_sum(node *root) {
 
	if (root == NULL)
		return 0;
	return root->size;
}
int getBalance(node *N)
{
	if (N == NULL)
		return 0;
	return ht(N->left) - ht(N->right);
}
node *rotateleft(node *x)
{
	node *y = x->right;
	node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(ht(x->left), ht(x->right)) + 1;
	x->size = get_sum(x->left) + get_sum(x->right) + 1;
	y->height = max(ht(y->left), ht(y->right)) + 1;
	y->size = get_sum(y->left) + get_sum(y->right) + 1;
	return y;
}
node *rotateright(node *x)
{
	node *y = x->left;
	node *y_right = y->right;
 
	y->right = x;
	x->left = y_right;
 
	x->height = max(ht(x->left), ht(x->right)) + 1;
	x->size= get_sum(x->left) + get_sum(x->right) + 1;
	y->height = max(ht(y->left), ht(y->right)) + 1;
	y->size = get_sum(y->left) + get_sum(y->right) + 1;
	return y;
}
node* search(node* root, int data)
{
	if (root == NULL)
		return NULL;
	while (root)
	{
		if (data == root->data)
			return root;
		else if (data < root->data)
			root = root->left;
		else
			root = root->right;
	}
	return NULL;
}
node* insert(node* root, int data)
{
	if (root == NULL)
		return create(data);
	if (search(root, data) != NULL)
	{
		return root;
	}
	if (data < root->data)
		root->left = insert(root->left, data);
 
	else
		root->right = insert(root->right, data);
 
	root->height = max(ht(root->left), ht(root->right)) + 1;
	root->size = get_sum(root->left) + get_sum(root->right) + 1;
	int bf = getBalance(root);
 
	//left left case
	if (bf > 1 && data < root->left->data)
		return rotateright(root);
 
	// right right case
	if (bf<-1 && data>root->right->data)
		return rotateleft(root);
 
	// left right case
	if (bf > 1 && data > root->left->data)
	{
		root->left = rotateleft(root->left);
		return rotateright(root);
	}
 
	// right left case
	if (bf < -1 && data < root->right->data)
	{
		root->right = rotateright(root->right);
		return rotateleft(root);
	}
	return root;
}
node * minValueNode(struct node* root)
{
	node* current = root;
	while (current->left != NULL)
		current = current->left;
	return current;
}
node* deletenode(node* root,int data)
{
	if (search(root, data) != NULL)
	{
		if (root == NULL)
			return root;
		if (data < root->data)
			root->left = deletenode(root->left, data);
		else if (data > root->data)
			root->right = deletenode(root->right, data);
		else
		{
			// node with only one child or no child
			if (root->left == NULL)
			{
				struct node *temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == NULL)
			{
				struct node *temp = root->left;
				free(root);
				return temp;
			}
 
			node* temp = minValueNode(root->right);
 
			root->data = temp->data;
 
			root->right = deletenode(root->right, temp->data);
		}
		root->height = max(ht(root->left), ht(root->right)) + 1;
		root->size = get_sum(root->left) + get_sum(root->right) + 1;
		int balance = getBalance(root);
 
		// Left Left Case
		if (balance > 1 && getBalance(root->left) >= 0)
			return rotateright(root);
 
		// Left Right Case
		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = rotateleft(root->left);
			return rotateright(root);
		}
 
		// Right Right Case
		if (balance < -1 && getBalance(root->right) <= 0)
			return rotateleft(root);
 
		// Right Left Case
		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rotateright(root->right);
			return rotateleft(root);
		}
	}
//	else
	{
		return root;
	}
}
int k_small(node* root, int k)
{
	if (root == NULL)
		return 0;
	int r = get_sum(root->left)+1;
	if (k == r)
		return root->data;
	 if (k < r)
		return k_small(root->left, k);
	else
		return k_small(root->right, k-r);
}
int count(node* root, int x)
{
	if (root == NULL)
		return 0;
	if (x < root->data)
	{
		return count(root->left, x);
	}
	else if (root->data == x)
	{
		if (root->left != NULL)
			return get_sum(root->left) + 1;
		else
			return 1;
	}
	else
	{
		if (root->left != NULL)
			return get_sum(root->left) + count(root->right, x) + 1;
		else
			return count(root->right, x) + 1;
	}
}
int main()
{
//	freopen("t.txt", "r", stdin);
	node* root = NULL;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char a[3];
		int num;
		scanf("%s%d", a, &num);
		if (a[0] == 'I')
		{
			root = insert(root, num);
		}
		else if (a[0] == 'D')
		{
			root = deletenode(root, num);
		}
		else if (a[0] == 'K')
		{
			if (root == NULL)
				printf("invalid\n");
			else if (root->size < num)
				printf("invalid\n");
			else
				printf("%d\n", k_small(root, num));
			
		}
		else
		{
			int q = count(root, num);
			if (search(root, num) != NULL)
				printf("%d\n", q - 1);
			else
				printf("%d\n", q);
		}
	}
	return 0;
}
 
