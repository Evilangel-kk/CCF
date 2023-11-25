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
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
