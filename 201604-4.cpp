#include<stdio.h>
struct Trap
{
	int x;
	int y;
	int t1;
	int t2;
};
int main()
{
	int n = 0, m = 0, t = 0;
	scanf("%d%d%d", &n, &m, &t);
	int a[105][105] = {0};
	struct Trap trap[9999];
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d%d%d", &trap[i].x, &trap[i].y, &trap[i].t1, &trap[i].t2);
	}
	int k = 1;
	int x = 0;
	int y = 0;
	int time = 0;
	while (!(x == n - 1 && y == m - 1))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < t; i++)
		{
			if (k >= trap[i].t1 && k <= trap[i].t2)
			{
				a[trap[i].x - 1][trap[i].y - 1] = 1;
			}
		}
		if (x + 1 < n && a[x + 1][y] != 1)
		{
			x++;
		}
		else if (y + 1 < m && a[x][y + 1] != 1)
		{
			y++;
		}
		else if (x - 1 >= 0 && a[x - 1][y - 1] != 1)
		{
			x--;
		}
		else if (y - 1 >= 0 && a[x][y - 1] != 1)
		{
			y--;
		}
		k++;
	}
	x = 0;
	y = 0;
	time = k;
	k = 0;
	while (!(x == n - 1 && y == m - 1))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < t; i++)
		{
			if (k >= trap[i].t1 && k <= trap[i].t2)
			{
				a[trap[i].x - 1][trap[i].y - 1] = 1;
			}
		}
		if (y + 1 < m && a[x][y + 1] != 1)
		{
			y++;
		}
		else if (x + 1 < n && a[x + 1][y] != 1)
		{
			x++;
		}
		else if (x - 1 >= 0 && a[x - 1][y] != 1)
		{
			x--;
		}
		else if (y - 1 >= 0 && a[x][y - 1] != 1)
		{
			y--;
		}
		k++;
	}
	if (time > k)
	{
		time = k;
	}
	x = 0;
	y = 0;
	k = 0;
	while (!(x == n - 1 && y == m - 1))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < t; i++)
		{
			if (k >= trap[i].t1 && k <= trap[i].t2)
			{
				a[trap[i].x - 1][trap[i].y - 1] = 1;
			}
		}
		if (y + 1 < m && a[x][y + 1] != 1)
		{
			y++;
		}
		else if (x + 1 < n && a[x + 1][y] != 1)
		{
			x++;
		}
		else if (y - 1 >= 0 && a[x][y - 1] != 1)
		{
			y--;
		}
		else if (x - 1 >= 0 && a[x - 1][y] != 1)
		{
			x--;
		}
		k++;
	}
	if (time > k)
	{
		time = k;
	}
	x = 0;
	y = 0;
	k = 0;
	while (!(x == n - 1 && y == m - 1))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < t; i++)
		{
			if (k >= trap[i].t1 && k <= trap[i].t2)
			{
				a[trap[i].x - 1][trap[i].y - 1] = 1;
			}
		}
		if (x + 1 < n && a[x+1][y] != 1)
		{
			x++;
		}
		else if (y + 1 < m && a[x][y+1] != 1)
		{
			y++;
		}
		else if (y - 1 >= 0 && a[x][y - 1] != 1)
		{
			y--;
		}
		else if (x - 1 >= 0 && a[x - 1][y] != 1)
		{
			x--;
		}
		k++;
	}
	if (time > k)
	{
		time = k;
	}
	printf("%d", time - 1);
	return 0;
}
