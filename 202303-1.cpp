#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=0;
	int a=0,b=0;
	cin>>n>>a>>b;
	int size=0;
	for(int i=0;i<n;i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1<0)
		{
			x1=0;
		}
		else if(x1>a)
		{
			x1=a;
		}
		if(y1<0)
		{
			y1=0;
		}
		else if(y1>b)
		{
			y1=b;
		}
		if(x2>a)
		{
			x2=a;
		}
		else if(x2<0)
		{
			x2=0;
		}
		if(y2>b)
		{
			y2=b;
		}
		else if(y2<0)
		{
			y2=0;
		}
		size+=(x2-x1)*(y2-y1);
	}
	cout<<size;
	return 0;
}
