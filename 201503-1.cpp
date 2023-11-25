#include<stdio.h>
int main()
{
	int n=0,m=0;
	scanf("%d%d",&n,&m);
	int a[10][10]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",a[j][i]);
		}
		printf("\n");
	}
	return 0;
}
