#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;//����
double i;//����������
int main()
{
	cin>>n;
	cin>>i;
	double ans = 0;//�洢���
	cin>>ans;//�������0�������
	for(int k=1;k<=n;k++)
	{
		ans = ans*(1+i);//���ݹ�ʽ���м���
		int x;
		cin>>x;
		ans+=x;//��Ҫ���Ǽ�������
	}
	ans =ans*pow((1+i), -n);//���㵱ǰ��ֵ
	cout<<ans<<endl;
	return 0;
}

