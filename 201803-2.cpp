#include<bits/stdc++.h>
using namespace std;
class Ball
{
	private:
		int x;
		int d = 1;
	public:
		void set_x(int x)
		{
			this->x = x;
		};
		void set_d(int d)
		{
			this->d = d;
		};
		int get_x()
		{
			return this->x;
		}
		int get_d()
		{
			return this->d;
		}
		void change_d()
		{
			this->d *= -1;
		}
		void move()
		{
			this->x += this->d;
		}
};

void changeD(Ball balls[], int n, int l)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (balls[i].get_x() == balls[j].get_x())
			{
				balls[i].change_d();
				balls[j].change_d();
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (balls[i].get_x() <= 0)
		{
			balls[i].set_x(0);
			balls[i].change_d();
		}
		else if (balls[i].get_x() >= l)
		{
			balls[i].set_x(l);
			balls[i].change_d();
		}
	}
}

int main()
{
	int n = 0, l = 0, t = 0;
	cin >> n >> l >> t;
	Ball balls[n];
	for (int i = 0; i < n; i++)
	{
		int p = 0;
		cin >> p;
		balls[i].set_x(p);
	}
	while (t--)
	{
		for (int i = 0; i < n; i++)
		{
			balls[i].move();
		}
		changeD(balls, n, l);
	}
	for (int i = 0; i < n; i++)
	{
		cout << balls[i].get_x() << " ";
	}
}
