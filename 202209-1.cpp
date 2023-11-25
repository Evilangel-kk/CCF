#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0;
	long m=0;
	cin>>n>>m;
	long a[n+1]={0};
	long b[n+1]={0};
	long c[n+1]={0};
	c[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i]*c[i-1];
	}
	long tmp=0;
	for(int i=1;i<=n;i++)
	{
		if((m%c[i]-tmp)!=0)
		{
			b[i]=(m%c[i]-tmp)/c[i-1];
		}
		else
		{
			b[i]=0;
		}
		tmp=m%c[i];
		cout<<b[i]<<" ";
	}
}
