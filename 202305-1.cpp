#include<bits/stdc++.h>
using namespace std;

class Step{
public:
	string jumian[8];
	int times=1;
	void init(){
		for(int i=0;i<8;i++){
			cin>>jumian[i];
		}
	}
	void compare(Step s){
		for(int i=0;i<8;i++){
			if(this->jumian[i]!=s.jumian[i]){
				return;
			}
		}
		this->times++;
	}
};

int main(){
	int n;
	cin>>n;
	vector<Step> ss;
	for(int i=0;i<n;i++){
		Step s;
		s.init();
		ss.push_back(s);
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			ss[i].compare(ss[j]);
		}
	}
	for(int i=0;i<n;i++){
		cout<<ss[i].times<<endl;
	}
}
