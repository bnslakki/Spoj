#include "bits/stdc++.h"
using namespace std;

int n, len;
int arr[100005];
pair<int, int> b[350];
void sqrt_decompose()
{
	double l = sqrt(n);
	len = (int)ceil(n / l);
	//printf("len is %d\n", len);
	int current_block = 0;
	int mn = INT_MAX;
	for (size_t i = 0; i < n; i++)
	{
		b[i / len].first += arr[i];
		if ((i / len) == current_block)
		{
			mn = min(mn, arr[i]);
		}
		else
		{
			b[i / len - 1].second = mn;
			mn = INT_MAX;
			current_block = i / len;
		}	
	}
	b[current_block].second = mn;
}
void grow(int i, int val)
{
	int block = i / len;
	b[block].first += val;
	arr[i] += val;
	int mn = INT_MAX;
	for (size_t k = len*block; k < len*block+len&&k < n; k++)
	{
		mn = min(mn, arr[k]);
	}
	b[block].second = mn;
}
void eat(int i, int val)
{
	int block = i / len;
	//printf("block is %d\n", block);
	b[block].first -= val;
	arr[i] -= val;
	int mn = INT_MAX;
	for (size_t k = len*block; k < len*block+len&&k < n; k++)
	{
		mn = min(mn, arr[k]);
	}
	b[block].second = mn;
}
ll count(int i, int j)
{
	ll sum = 0;
	int startblock = i / len;
	int endblock = j / len;
	int mn = INT_MAX;
	if (startblock == endblock)
	{
		for (int k = i; k <= j; k++)
		{
			sum += arr[k];
			mn = min(mn, arr[k]);
		}
		return sum - mn;
	}
	for (size_t k = i; k <=(startblock+1)*len-1; k++)
	{
		sum += arr[k];
		mn = min(mn, arr[k]);
	}
	for (int k = startblock + 1; k <= endblock - 1; k++)
	{
		sum += b[k].first;
		mn = min(mn, b[k].second);
	}
	for (int k = endblock*len; k <= j; k++)
	{
		sum += arr[k];
		mn = min(mn, arr[k]);
	}
	return sum - mn;
}
int main()
{
	//READ;
	scanf("%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sqrt_decompose();
	int q;
	scanf("%d", &q);
	while (q--)
	{
		char s[10];
		int x, y;
		scanf("%s%d%d", s, &x, &y);
		if (s[0] == 'C')
		{
			printf("%lld\n", count(x, y));
		}
		else if (s[0] == 'G')
		{
			grow(y, x);
		}
		else
		{
			eat(y, x);
		}
	}
	return 0;
} 
