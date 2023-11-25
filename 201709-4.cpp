#include<stdio.h>
#define N 10001
struct Road
{
	int a=0;
	int b=0;
};
int main()
{
	int n=0,m=0;
	scanf("%d%d",&n,&m);
	int men[N]={0};
	struct Road r[N];
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&r[i].a,&r[i].b);
		//直接通信
		men[r[i].a-1]++;
		men[r[i].b-1]++;
	}
	for(int i=0;i<m-1;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(r[i].b==r[j].a)
			{
				men[r[i].a-1]++;
				men[r[j].b-1]++;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(men[i]>=n)
		{
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
	
}
