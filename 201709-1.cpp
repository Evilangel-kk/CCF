#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a=n/50;
	n%=50;
	int b=n/30;
	n%=30;
	int c=n/10;
	int sum=a*5+a*2+b*3+b+c;
	printf("%d",sum);
	return 0;
}
