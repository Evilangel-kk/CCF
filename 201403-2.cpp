#include<stdio.h>
struct Windows
{
	int n;
	int f;
	int x1, y1, x2, y2;

} Windows;
struct Mouse
{
	int n;
	int x;
	int y;
} Mouse;
int main()
{
	int N = 0, M = 0;
	struct Windows windows[11];
	struct Mouse mouse[11];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d%d", &windows[i].x1, &windows[i].y1, &windows[i].x2, &windows[i].y2);
		windows[i].n = i + 1;
		windows[i].f = N - i;
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &mouse[i].x, &mouse[i].y);
		mouse[i].n = i + 1;
	}

	for (int i = 0; i < M; i++)
	{
		int j = 1;
		for (; j <= N; j++)
		{
			if (mouse[i].x >= windows[N - j].x1 && mouse[i].x <= windows[N - j].x2 && mouse[i].y >= windows[N - j].y1 && mouse[i].y <= windows[N - j].y2)
			{
				printf("%d\n", windows[N - j].n);
				struct Windows window = windows[N - j];
				struct Windows win[11];
				win[N - 1] = window;
				int o = N - 2;
				for (int k = N - 1; k >= 0; k--)
				{
					if (k != N - j)
					{
						win[o--] = windows[k];
					}
				}
				for (int k = 0; k < N; k++)
				{
					windows[k] = win[k];
					windows[k].f = N - k;
				}
				break;
			}
		}
		if (j == N + 1)
		{
			printf("IGNORED\n");
		}
	}
	return 0;
}
