#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a[100001] = { 0 };
	float b[3] = { 0.0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	b[0] = a[0];
	b[1] = a[n - 1];
	int flag = 0;
	if (n % 2 == 1)
	{
		b[2] = a[n / 2];
	}
	else
	{
		b[2] = a[n / 2 - 1] + a[n / 2];
		b[2] /= 2;
		if ((a[n / 2 - 1] + a[n / 2]) % 2 == 1)
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		if (b[1] > b[0])
		{
			if (b[1] > b[2])
			{
				if (b[2] > b[0])
				{
					printf("%.0f %.1f %.0f", b[1], b[2], b[0]);
				}
				else
				{
					printf("%.0f %.0f %.1f", b[1], b[0], b[2]);
				}
			}
			else
			{
				printf("%.1f %.0f %.0f", b[2], b[1], b[0]);
			}
		}
		else
		{
			if (b[1] > b[2])
			{
				printf("%.0f %.0f %.1f", b[0], b[1], b[2]);
			}
			else
			{
				if (b[2] > b[0])
				{
					printf("%.1f %.0f %.0f", b[2], b[0], b[1]);
				}
				else
				{
					printf("%.0f %.1f %.0f", b[0], b[2], b[1]);
				}
			}
		}
	}
	else
	{
		if (b[1] > b[0])
		{
			if (b[1] > b[2])
			{
				if (b[2] > b[0])
				{
					printf("%.0f %.0f %.0f", b[1], b[2], b[0]);
				}
				else
				{
					printf("%.0f %.0f %.0f", b[1], b[0], b[2]);
				}
			}
			else
			{
				printf("%.0f %.0f %.0f", b[2], b[1], b[0]);
			}
		}
		else
		{
			if (b[1] > b[2])
			{
				printf("%.0f %.0f %.0f", b[0], b[1], b[2]);
			}
			else
			{
				if (b[2] > b[0])
				{
					printf("%.0f %.0f %.0f", b[2], b[0], b[1]);
				}
				else
				{
					printf("%.0f %.0f %.0f", b[0], b[2], b[1]);
				}
			}
		}
	}

	return 0;
}
