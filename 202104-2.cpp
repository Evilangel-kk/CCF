#include<bits/stdc++.h>

using namespace std;
int n,l,r,t,a[601][601],sum[601][601];
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>l>>r>>t;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>a[i][j];
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
	
	int res=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
		int max_i = min(n,i+r);
		int max_j = min(n,j+r);
		int min_i = max(0,i-r-1);
		int min_j = max(0,j-r-1);
		double tmp = double(sum[max_i][max_j] - sum[min_i][max_j] - sum[max_i][min_j] + sum[min_i][min_j]) / double((max_i - min_i) * (max_j - min_j));
		if(tmp<=t)
			res++;
	}
	cout<<res;
	return 0;
}
