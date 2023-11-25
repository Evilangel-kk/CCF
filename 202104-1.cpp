#include<stdio.h>
int main()
{
	int n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	int a[501][501]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int b[257]={0};
	int flag=0;
	while(flag<l)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(flag==a[i][j])
				{
					b[flag]++;
				}
			}
		}
		flag++;
	}
	for(int i=0;i<l;i++)
	{
		printf("%d ",b[i]);
	}
	
	return 0;
}
