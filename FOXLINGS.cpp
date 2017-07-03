#include "bits/stdc++.h"
using namespace std;
struct node
{
	int data;
	int rank;
	node* parent;
};
map<int, node*> mp2;
void makeset(int data)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->rank = 0;
	temp->parent = temp;
	mp2[data] = temp;
}
node* find(int x)
{
	node* current = mp2[x];
	node* Parent = current->parent;
	if (current == Parent)
	{
		return Parent;
	}
	Parent = find(Parent->data);
}
void Union(int d1, int d2)
{
	node* parent1 = find(d1);
	node* parent2 = find(d2);
	if (parent1->data == parent2->data)
		return;
	if (parent1->rank > parent2->rank)
	{
		parent2->parent = parent1->parent;
	}
	else if (parent1->rank == parent2->rank)
	{
		parent1->rank++;
		parent2->parent = parent1->parent;
	}
	else
	{
		parent1->parent = parent2->parent;
	}
}
map<int, int>mp;
int ck[1000000];
int main()
{
	//input;
	int n, m;
	int j = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 2 * m; i++)
	{
		makeset(i);
	}
	//Union(3, 1);
	//Union(6, 1);
	int ct = 0;
	for (int i = 0; i < m;i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (!mp[a])
		{
			mp[a] = j + 1;
			j++;
		}
		if (!mp[b])
		{
			mp[b] = j + 1;
			j++;
		}
	//	printf("%d\n", j);
		Union(mp[a], mp[b]);
		
		
	}
	for (int i = 1; i <= j; i++)
	{
		//cout << find(i)->data << " ";
		ck[find(i)->data] = 1;
	}
	//printf("\n");
	//printf("%d\n", j);
	for (int i = 1; i <= j; i++)
	{
		//cout << ck[i] << " ";
		if (ck[i] != 0)
			ct++;
	}
	//printf("\n");
	int temp = n - j;
	//printf("%d\n", temp);
	  printf("%d\n", ct + temp);
	//printf("%d\n", find(1));
	return 0;
} 
