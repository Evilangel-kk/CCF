#include<bits/stdc++.h>
using namespace std;

bool stringMatch(string target, string search, int order)
{
	size_t targetLen = target.length();
	size_t searchLen = search.length();
	if (order == 1)
	{
		for (size_t i = 0; i <= targetLen - searchLen; i++)
		{
			size_t j;
			for (j = 0; j < searchLen; j++)
			{
				if (target[i + j] != search[j])
				{
					break;
				}
			}
			if (j == searchLen)
			{
				return true;
			}
		}
	}
	else
	{
		for (size_t i = 0; i <= targetLen - searchLen; i++)
		{
			size_t j;
			for (j = 0; j < searchLen; j++)
			{
				if ((target[i + j] != search[j])&&(target[i + j]-'A' != search[j]-'a')&&(target[i + j]-'a' != search[j]-'A'))
				{
					break;
				}
			}
			if (j == searchLen)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	string format;
	int order, n;
	cin >> format >> order >> n;
	
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (stringMatch(str, format, order))
		{
			cout << str << endl;
		}
	}
}
