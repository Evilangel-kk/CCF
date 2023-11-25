#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int b[101] = {0};
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	int amax[101] = {0};
	int amin[101] = {0};
	amax[0] = b[0];
	amin[0] = b[0];
	for(int i=1;i<n;i++)
	{
		if(b[i]==b[i-1])
		{
			amax[i]=amax[i-1];
			amin[i]=0;
		}
		else
		{
			amax[i]=amin[i]=b[i];
		}
	}
	
	int max=0;
	int min=0;
	
	for(int i=0;i<n;i++)
	{
		max+=amax[i];
		min+=amin[i];
	}
	
	printf("%d\n%d\n",max,min);


	return 0;
}
