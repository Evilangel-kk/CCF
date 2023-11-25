#include<stdio.h>
int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	int a[31][31] = {0};
	int t[31][31]={0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2])
			{
				t[i][j] = t[i][j+1]=t[i][j+2]= 1;
			}
		}
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n - 2; i++)
		{
			if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j])
			{
				t[i][j]=t[i+1][j]=t[i+2][j]=1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(t[i][j])
			{
				a[i][j]=0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
