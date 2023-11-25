#include<stdio.h>
int main()
{
	int n,N;
	scanf("%d", &n);
	scanf("%d", &N);
	int sum = 0;
	int A[n + 1]={0};
	int f[N]={0};
	A[0] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i + 1]);
	}
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		if (i < A[n])
		{
			for (; j < n; j++)
			{
				if (A[j] <= i && A[j+1] > i)
				{
					f[i] = j;
					break;
				}
			}
		}
		else
		{
			f[i]=j + 1;
		}
	}
	for(int i=0;i<N;i++)
	{
		int num=1;
		while(1)
		{
			if(f[i]==f[i+1] && i+1<N)
			{
				num++;
				i++;
			}
			else
			{
				break;
			}
		}
		
		sum=sum+num*f[i];
	}
	
	printf("%d\n",sum);
	
	return 0;
}
