#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[1001]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int res=0;
	int max=0;
	for(int i=0;i<n-1;i++)
	{
		res=a[i+1]-a[i];
		if(res<0)
		{
			res=-res;
		}
		if(res>max)
		{
			max=res;
		}
	}
	printf("%d\n",max);
	return 0;
}
