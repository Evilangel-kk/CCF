#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k;
	cin>>n>>m>>k;	
	int Qleft[200002] = {0}, Qright[200002] = {0};
	for (int i = 0; i < n; ++i) {
		int t, c;
		cin>>t>>c;
		if (k <= t) {
			int l = max(0, t - c - k + 1);
			int r = t - k + 1;  // 左闭右开
			Qleft[l]++;
			Qright[r]++;
		}
	}
	for (int i = 1; i < 200002; ++i) {  // 是200002！！ 不要写错了
		Qleft[i] += Qleft[i - 1];
		Qright[i] += Qright[i - 1];
	}
	for (int i = 0; i < m; ++i) {
		int q;
		cin>>q;
		int ans = Qleft[q] - Qright[q];
		cout<<ans<<endl;
	}
	return 0;
}
