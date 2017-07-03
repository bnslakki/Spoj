#include "bits/stdc++.h"
using namespace std;
int r, c;
char arr[22][22];
bool f[22][22];
bool visit[22][22];
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
vector<pair<int, int>>s;
bool isSafe(pair<int, int>s)
{
	return (s.first >= 0) && (s.first < r) && (s.second >= 0) && (s.second < c);
}
bool bfs(vector<pair<int, int>>s)
{
	visit[s[0].first][s[0].second] = 1;
	queue<pair<int, int> >q;
	pair<int, int>temp;
	q.push(s[0]);
	while (!q.empty())
	{
		temp = q.front();
		if (s[1].first == temp.first&&s[1].second == temp.second)return true;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			pair<int, int>t1;
			t1.first = dx[k] + temp.first;
			t1.second = dy[k] + temp.second;
			if (isSafe(t1) && arr[t1.first][t1.second] == '.'&&!visit[t1.first][t1.second])
			{
				visit[t1.first][t1.second] = 1;
				q.push(t1);
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
		s.clear();
		memset(visit, 0, sizeof visit);
		memset(f, 0, sizeof f);
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; i++)
		{
			scanf("%s", arr[i]);
		}
		int ck = 0;
		for (int i = 0; i < c; i++)
		{
			if (arr[0][i] == '.'&&!f[0][i])
			{
				ck++;
				f[0][i] = 1;
				s.push_back(make_pair(0, i));
			}
		}
		for (int i = 0; i < c; i++)
		{
			if (arr[r-1][i] == '.'&&!f[r-1][i])
			{
				ck++;
				f[r-1][i] = 1;
				s.push_back(make_pair(r - 1, i));
			}
		}
		for (int i = 0; i < r; i++)
		{
			if (arr[i][0] == '.'&&!f[i][0])
			{
				ck++;
				f[i][0] = 1;
				s.push_back(make_pair(i, 0));
			}
		}
		for (int i = 0; i < r; i++)
		{
			if (arr[i][c-1] == '.'&&!f[i][c-1])
			{
				ck++;
				f[c-1][i] = 1;
				s.push_back(make_pair(i, c - 1));
			}
		}
		if (ck != 2)printf("invalid\n");
		else
		{
			if (bfs(s))printf("valid\n");
			else printf("invalid\n");
		}
	}
	return 0;
} 
