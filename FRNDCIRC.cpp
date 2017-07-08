#include "bits/stdc++.h"
using namespace std;
unordered_map<string, int>mp;
int parent[200005];
int Rank[200005];
int Size[200005];
void make_set(int v)
{
	parent[v] = v;
	Rank[v] = 0;
	Size[v] = 1;
}
int find_set(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
int ans;
void union_sets(int a, int b)
{
	int t;
	a = find_set(a);
	b = find_set(b);
	if (a != b)
	{
		if (Rank[a] < Rank[b])
			swap(a, b);
		parent[b] = a;
		if (Rank[a] == Rank[b])
			++Rank[a];
 
		t = Size[a] + Size[b];
	//	printf("%d\n", t);
		Size[a] = t;
		Size[b] = t;
	}
	ans = Size[a];
	//printf("%d %d\n", Size[a], Size[b]);
}
int main()
{
//	INPUT;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int sz = 2 * n;
		for (size_t i = 1; i < sz + 3; i++)
		{
			make_set(i);
		}
		
		int j = 1;
		while (n--)
		{
			char a[30], b[30];
		//	string a, b;
		//	cin >> a >> b;
			scanf("%s%s", a, b);
			if (mp[a] == 0)
			{
				
				mp[a] = j;
				j++;
			}
			if (mp[b] == 0)
			{
				//DEBUG;
				mp[b] = j;
				j++;
			}
			union_sets(mp[a], mp[b]);
			printf("%d\n", ans);
		}
		mp.clear();
	}
	return 0;
} 
