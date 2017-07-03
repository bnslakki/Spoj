#include "bits/stdc++.h"
using namespace std;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
bool visit[105][105];
int r, c;
char arr[105][105];
bool issafe(int i, int j)
{
	return (i >= 0) && (i < r) && (j >= 0) && (j < c);
}
string pattern = "ALLIZZWELL";
bool dfs(int i, int j,int level)
{
	//printf("%c ", arr[i][j]);
	visit[i][j] = 1;
	if (level == 9)return true;
 
	for (int k = 0; k < 8; k++)
	{
		if (issafe(i + dx[k], j + dy[k]))
		{
			if ((arr[i + dx[k]][j + dy[k]] == pattern[level + 1]) && (!visit[i + dx[k]][j + dy[k]]))
			{
				visit[i + dx[k]][j + dy[k]] = 1;
				if (dfs(i + dx[k], j + dy[k], level + 1))
					return true;
				visit[i + dx[k]][j + dy[k]] = 0;
			}
		}
	}
	visit[i][j] = 0;
	return false;
}
bool solve()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == 'A' && dfs(i, j, 0))
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	//READ;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(visit, 0, sizeof(visit));
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; i++)
		{
			scanf("%s", arr[i]);
		}
		if (solve())printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
} 
