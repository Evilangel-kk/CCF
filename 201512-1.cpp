#include<stdio.h>
#include<string.h>
int main()
{
	char c[1001]={'0'};
	scanf("%s",c);
	int l=strlen(c);
	int sum=0;
	for(int i=0;i<l;i++)
	{
		sum+=(c[i]-'0');
	}
	printf("%d",sum);
	return 0;
}
