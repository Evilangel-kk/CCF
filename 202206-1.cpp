#include<bits/stdc++.h>
using namespace std;
vector<double> f;
void fa(double avg, vector<double> a, int n)
{
	double da = 0;
	for (int i = 0; i < n; i++)
	{
		da += pow(avg - a[i], 2);
	}
	da /= n;
	da = sqrt(da);
	for (int i = 0; i < n; i++)
	{
		f.push_back((a[i] - avg) / da);
	}
}

int main()
{
	int n = 0;
	cin >> n;
	vector<double> a;
	
	double all = 0;
	for (int i = 0; i < n; i++)
	{
		double t = 0;
		cin >> t;
		a.push_back(t);
		all += t;
	}
	double avg = all / n;
	fa(avg, a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%f\n",f[i]);
	}
	return 0;
}
