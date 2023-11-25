#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	int a[1001]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0;
	for(int i=0;i<n-2;i++)
	{
		if((a[i]-a[i+1])*(a[i+1]-a[i+2])<0)
		{
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
