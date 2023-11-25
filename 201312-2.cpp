#include<stdio.h>
int main()
{
	int n1,n2,n3;
	char n4;
	scanf("%d-%d-%d-%c",&n1,&n2,&n3,&n4);
	
	int n5=n1;
	int n6=n2;
	int n7=n3;
	int a[9]={0};
	a[0]=n1;
	a[1]=n2/100;
	n2%=100;
	a[2]=n2/10;
	a[3]=n2%10;
	a[4]=n3/10000;
	n3%=10000;
	a[5]=n3/1000;
	n3%=1000;
	a[6]=n3/100;
	n3%=100;
	a[7]=n3/10;
	a[8]=n3%10;
	int text=0;
	for(int i=0;i<9;i++)
	{
		text+=a[i]*(i+1);
	}
	text%=11;
	int t=n4-'0';
	if(text==10)
	{
		if(n4=='X')
		{
			printf("Right");
		}
		else
		{
			printf("%d-%d-%d-X",n5,n6,n7);	
		}
	}
	
	else
	{
		if(t==text)
		{
			printf("Right");
		}
		else
		{
			printf("%d-%d-%d-%d",n5,n6,n7,n4);
		}
	}
	return 0;
}
