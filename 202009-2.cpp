#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=0,k=0,t=0;
	cin>>n>>k>>t;
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int out1=0;// ����Σ����������
	int out2=0;// ��Σ������������
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
					// ��һ�ν���Σ������
					out1++;
					flag=true;
				}
				else
				{
					if(count==k&&f==false)
					{
						// �ڶ�����������
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
