#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int a[n][n] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	int y[n * n] = {0};
	int p = 0;
	int q = 0;
	int k = 0;
	y[k++] = a[p][q];
	while (k < n * n)
	{
		if (q + 1 < n)
		{
			q++;
			y[k++] = a[p][q];
		}
		else
		{
			p++;
			y[k++] = a[p][q];
		}
		while (p + 1 < n && q - 1 >= 0)
		{
			p++;
			q--;
			y[k++] = a[p][q];
		}
		if (q == 0 && p + 1 < n)
		{
			p++;
			y[k++] = a[p][q];
		}
		else
		{
			q++;
			y[k++] = a[p][q];
		}
		while (p - 1 >= 0 && q + 1 < n)
		{
			p--;
			q++;
			y[k++] = a[p][q];
		}
	}
	for (int i = 0; i < n * n; i++)
	{
		cout << y[i] << " ";
	}
	return 0;
}
