#include<stdio.h>
int main()
{
	int m = 0, n = 0, q = 0;
	scanf("%d%d%d", &m, &n, &q);
	char map[101][101] = { 0 };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[i][j] = '.';
		}
	}
	int od[101][5];
	char order[101];
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &od[i][0]);
		if (od[i][0] == 1)
		{
			scanf("%d%d", &od[i][1], &od[i][2]);
			scanf("%s", &order[i]);
		}
		else
		{
			scanf("%d%d%d%d", &od[i][1], &od[i][2], &od[i][3], &od[i][4]);
			if (od[i][1] == od[i][3])
			{
				int j = 0;
				int k = 0;
				if (od[i][2] < od[i][4])
				{
					j = od[i][2];
					k = od[i][4];
				}
				else
				{
					j = od[i][4];
					k = od[i][2];
				}
				for (; j <= k; j++)
				{
					map[od[i][1]][j] = '|';
				}
			}
			else if (od[i][2] == od[i][4])
			{
				int j = 0;
				int k = 0;
				if (od[i][1] < od[i][3])
				{
					j = od[i][1];
					k = od[i][3];
				}
				else
				{
					j = od[i][3];
					k = od[i][1];
				}
				for (; j <= k; j++)
				{
					map[j][od[i][2]] = '-';
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '-' || map[i][j] == '|')
			{
				if (i - 1 >= 0 && (map[i - 1][j] == '|' || map[i - 1][j] == '-'))
				{
					if (j - 1 >= 0 && (map[i][j - 1] == '|' || map[i][j - 1] == '-'))
					{
						map[i][j] = '+';
					}
					else if (j + 1 < n && (map[i][j + 1] == '|' || map[i][j + 1] == '-'))
					{
						map[i][j] = '+';
					}
				}
				else if (i + 1 < m && (map[i + 1][j] == '|' || map[i + 1][j] == '-'))
				{
					if (j - 1 >= 0 && (map[i][j - 1] == '|' || map[i][j - 1] == '-'))
					{
						map[i][j] = '+';
					}
					else if (j + 1 < n && (map[i][j + 1] == '|' || map[i][j + 1] == '-'))
					{
						map[i][j] = '+';
					}
				}
			}
		}
	}
	for (int p = q - 1; p >= 0; p--)
	{
		if (od[p][0] == 1&&map[od[p][1]][od[p][2]]=='.')
		{
			map[od[p][1]][od[p][2]] = order[p];
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (map[i][j] == order[p])
					{
						int a = i;
						int b = j;
						while (a + 1 < m && map[a + 1][b] == '.')
						{
							map[a + 1][b] = map[a][b];
							a++;
						}
						while (b + 1 < n && map[a][b + 1] == '.')
						{
							map[a][b + 1] = map[a][b];
							b++;
						}
						while (a - 1 >= 0 && map[a - 1][b] == '.')
						{
							map[a - 1][b] = map[a][b];
							a--;
						}
						while (b - 1 >= 0 && map[a][b - 1] == '.')
						{
							map[a][b - 1] = map[a][b];
							b--;
						}
					}
				}
			}
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%c", map[j][i]);
		}
		printf("\n");
	}

	return 0;
}
