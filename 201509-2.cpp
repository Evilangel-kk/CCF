#include<stdio.h>
int day_culcut(int y, int m, int d)
{
	int num = 0;
	int a, b, c;
	if (m <= 2)
	{
		switch (m)
		{
			case 1:
				num = d;
				break;
			case 2:
				num = 31 + d;
				break;
		}
	}
	else
	{
		a = y % 4;
		b = y % 100;
		c = y % 400;
		if ((a == 0 && b != 0) || (b == 0 && c == 0))
		{
			switch (m)
			{
				case 3:
					num = 60 + d;
					break;
				case 4:
					num = 91 + d;
					break;
				case 5:
					num = 121 + d;
					break;
				case 6:
					num = 152 + d;
					break;
				case 7:
					num = 182 + d;
					break;
				case 8:
					num = 213 + d;
					break;
				case 9:
					num = 244 + d;
					break;
				case 10:
					num = 274 + d;
					break;
				case 11:
					num = 305 + d;
					break;
				case 12:
					num = 335 + d;
					break;
				default:
					break;
			}
		}
		else
		{
			switch (m)
			{
				case 3:
					num = 59 + d;
					break;
				case 4:
					num = 90 + d;
					break;
				case 5:
					num = 120 + d;
					break;
				case 6:
					num = 151 + d;
					break;
				case 7:
					num = 181 + d;
					break;
				case 8:
					num = 212 + d;
					break;
				case 9:
					num = 243 + d;
					break;
				case 10:
					num = 273 + d;
					break;
				case 11:
					num = 304 + d;
					break;
				case 12:
					num = 334 + d;
					break;
				default:
					break;
			}
		}
	}
	return num;
}
int main()
{
	int y = 0, d = 0;
	scanf("%d%d", &y, &d);
	for (int i = 1; i <= 12; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		{
			for (int j = 1; j <= 31; j++)
			{
				if (d == day_culcut(y, i, j))
				{
					printf("%d\n%d\n", i, j);
				}
			}
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11)
		{
			for (int j = 1; j <= 30; j++)
			{
				if (d == day_culcut(y, i, j))
				{
					printf("%d\n%d\n", i, j);
				}
			}
		}
		else if (i == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
		{
			for (int j = 1; j <= 29; j++)
			{
				if (d == day_culcut(y, i, j))
				{
					printf("%d\n%d\n", i, j);
				}
			}
		}
		else
		{
			for (int j = 1; j <= 28; j++)
			{
				if (d == day_culcut(y, i, j))
				{
					printf("%d\n%d\n", i, j);
				}
			}
		}
	}
	return 0;
}
