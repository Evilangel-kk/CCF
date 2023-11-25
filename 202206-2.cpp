#include<bits/stdc++.h>
using namespace std;

map<int, map<int, int> >mp;
struct node
{
	int x, y;
} point[1001];

int g[51][51];

int main()
{
	int n, L, S;
	cin >> n >> L >> S;
	for (int i = 0; i < n; i++)
	{
		cin >> point[i].x >> point[i].y;
		mp[point[i].x][point[i].y] = 1;
	}
	for (int i = S; i >= 0; i--)
	{
		for (int j = 0; j <= S; j++)
		{
			cin >> g[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		int x = point[i].x;
		int y = point[i].y;
		for (int j = 0; j <= S; j++)
		{
			for (int k = 0; k <= S; k++)
			{
				if (x + S > L || y + S > L || mp[x + j][y + k] != g[j][k])
				{
					flag = 0;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
