#include<stdio.h>
struct Teacher
{
	int w = 0;
	int s = 0;
	int c = 0;
	int b = 0;
};
int main()
{
	int n = 0, k = 0;
	scanf("%d%d", &n, &k);
	int a[1001] = {0};
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	struct Teacher t[1001];
	int start = 10001;
	int end = 0;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d%d", &t[i].w, &t[i].s, &t[i].c);
		t[i].b = t[i].c + t[i].s;
		if (t[i].s < start)
		{
			start = t[i].s;
		}
		if (end < t[i].b)
		{
			end = t[i].b;
		}
	}
	for (int i = start; i <= end; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (t[j].s == i)
			{
				for (int k = 0; k < n; k++)
				{
					if (a[k] == t[j].w)
					{
						a[k] = 0;
						break;
					}
				}
			}
			else if (t[j].b == i)
			{
				for (int k = 0; k < n; k++)
				{
					if (a[k] == 0)
					{
						a[k] = t[j].w;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;

}
