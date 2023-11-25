#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int a[1001] = {0};
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	int k = 0;
	while (k != n)
	{
		int max = 0;
		int min = 0;
		int flag = a[k];
		for (int i = 0; i < n; i++)
		{
			if (a[i] < flag)
			{
				min++;
			}
			else if (a[i] > flag)
			{
				max++;
			}
		}

		if (min == max)
		{
			break;
		}
		else
		{
			k++;
		}
	}
	if (k != n)
		printf("%d", a[k]);
	else
		printf("-1");
	return 0;
}
