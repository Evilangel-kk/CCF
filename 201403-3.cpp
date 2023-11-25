#include <bits/stdc++.h>
using namespace std;

const int N = 256;

char delimiter[] = " ";

void spilt(vector<string>& v, char *s, char *t)
{
	char *sp;
	sp = strtok(s, t);
	while(sp) {
		v.push_back(sp);
		sp = strtok(NULL, t);
	}
}

void mygetline(char *pc)
{
	char c;
	while((c=getchar()) != '\n' && c !=EOF)
		*pc++ = c;
	*pc = '\0';
}

int main()
{
	string format;
	char s[N+1];
	int n;
	
	// 输入数据：格式和整数n
	cin >> format >> n;
	getchar();
	
	// 输入n行命令行进行处理
	for(int i=1; i<=n; i++) {
		vector<string> sv;
		map<string, string> m;
		
		// 输入命令行
		mygetline(s);
		
		// 切分命令行：命令和各个参数分开
		spilt(sv, s, delimiter);
		
		// 处理各个参数，放入map变量ｍ中
		for(int j=1; j<(int)sv.size(); j++) {
			if(sv[j].size() == 2 && sv[j][0] == '-') { // 判断是否是选项，选项则处理
				// 选项在格式中未找到则出错结束
				int pos = format.find(sv[j][1]);
				if(pos == -1)
					break;
				
				// 选项未出现过则添加
				if(m.find(sv[j]) == m.end())
					m[sv[j]] = "";
				
				// 更新参数：后出现优先
				if(format[pos+1] == ':' && j+1 < (int)sv.size()) {
					m[sv[j]] = sv[j+1];
					j++;
				}
			} else
				break;
		}
		
		// 输出结果
		cout << "Case " << i << ":";
		for(map<string,string>::iterator iter=m.begin(); iter!=m.end(); iter++) {
			cout << " " << iter->first;
			if(iter->second != "")
				cout << " " << iter->second;
		}
		cout << endl;
	}
	
	return 0;
}
