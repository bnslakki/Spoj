#include "bits/stdc++.h"
using namespace std;
 
map<string, int>mp;
struct node
{
	int frequency;
	bool isend;
	node* arr[26];
};
node* create()
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->frequency = 0;
	newnode->isend = 0;
	for (int i = 0; i < 26; i++)newnode->arr[i] = NULL;
	return newnode;
}
void insert(node* root, string s)
{
	int l = s.length();
	node* temp = root;
	for (int i = 0; i < l; i++)
	{
		if (!temp->arr[s[i] - 'a']) {
			temp->arr[s[i] - 'a'] = create();
		}
		temp = temp->arr[s[i] - 'a'];
		temp->frequency = temp->frequency + 1;
	}
	temp->isend = 1;
}
int search(node* root, string s)
{
	node* temp = root;
	int l = s.length();
	for (int i = 0; i < l; i++)
	{
		if (temp->arr[s[i] - 'a'])temp = temp->arr[s[i] - 'a'];
		else return 0; 
	}
	return temp->frequency;
}
 
int main()
{
	//READ;
	node* root = create();
	int n, q;
	scanf("%d%d", &n, &q);
	string s;
	for (size_t i = 0; i < n; i++)
	{
		cin >> s;
		insert(root, s);
	}
	while (q--)
	{
		cin >> s;
		printf("%d\n",search(root, s));
	}
	return 0;
} 
