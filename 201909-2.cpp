#include<stdio.h>
#define N 1001
struct Tree
{
	int x = 0;
	int flag = 0;
	int m = 0;
	int num = 0;
};
int main()
{
	int n = 0;
	scanf("%d", &n);
	int D = 0;
	int T = 0;
	struct Tree tree[N];
	for (int i = 0; i < n; i++)
	{
		tree[i].x = i + 1;
		scanf("%d", &tree[i].m);
		scanf("%d", &tree[i].num);
		for (int j = 1; j < tree[i].m; j++)
		{
			int cnt = 0;
			scanf("%d", &cnt);
			if (cnt <= 0)
			{
				tree[i].num += cnt;
			}
			else
			{
				if (cnt < tree[i].num && tree[i].flag == 0)
				{
					D++;
					tree[i].flag = 1;
				}
				tree[i].num = cnt;
			}
		}
		T += tree[i].num;
	}
	int E = 0;
	for (int i = 0; i < n; i++)
	{
		if (tree[i].flag == 1 && tree[i + 1].flag == 1 && tree[i + 2].flag == 1)
		{
			E++;
		}
	}
	if (tree[n - 1].flag == 1 && tree[1].flag == 1 && tree[0].flag == 1)
	{
		E++;
	}
	if (tree[n - 2].flag == 1 && tree[n - 1].flag == 1 && tree[0].flag == 1)
	{
		E++;
	}
	printf("%d %d %d", T, D, E);
	return 0;
}
