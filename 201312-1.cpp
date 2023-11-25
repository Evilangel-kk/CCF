#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	int a[1001][2]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i][0]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j][0]==a[i][0])
			{
				a[i][1]++;
				a[j][0]=0;
			}
		}
	}
	int max=0;
	int num=0;
	for(int i=0;i<n;i++)
	{
		if(max<a[i][1])
		{
			max=a[i][1];
			num=a[i][0];
		}
		else if(max==a[i][1])
		{
			if(num>a[i][0])
			{
				num=a[i][0];
			}
		}
	}
	printf("%d\n",num);
	return 0;
}
