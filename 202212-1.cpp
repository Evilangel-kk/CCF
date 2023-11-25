#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;//年数
double i;//银行年利率
int main()
{
	cin>>n;
	cin>>i;
	double ans = 0;//存储结果
	cin>>ans;//先输入第0年的收入
	for(int k=1;k<=n;k++)
	{
		ans = ans*(1+i);//根据公式进行计算
		int x;
		cin>>x;
		ans+=x;//不要忘记加上收入
	}
	ans =ans*pow((1+i), -n);//计算当前价值
	cout<<ans<<endl;
	return 0;
}

