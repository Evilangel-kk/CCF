#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int y[m] = {0};
	int s[m] = {0};
	for (int i = 0; i < m; i++)
	{
		cin >> y[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s[i];
	}
	int e[m] = {0};
	int l[m] = {0};
	bool canfinish = true;
	for (int i = 0; i < m; i++)
	{
		if (y[i] == 0)
		{
			e[i] = 1;
		}
		else
		{
			e[i] = s[y[i] - 1] + e[y[i] - 1];
		}
		if (s[i] + e[i] - 1 > n)
		{
			canfinish = false;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << e[i] << " ";
	}
	if (canfinish)
	{
		for (int i = m - 1; i >= 0; i--)
		{
			if (l[i] == 0)
			{
				if (y[i] == 0)
				{
					l[i] = n - s[i] + 1;
				}
				else
				{
					l[i] = n - s[i] + 1;
					int k = y[i] - 1; //当前依赖的任务号索引
					int t = i; //当前的任务号索引
					while (k >= 0)
					{
						if (l[k] == 0)
						{
							l[k] = l[t] - s[k];
						}
						else
						{
							l[k] = min(l[k], l[t] - s[k]);
						}
						t = k;
						k = y[k] - 1;
					}
				}
			}
		}
		cout << endl;
		for (int i = 0; i < m; i++)
		{
			cout << l[i] << " ";
		}
	}
}

