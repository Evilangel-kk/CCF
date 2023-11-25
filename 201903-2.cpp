#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	int a[101][4]={0};
	char c[101][3]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d%c%d%c%d%c%d",&a[i][0],&c[i][0],&a[i][1],&c[i][1],&a[i][2],&c[i][2],&a[i][3]);
	}
	int sum[101]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(c[i][j]=='x')
			{
				a[i][j+1]=a[i][j]*a[i][j+1];
				a[i][j]=0;
			}
			else if(c[i][j]=='/')
			{
				a[i][j+1]=a[i][j]/a[i][j+1];
				a[i][j]=0;
			}
		}
		for(int j=0;j<3;j++)
		{
			if(c[i][j]=='-')
			{
				if(a[i][j+1]==0)
				{
					if(j!=2&&(c[i][j+1]=='x'||c[i][j+1]=='/'))
					{
						a[i][j+1]=a[i][j+2];
						a[i][j+2]=0;
					}
				}
				a[i][j+1]=a[i][j]-a[i][j+1];
				a[i][j]=0;
			}
		}
		sum[i]=a[i][0]+a[i][1]+a[i][2]+a[i][3];
		if(sum[i]==24)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	
	return 0;
}
