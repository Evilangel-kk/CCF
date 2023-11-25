#include<stdio.h>
struct Reader
{
	int num=0;
	int cnt=0;
};
int main()
{
	int n=0;
	scanf("%d",&n);
	struct Reader reader[1001];
	int a[1001]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		reader[i].num=i+1;
		reader[i].cnt=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]==reader[j].num)
			{
				reader[j].cnt++;
				printf("%d ",reader[j].cnt);
				break;
			}
		}
	}
	return 0;
}
