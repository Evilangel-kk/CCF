#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e5+5;
ll a[N];

ll cal_sn(ll a1,ll an) {
	ll n=an-a1+1;
	return n*(a1+an)/2;
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,N;
	cin>>n>>N;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	a[0]=0;
	a[n+1]=N;
	ll r=N/(n+1);
	
	ll ans=0;
	for(int i=1;i<=n+1;++i) {
		ll left=a[i-1]/r,right=(a[i]-1)/r;
		if(left>=i-1 || right<=i-1) {
			ll original=(i-1)*(a[i]-a[i-1]);
			ll sum=cal_sn(left,right)*r;
			sum-=(a[i-1]%r)*left;
			sum-=(r-((a[i]-1)%r)-1)*right;
			ans+=abs(original-sum);
		}
		else {
			ll mid=i*r;
			ll original=(i-1)*(mid-a[i-1]);
			ll sum=cal_sn(left,(mid-1)/r)*r;
			sum-=(a[i-1]%r)*left;
			sum-=(r-((mid-1)%r)-1)*((mid-1)/r);
			ans+=abs(original-sum);
			
			original=(i-1)*(a[i]-mid);
			sum=cal_sn(mid/r,right)*r;
			sum-=(mid%r)*mid/r;
			sum-=(r-((a[i]-1)%r)-1)*right;
			ans+=abs(original-sum);
		}
	}
	cout<<ans<<endl;
	return 0;
}


