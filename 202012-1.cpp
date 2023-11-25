#include<stdio.h>
struct Men{
	int w;
	int score;
	int r;
}Men[100001];

int main()
{
	int n;
	int sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&Men[i].w,&Men[i].score);
		Men[i].r=Men[i].w*Men[i].score;
		sum+=Men[i].r;
	}
	if(sum<0)
	{
		sum=0;
	}
	printf("%d\n",sum);
	
	return 0;
}
