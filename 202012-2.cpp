#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,Max=0,res;
int sum[N]={0};
set<int>st;
pair<int,int>pr[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		pr[i]=make_pair(a,b);
	}
	sort(pr+1,pr+n+1);//1.������
	for(int i=1;i<=n;i++)
		sum[i] =sum[i-1]+ pr[i].second;//2.��ҿ����ǰ׺�� 
	for(int i=1;i<=n;i++)
	{
		int a=pr[i].first;//ѡȡ��ֵ 
		if(st.count(a)) continue;//setȥ�� 
		st.insert(a);
		int yuce1 = sum[n]-sum[i-1];//���ڵ�����ֵʱ��Ӧͳ��Ԥ������Ϊ1�ĸ���
		int yuce0 = i-1-sum[i-1];//С����ֵʱ��Ӧͳ��Ԥ������Ϊ0�ĸ��� 
		int yuce = yuce1+ yuce0;//�ϼ�Ԥ����ȷ���� 
		if(yuce >= Max) {
			Max=yuce;
			res=a;
		}
	}
	cout<<res;
	return 0;
}

