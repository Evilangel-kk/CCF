//#include<stdio.h>
//#include<math.h>
//
//int Interest(int a[],int n)
//{
//	int n0=0,n1=0,n2=0,n3=0;
//
//	for(int i=0;i<n;i++)
//	{
//		if(a[i]==0)
//		{
//			n0=1;
//		}
//		else if(a[i]==1)
//		{
//			n1=1;
//		}
//		else if(a[i]==2)
//		{
//			n2=1;
//		}
//		else if(a[i]==3)
//		{
//			n3=1;
//		}
//	}
//	if(n0==0||n1==0||n2==0||n3==0)
//	{
//		return 0;
//	}
//
//	int flag0=0;
//	int flag1=0;
//	int flag2=0;
//	int flag3=0;
//	
//	for(int i=0;i<n;i++)
//	{
//		if(flag2==0&&flag3==0&&a[i]==3)
//		{
//			return 0;
//		}
//		if(flag2==0&&flag3==0&&a[i]==2)	//第一次出现2
//		{
//			flag2=1;
//			continue;
//		}
//		if(flag2==1&&flag3==0&&a[i]==3)	//第一次出现3
//		{
//			flag3=1;
//			continue;
//		}
//		if(flag2==1&&flag3==1&&a[i]==2)
//		{
//			return 0;
//		}
//		if(flag0==0&&flag1==0&&a[i]==1)
//		{
//			return 0;
//		}
//		if(flag0==0&&flag1==0&&a[i]==0)	//第一次出现0
//		{
//			flag0=1;
//			continue;
//		}
//		if(flag0==1&&flag1==0&&a[i]==1)	//第一次出现1
//		{
//			flag1=1;
//			continue;
//		}
//		if(flag0==1&&flag1==1&&a[i]==0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int n=4;
////	scanf("%d",&n);
//	while(n<=1000)
//	{
//		
//	
//	int a[n]={0};
//	a[0]=2;
//	long long num=0;
//	int mod=1000000007;
//	while(1)
//	{
//		a[n-1]++;
//		for(int i=n-1;i>0;i--)
//		{
//			if(a[i]==4)
//			{
//				a[i]=0;
//				a[i-1]++;
//			}
//		}
//		if(a[0]==2&&(a[n-1]==1||a[n-1]==3))
//		{
//			num+=Interest(a,n);
//			num%=mod;
//		}
//		if(a[0]==3)
//		{
//			break;
//		}
//	}
//	printf("     n:%d\t",n);
//	printf("number:%d\n",num);
//	n++;
//	}
//}
#include <bits/stdc++.h>

using namespace std;
const int mod = 1000000007;
typedef long long ll;
const int N = 1e3 + 5;
int n;
ll dp[N][10]; //注意long long
int main()
{
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;//0---0 1(2)3 ---首位只能放2 
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % mod;  //1---(0)1(2)3 --s[i-1][1]*2能放0或2 s[i-1][0]只能放0 
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % mod;//2---01(2)(3) --s[i-1][2]只能放3， s[i-1][0]只能放3 
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][3] * 2) % mod; //3---(0)(1)(2)3-- s[i-1][3]*2可以放2 1  s[i-1][1] 存在02只能放1 
		dp[i][4] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] * 2) % mod;//4---(0)1(2)(3)  1.可以放03 2.少0 3.少3 
		dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5] * 2) % mod;//5---(0)(1)(2)(3) 1.可以放13 2.少1 3。少3 
	}
	cout << dp[n][5] << endl;
	return 0;
}


