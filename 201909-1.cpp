#include<stdio.h>
#define N 1001
#define M 1001
struct Order
{
	int num = 0;
	int sum = 0;
	int d = 0;
};
int main()
{
	int n, m;
	int sum = 0;
	scanf("%d%d", &n, &m);
	struct Order od[N];
	for (int i = 0; i < n; i++)
	{
		od[i].num = i + 1;
		scanf("%d", &od[i].sum);
		for (int j = 0; j < m; j++)
		{
			int cnt;
			scanf("%d", &cnt);
			od[i].sum += cnt;
			od[i].d += cnt;
		}
		od[i].d = -od[i].d;
		sum += od[i].sum;
	}
	int num = 0;
	int x;
	for (int i = 0; i < n; i++)
	{
		if (od[i].d > num)
		{
			num = od[i].d;
			x = i + 1;
		}
	}
	printf("%d %d %d", sum, x, num);
	return 0;
}
