#include<bits/stdc++.h>
using namespace std;

int u[4] = {-1, 1, 0, 0};
int v[4] = {0, 0, 1, -1};

class Point
{
	public:
		int x;
		int y;
		int h;
		Point(int x, int y)
		{
			this->x = x;
			this->y = y;
			this->h = 0;
		}
		void inch()
		{
			this->h++;
		}
		bool ishuz()
		{
			if (this->h == 4)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

class Hsz
{
	public:
		int x;
		int y;
		int s;

		Hsz(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
		void set_s(int s)
		{
			this->s = s;
		}
		int get_s()
		{
			return this->s;
		}
		void incs()
		{
			this->s++;
		}
};

bool checkP(int i, vector<Point> p, int n)
{
	int x = p[i].x;
	int y = p[i].y;

	for (int k = 0; k < 4; k++)
	{
		for (int q = 0; q < n; q++)
		{
			if (q != i)
			{
				if (p[q].x == x + u[k] && p[q].y == y + v[k])
				{
					p[i].inch();
					break;
				}
			}
		}
	}
	if (p[i].ishuz())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int scoreP(vector<Point> p, Hsz h, int n)
{
	int s=0;
	int a[4] = {-1, 1, -1, 1};
	int b[4] = {-1, -1, 1, 1};
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < n; i++)
		{
			if (p[i].x == h.x + a[k] && p[i].y == h.y+b[k])
			{
				s++;
			}
		}
	}
	return s;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<Point> p;
	vector<Hsz> h;
	for (int i = 0; i < n; i++)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		Point tp(x, y);
		p.push_back(tp);
	}
	int a[5] = {0};
	for (int i = 0; i < n; i++)
	{
		int x = p[i].x;
		int y = p[i].y;
		if (checkP(i, p, n))
		{
			Hsz th(x, y);
			int tmp=scoreP(p,th,n);
			a[tmp]++;
			th.set_s(tmp);
			h.push_back(th);
		}
	}
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
