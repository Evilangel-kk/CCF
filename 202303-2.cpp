#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n,m,k;
int t[N],c[N];
int mx;//��¼�������
//�жϵ�ǰ��ʱ����x�ܷ���������
bool jude(int x)
{
	int sum = 0;//��¼��Դ�ܺ�
	for(int i=1;i<=n;i++)
	{
		if(t[i]<x)continue;//������ʱС��x������Ҫ������Դ����
		sum+=(t[i]-x)*c[i];//sum��ֵ���иı�
		if(sum>m)return false;//�����Դ�ܺʹ���m������������
	}
	return true;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>c[i];
		mx = max(mx,t[i]);
	}
	int l=k,r=mx;//���֣�������Ϊl���ұ�Ϊmx
	while(l<=r)
	{
		int mid = (l+r)>>1;
		if(jude(mid)) r=mid-1;//������������С��Χ����
		else l = mid+1;
	}
	cout<<l<<endl;
	return 0;
}

