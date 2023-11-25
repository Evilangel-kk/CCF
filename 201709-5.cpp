#include<stdio.h>
#define N 100001
struct Order
{
	int opt = 0;
	int l = 0;
	int r = 0;
	int v = 0;
};
int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	int a[N] = {0};
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	struct Order od[N];
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &od[i].opt);
		if (od[i].opt == 1)
		{
			scanf("%d%d%d", &od[i].l, &od[i].r, &od[i].v);
			for (int j = od[i].l - 1; j <= od[i].r - 1; j++)
			{
				if (a[j] >= od[i].v && a[j] % od[i].v == 0)
				{
					a[j] /= od[i].v;
				}
			}
		}
		else
		{
			scanf("%d%d", &od[i].l, &od[i].r);
			long long sum = 0;
			for (int j = od[i].l - 1; j <= od[i].r - 1; j++)
			{
				sum += a[j];
			}
			printf("%lld\n", sum);
		}
	}
	return 0;
}
