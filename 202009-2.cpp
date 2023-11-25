#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=0,k=0,t=0;
	cin>>n>>k>>t;
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int out1=0;// 经过危险区域人数
	int out2=0;// 在危险区域逗留人数
	for(int i=0;i<n;i++)
	{
		int x,y;
		bool flag=false;
		bool f=false;
		int count=0;
		for(int j=0;j<t;j++)
		{
			cin>>x>>y;
			if(x>=x1&&x<=x2&&y>=y1&&y<=y2)
			{
				count++;
				if(!flag)
				{
					// 第一次进入危险区域
					out1++;
					flag=true;
				}
				else
				{
					if(count==k&&f==false)
					{
						// 第二次连续进入
						count=0;
						out2++;
						f=true;
					}
				}
			}
			else
			{
				count=0;
			}
		}
	}
	cout<<out1<<endl;
	cout<<out2<<endl;
}
