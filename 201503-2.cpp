#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int a[10001][2] = {0};
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		int f = 0;
		scanf("%d", &f);
		int j = 0;
		for (; j < i; j++)
		{
			if (f == a[j][0])
			{
				a[j][1]++;
				break;
			}
		}
		if (j == i)
		{
			a[k++][0] = f;
		}
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if ((a[i][1] < a[j][1]) || (a[i][1] == a[j][1] && a[i][0] > a[j][0]))
			{
				int m = a[i][0];
				int p = a[i][1];
				a[i][0] = a[j][0];
				a[i][1] = a[j][1];
				a[j][0] = m;
				a[j][1] = p;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d %d\n", a[i][0], a[i][1] + 1);
	}
	return 0;
}
