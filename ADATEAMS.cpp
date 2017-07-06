#include "bits/stdc++.h"
using namespace std;
struct node {
	int data;
	node* next;
	node* pre;
};
node* create(int data)
{
	node* ret = (node*)malloc(sizeof(node));
	ret->data = data;
	ret->next = NULL;
	ret->pre = NULL;
	return ret;
}
void insert_begin(node*& head, node*& tail, int data)
{
	node* temp = create(data);
	if (!head&&!tail)
	{
		head = temp;
		tail = temp;
		return;
	}
	temp->next = head;
	head->pre = temp;
	head = temp;
	head->pre = NULL;
}
void insert_end(node*& head, node*& tail, int data)
{
	node* temp = create(data);
	if (!head&&!tail)
	{
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	temp->pre = tail;
	tail = temp;
	tail->next = NULL;
}
int main()
{
	//READ;
	node *head, *tail;
	head = tail = NULL;
	int q;
	int c = 0;
	scanf("%d", &q);
	bool f=0;
	while (q--)
	{
		
		string s;
		cin >> s;
		if (s.compare("toFront") == 0)
		{
			int n;
			scanf("%d", &n);
			c++;
			if(f==0)
			insert_begin(head, tail, n);
			else insert_end(head, tail, n);
		}
		else if (s.compare("push_back") == 0)
		{
			int n;
			scanf("%d", &n);
			c++;
			if(f==0)
			insert_end(head, tail, n);
			else insert_begin(head, tail, n);
		}
		else if (s.compare("reverse") == 0)
		{
			
			if(f==0)f=1;
			else f=0;
		}
		else if (s.compare("front") == 0&&f==0)
		{
			if (head == NULL || tail == NULL)printf("No job for Ada?\n");
			else
			{
				printf("%d\n", head->data);
				if (c == 1)
				{
					head = tail = NULL;
				}
				else
					head = head->next;
				c--;
			}
		}
		else if (s.compare("front") == 0&&f==1)
		{
			if (tail == NULL || head == NULL)printf("No job for Ada?\n");
			else
			{
				printf("%d\n", tail->data);
				if (c==1)head = tail = NULL;
				else
					tail = tail->pre;
				c--;
			}
		}
		else if (s.compare("back") == 0&&f==0)
		{
			if (tail == NULL || head == NULL)printf("No job for Ada?\n");
			else
			{
				printf("%d\n", tail->data);
				if (c==1)head = tail = NULL;
				else
					tail = tail->pre;
				c--;
			}
		}
		else if (s.compare("back") == 0&&f==1)
		{
			if (head == NULL || tail == NULL)printf("No job for Ada?\n");
			else
			{
				printf("%d\n", head->data);
				if (c == 1)
				{
					head = tail = NULL;
				}
				else
					head = head->next;
				c--;
			}
		}
	}
	return 0;
} 
