#include<stdio.h>
#define MAX 101
struct Rectangle
{
	int x1, y1, x2, y2;
};
int main()
{
	int map[MAX][MAX] = {0};
	int n;
	scanf("%d", &n);
	struct Rectangle rag[MAX];
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &rag[i].x1, &rag[i].y1, &rag[i].x2, &rag[i].y2);
		for (int j = rag[i].x1; j < rag[i].x2; j++)
		{
			for (int k = rag[i].y1; k < rag[i].y2; k++)
			{
				map[j][k] = 1;
			}
		}
	}
	int sum = 0;
	for (int x = 0; x < MAX; x++)
	{
		for (int y = 0; y < MAX; y++)
		{
			if (map[x][y] == 1)
			{
				sum++;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
