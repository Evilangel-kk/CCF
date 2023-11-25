#include<stdio.h>
#include<math.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	int a[10001]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(abs(a[i]-a[j])==1)
			{
				sum++;
			}
		}
	}
	printf("%d",sum);
	return 0;
}
