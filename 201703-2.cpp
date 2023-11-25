#include<stdio.h>
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a[1001] = {0};
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	int lot = 0;
	int step = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &lot, &step);
		int k = 0;
		for (; k < n; k++)
		{
			if (a[k] == lot)
			{
				break;
			}
		}
		if (step > 0)
		{
			for (int j = 0; j < step; j++)
			{
				int tmp = a[k + j];
				a[k + j] = a[k + 1 + j];
				a[k + 1 + j] = tmp;
			}
		}
		else
		{
			step = -step;
			for (int j = 0; j < step; j++)
			{
				int tmp = a[k - j];
				a[k - j] = a[k - 1 - j];
				a[k - 1 - j] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
