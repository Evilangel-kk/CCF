/* CCF201609-2 �𳵹�Ʊ */
 
#include <iostream>
#include <map>
 
using namespace std;
 
const int N = 20;
const int NUM = 5;
 
int main()
{
    map<int,int> m;
    int n, v, start, end;
 
    // ��ʼ������ƱԴ
    for(int i=1; i<=N; i++)
        m[i] = NUM;
 
    // �������ݣ����䳵Ʊ��������
    cin >> n;
    for(int i=1; i<=n; i++) {
        // �������ݣ������Ʊ����
        cin >> v;
 
        // ���䳵Ʊ��ͬһ�ŷ��䣩����������
        for(map<int,int>::iterator it=m.begin(); it!=m.end(); it++) {
            if(it->second >= v) {
                // ������
                start = (it->first - 1) * NUM + 1 + (NUM - it->second);
                end = start + v - 1;
                for(int j=start; j<=end; j++) {
                    if(j != start)
                        cout << " ";
                    cout << j;
                }
                cout << endl;
 
                // ����Ʊ���Ѿ�������ϵ��ţ�ɾ��
                if(it->second == v)
                    m.erase(it);
                else
                    it->second = it->second - v;
 
                v = 0;
                break;
            }
        }
 
        // ���䳵Ʊ�����ŷ��䣩����������
        bool nofirstflag = false;
        while(v > 0) {
            for(map<int,int>::iterator it=m.begin(); it!=m.end(); it++) {
                if(it->second >= v) {
                    // ������
                    start = (it->first - 1) * NUM + 1 + (NUM - it->second);
                    end = start + v - 1;
                    for(int j=start; j<=end; j++) {
                        if(nofirstflag)
                            cout << " ";
                        cout << j;
                        nofirstflag = true;
                    }
 
                    // ����Ʊ���Ѿ�������ϵ��ţ�ɾ��
                    if(it->second == v)
                        m.erase(it);
                    else
                        it->second = it->second - v;
 
                    v = 0;
                    break;
                } else {
                    // ������
                    start = (it->first - 1) * NUM + 1 + (NUM - it->second);
                    end = start + it->second - 1;
                    for(int j=start; j<=end; j++) {
                        if(nofirstflag)
                            cout << " ";
                        cout << j;
                        nofirstflag = true;
                    }
 
                    v = v - it->second;
 
                    // ����Ʊ���Ѿ�������ϵ��ţ�ɾ��
                    m.erase(it);
                }
            }
            cout << endl;
        }
    }
 
    return 0;
}
