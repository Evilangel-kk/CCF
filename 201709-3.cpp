#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct node
{
	bool is_obj; //����ڵ��Ƿ��Ƕ���
	string val; //�ַ�����ֵ
	map <string, node> obj; //����
};

map <string, node> res; //ֻ����map��������unordered_map

void workBlank(string &str) //ȥ������Ŀո�
{
	string t;
	for (int i = 0; i < str.size(); i ++)
	{
		if (str[i] != ' ') t += str[i]; //ֻҪ���ǿո���ַ���Ҫ
	}
	str = t;
}

map <string, node> Object(string str, int &i)
{
	map <string, node> obj;

	if (str[i] == '}') //����ǿն���
	{
		i++;
		return obj;
	}

	for (; i < str.size();)
	{
		if (str[i] == '"') //��һ���Ǽ�ֵ�Ե�key�ĵ�һ������
		{
			//����key
			int j = i + 1; //ָ��"��һλ
			string key;
			while (j < str.size() && str[j] != '"') //������j����"
			{
				if (str[j] != '\\') key += str[j];
				else key += str[ ++ j]; //����\������λ
				j ++;
			}

			//����value
			i = j + 2; //iָ��ð�ź���һλ
			if (str[i] == '"') //ֵΪstring
			{
				int j = i + 1; //����ĵ�һ���ַ�
				string value;
				while (j < str.size() && str[j] != '"') //������j����"
				{
					if (str[j] != '\\') value += str[j];
					else value += str[ ++ j]; //����\������λ
					j ++;
				}
				obj[key].is_obj = false;
				obj[key].val = value;
				i = j + 1; //iָ��"��һλ�������ǣ�����}
			}
			else //ֵΪ����
			{
				i ++; //iָ��{��һλ����ݹ�
				obj[key].is_obj = true;
				obj[key].obj = Object(str, i); //����ʱjָ��}��һλ�������ǣ�����}
			}

			if (str[i] == ',')
			{
				i ++; //iָ��"
				continue;
			}
			else //ֻ�п�����}
			{
				i ++; //����ʱjָ��}��һλ�������ǣ�����}
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
		if (k == -1) //����û��.
		{
			res.push(str.substr(i));
			break;
		}
		else
		{
			res.push(str.substr(i, k - i));
			i = k + 1; //iָ��.��һλ
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
		str += t; //����������ƴ�ӳ�һ��
	}

	workBlank(str); //ȥ������Ŀո�

	//cout << str;
	int pos = 1;
	res = Object(str, pos); //�ݹ鴦����󣬴�{��һλ��ʼ

	//��ѯ
	while (m --)
	{
		cin >> str;
		queue <string> q = pushin(str); //����.���зָ�ѯ��

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
			if (q.size() == 1) //��ѯ�����һ��
			{
				if (tmp1[key].is_obj) puts("OBJECT");
				else cout << "STRING" << " " << tmp1[key].val << endl;
			}
			else //���²�ѯ�Ķ���
			{
				if (tmp1[key].is_obj == false) //�����value���Ƕ���˵����ѯʧ�ܣ���Ϊ��������һ�һ���Ƕ���
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

