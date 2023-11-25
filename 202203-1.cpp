#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=0,k=0;
	cin>>n>>k;
	int a[n+1]={0};
	int b[n+1]={0};
	int count=0;
	for(int i=0;i<k;i++)
	{
		int x=0,y=0;
		cin>>x>>y;
		if(y==0)
		{
			a[x]=1;
			continue;
		}
		if(a[y]==0)
		{
			a[x]=1;
			count++;
		}
		else
		{
			a[x]=1;
		}
	}
	cout<<count;
	return 0;
}
