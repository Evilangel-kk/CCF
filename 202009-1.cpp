#include<stdio.h>
struct Text{
	int num=0;
	int x=0;
	int y=0;
	int d=0;
}Text[201];
int main()
{
	int n=0,x=0,y=0;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&Text[i].x,&Text[i].y);
		Text[i].num=i+1;
		Text[i].d=(Text[i].x-x)*(Text[i].x-x)+(Text[i].y-y)*(Text[i].y-y);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(Text[j].d>Text[j+1].d)
			{
				struct Text Tmp=Text[j];
				Text[j]=Text[j+1];
				Text[j+1]=Tmp;
			}
		}
	}
	printf("%d\n%d\n%d\n",Text[0].num,Text[1].num,Text[2].num);
	return 0;
}
