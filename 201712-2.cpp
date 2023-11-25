#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	int a[n] = {0};
	int num = 1;
	int q = 0;
	int p = n;
	while (p > 1)
	{
		while (a[q] == 1)
		{
			if (q + 1 < n)
			{
				q++;
			}
			else
			{
				q = 0;
			}
		}
		if (num % k == 0 || num % 10 == k)
		{
			a[q] = 1;
			p--;
		}
		num++;
		q++;
		if (q == n)
		{
			q = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			cout << i + 1;
		}
	}
}
