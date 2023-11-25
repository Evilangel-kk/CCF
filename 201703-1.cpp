#include<stdio.h>
int main()
{
	int n=0,k=0;
	scanf("%d%d",&n,&k);
	int a[1001]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int num=0;
	int sum=0;
	int i=0;
	for(;i<n;i++)
	{
		sum+=a[i];
		if(sum>=k)
		{
			sum=0;
			num++;
		}
	}
	if(sum!=0)
	{
		num++;
	}
	printf("%d",num);
	return 0;
}
