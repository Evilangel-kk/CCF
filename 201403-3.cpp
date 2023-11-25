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
	
	// �������ݣ���ʽ������n
	cin >> format >> n;
	getchar();
	
	// ����n�������н��д���
	for(int i=1; i<=n; i++) {
		vector<string> sv;
		map<string, string> m;
		
		// ����������
		mygetline(s);
		
		// �з������У�����͸��������ֿ�
		spilt(sv, s, delimiter);
		
		// �����������������map��������
		for(int j=1; j<(int)sv.size(); j++) {
			if(sv[j].size() == 2 && sv[j][0] == '-') { // �ж��Ƿ���ѡ�ѡ������
				// ѡ���ڸ�ʽ��δ�ҵ���������
				int pos = format.find(sv[j][1]);
				if(pos == -1)
					break;
				
				// ѡ��δ���ֹ������
				if(m.find(sv[j]) == m.end())
					m[sv[j]] = "";
				
				// ���²��������������
				if(format[pos+1] == ':' && j+1 < (int)sv.size()) {
					m[sv[j]] = sv[j+1];
					j++;
				}
			} else
				break;
		}
		
		// ������
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
