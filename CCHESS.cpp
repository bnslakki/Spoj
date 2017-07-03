#include "bits/stdc++.h"
using namespace std;
int dx[] = { 2,2,1,-1,1,-1,-2,-2 };
int dy[] = { -1,1,2,2,-2,-2,1,-1 };
bool visit[10][10];
bool isSafe(int i, int j)
{
	return (i >= 0) && (i <= 7) && (j >= 0) && (j <= 7);
}
int bfs(int i, int j, int di, int dj)
{
	//visit[i][j] = 1;
	priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
	pq.push(make_tuple(0, i, j));
	while (!pq.empty())
	{
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		int z = get<0>(pq.top());
		pq.pop();
		if (x == di&&y == dj)
		{
			return z;
		}
		visit[x][y] = 1;
		for (int K = 0; K < 8; K++)
		{
			if (isSafe(x + dx[K], y + dy[K])&&!visit[x+dx[K]][y+dy[K]])
			{
			//	visit[x + dx[K]][y + dy[K]] = 1;
				pq.push(make_tuple(z+x*(x+dx[K])+y*(y+dy[K]),x + dx[K], y + dy[K]));
			}
		}
	}
	return -1;
}
 
int main()
{
	int a, b, c, d;
	while (scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
	{
		memset(visit, 0, sizeof visit);
		printf("%d\n", bfs(a, b, c, d));
	}
	return 0;
} 
