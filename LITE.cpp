#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int segtree[4 * 100000];
bool lazytree[4 * 100000];
int query(int v, int low, int high, int start, int end)
{
	if (lazytree[v])
	{
		segtree[v] = abs((high - low + 1) - segtree[v]);
		if (low != high)
		{
			lazytree[2 * v + 1] = !lazytree[2 * v + 1];
			lazytree[2 * v + 2] = !lazytree[2 * v + 2];
		}
		lazytree[v] = false;
	}
	if (low>high || low>end || high<start)
		return 0;
	if (low >= start&&high <= end)
		return segtree[v];
	return query(2 * v + 1, low, (low + high) / 2, start, end) + query(2 * v + 2, 1 + (low + high) / 2, high, start, end);
}
void updatetree(int v, int low, int high, int start, int end)
{
	if (lazytree[v] )
	{
		//printf("d %d %d\n",low,high);
		segtree[v] = abs(segtree[v] - (high - low + 1));
		if (low != high)
		{
			lazytree[2 * v + 1] = !lazytree[2 * v + 1];
			lazytree[2 * v + 2] = !lazytree[2 * v + 2];
		}
		lazytree[v] = false;
	}
	if (low>high || low>end || high<start)
		return;
 
	if (low >= start&&high <= end)
	{
	//	printf("%d %d\n", low, high);
		segtree[v] = abs(segtree[v]-(high - low + 1));
		if (low != high)
		{
			lazytree[2 * v + 1] = !lazytree[2 * v + 1];
			lazytree[2 * v + 2] = !lazytree[2 * v + 2];
		}
		return;
	}
	int mid = (low + high) / 2;
	updatetree(2 * v + 1, low, mid, start, end);
	updatetree(2 * v + 2, mid + 1, high, start, end);
	segtree[v] = segtree[2 * v + 1] + segtree[2 * v + 2];
}
int main()
{
//	freopen("t.txt", "r", stdin);
	int n, q;
	scanf("%d%d", &n,&q);
	while (q--)
	{
		int op, st, en;
		scanf("%d%d%d", &op, &st, &en);
		if (op == 0)
		{
			updatetree(0, 0, n - 1, st - 1, en - 1);
		}
		else
		{
			printf("%d\n", query(0, 0, n - 1, st-1, en-1));
		}
	}
	return 0;
} 
