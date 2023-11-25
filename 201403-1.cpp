#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	int a[501]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]+a[j]==0)
			{
				sum++;
				break;
			}
		}
	}
	printf("%d",sum);
	return 0;
}
