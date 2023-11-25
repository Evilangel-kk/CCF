#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct node
{
	bool is_obj; //这个节点是否是对象
	string val; //字符串的值
	map <string, node> obj; //对象
};

map <string, node> res; //只能用map，不能用unordered_map

void workBlank(string &str) //去除多余的空格
{
	string t;
	for (int i = 0; i < str.size(); i ++)
	{
		if (str[i] != ' ') t += str[i]; //只要不是空格的字符就要
	}
	str = t;
}

map <string, node> Object(string str, int &i)
{
	map <string, node> obj;

	if (str[i] == '}') //如果是空对象
	{
		i++;
		return obj;
	}

	for (; i < str.size();)
	{
		if (str[i] == '"') //这一定是键值对的key的第一个引号
		{
			//处理key
			int j = i + 1; //指向"后一位
			string key;
			while (j < str.size() && str[j] != '"') //结束是j等于"
			{
				if (str[j] != '\\') key += str[j];
				else key += str[ ++ j]; //加上\后面那位
				j ++;
			}

			//处理value
			i = j + 2; //i指向冒号后面一位
			if (str[i] == '"') //值为string
			{
				int j = i + 1; //“后的第一个字符
				string value;
				while (j < str.size() && str[j] != '"') //结束是j等于"
				{
					if (str[j] != '\\') value += str[j];
					else value += str[ ++ j]; //加上\后面那位
					j ++;
				}
				obj[key].is_obj = false;
				obj[key].val = value;
				i = j + 1; //i指向"后一位，可能是，或者}
			}
			else //值为对象
			{
				i ++; //i指向{后一位进入递归
				obj[key].is_obj = true;
				obj[key].obj = Object(str, i); //返回时j指向}后一位，可能是，或者}
			}

			if (str[i] == ',')
			{
				i ++; //i指向"
				continue;
			}
			else //只有可能是}
			{
				i ++; //返回时j指向}后一位，可能是，或者}
				//cout << str[i];
				return obj;
			}
		}
	}
}

queue <string> pushin(string str)
{
	queue <string> res;
	for (int i = 0; i < str.size();)
	{
		int k = str.find('.', i);
		if (k == -1) //后面没有.
		{
			res.push(str.substr(i));
			break;
		}
		else
		{
			res.push(str.substr(i, k - i));
			i = k + 1; //i指向.后一位
			continue;
		}
	}
	return res;
}

int main()
{
	int n, m;
	cin >> n >> m;

	string str;
	getchar();
	while (n --)
	{
		string t;
		getline(cin, t);
		str += t; //将所有内容拼接成一行
	}

	workBlank(str); //去除多余的空格

	//cout << str;
	int pos = 1;
	res = Object(str, pos); //递归处理对象，从{下一位开始

	//查询
	while (m --)
	{
		cin >> str;
		queue <string> q = pushin(str); //根据.进行分隔询问

		map <string, node> tmp1 = res;
		while (q.size())
		{
			string key = q.front();
			if (tmp1.count(key) == 0)
			{
				//for (auto x : tmp1) cout << x.first << endl;
				puts("NOTEXIST");
				break;
			}
			if (q.size() == 1) //查询的最后一项
			{
				if (tmp1[key].is_obj) puts("OBJECT");
				else cout << "STRING" << " " << tmp1[key].val << endl;
			}
			else //更新查询的对象
			{
				if (tmp1[key].is_obj == false) //如果该value不是对象，说明查询失败，因为这项不是最后一项，一定是对象
				{
					puts("NOTEXIST");
					break;
				}
				else
				{
					map <string, node> tmp2 = tmp1[key].obj;
					tmp1 = tmp2;
				}
			}
			q.pop();
		}
	}
	return 0;
}

