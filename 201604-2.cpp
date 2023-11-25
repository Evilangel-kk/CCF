#include<stdio.h>
struct Blocks
{
	int x;
	int y;
};
int main()
{
	int map[15][10] = {0};
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	int block[4][4] = {0};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &block[i][j]);
		}
	}
	int start = 0;
	scanf("%d", &start);
	struct Blocks blocks[4];
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[i][j] == 1)
			{
				blocks[k].x=i;
				blocks[k].y=j+start-1;
				k++;
			}
		}
	}

	int flag = 1;
	while (flag)
	{
		int i = 0;
		for (; i < 4; i++)
		{
			if (map[blocks[i].x + 1][blocks[i].y] == 1||blocks[i].x==14)
			{
				flag = 0;
				break;
			}
		}
		if (i == 4)
		{
			for (int j = 0; j < 4; j++)
			{
				blocks[j].x++;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		map[blocks[i].x][blocks[i].y] = 1;
	}

	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			printf("%d ", map[x][y]);
		}
		printf("\n");
	}
	return 0;
}
