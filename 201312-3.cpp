#include <iostream>
#include <stdio.h>

int main()
{
	int x0, x1, n, a[1002], maxheight = 0, i, now, max = 0;
	scanf("%d", &n);
	for (i = 0; i <= n - 1; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > maxheight)
		{
			maxheight = a[i];
		}
	}
	for (i = 1; i <= maxheight; i++)//高度
	{
		x0 = 0;//左边界
		x1 = 0;//右边界
		do
		{
			x0 = x1;
			if (x0 == n)
			{
				break;
			}
			while (x1 < n && a[x1] >= i) //可以装下
			{
				x1++;
			}
			now = (x1 - x0) * i;
			if (now > max)
			{
				max = now;
			}
			if (x1 < n && a[x1] < i)
			{
				x1++;
			}
		}
		while (1);
	}
	printf("%d", max);
	return 0;
}
