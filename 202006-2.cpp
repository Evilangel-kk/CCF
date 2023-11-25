#include<bits/stdc++.h>
using namespace std;

class U
{
	public:
		long index;
		long value;
		U(long index, long value)
		{
			this->index = index;
			this->value = value;
		}
};

int main()
{
	long n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	vector<U> u;
	long sum = 0;
	for (long i = 0; i < a; i++)
	{
		long ti = 0, tv = 0;
		cin >> ti >> tv;
		U tu(ti, tv);
		u.push_back(tu);
	}
	long k = 0;
	for (long j = 0; j < b; j++)
	{
		long ti = 0, tv = 0;
		cin >> ti >> tv;
		while (k < a)
		{
			if (ti == u[k].index)
			{
				sum += tv * u[k].value;
				k++;
			}
			else if (ti < u[k].index)
			{
				break;
			}
			else
			{
				k++;
			}
		}
	}
	cout << sum;
	return 0;
}
