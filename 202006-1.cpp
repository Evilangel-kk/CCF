#include<bits/stdc++.h>
using namespace std;
class Point
{
	public:
		int x;
		int y;
		char t;
		Point(int x, int y, char t)
		{
			this->x = x;
			this->y = y;
			this->t = t;
		}
};

class Line
{
	public:
		int a;
		int b;
		int c;
		Line(int a, int b, int c)
		{
			this->a = a;
			this->b = b;
			this->c = c;
		}

		int score(int x, int y)
		{
			if (a + b * x + c * y > 0)
			{
				return 1;
			}
			else if (a + b * x + c * y == 0)
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
};

void compare(Line l, vector<Point> p, int n)
{
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		int type = l.score(p[i].x, p[i].y);
		if (type == 0)
		{
			cout << "No" << endl;
			return;
		}
		if(a==0)
		{
			if(p[i].t=='A')
			{
				a=type;
			}
		}
		if(b==0)
		{
			if(p[i].t=='B')
			{
				b=type;
			}
		}
		if (p[i].t == 'A')
		{
			if(a!=0)
			{
				if(a!=type)
				{
					cout << "No" << endl;
					return;
				}
			}
		}
		else
		{
			if(b!=0)
			{
				if(b!=type)
				{
					cout << "No" << endl;
					return;
				}
			}
		}
	}
	cout << "Yes" << endl;
	return;
}

int main()
{
	int n=0,m=0;
	cin>>n>>m;
	vector<Point> p;
	for(int i=0;i<n;i++)
	{
		int x=0,y=0;
		char t;
		cin>>x>>y>>t;
		Point tp(x,y,t);
		p.push_back(tp);
	}
	for(int i=0;i<m;i++)
	{
		int a=0,b=0,c=0;
		cin>>a>>b>>c;
		Line l(a,b,c);
		compare(l,p,n);
	}
	return 0;
}
