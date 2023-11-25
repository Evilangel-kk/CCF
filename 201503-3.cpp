#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a,b,c;
int y1,y2;
int monthes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

//�ж��ǲ�������
int isyear(int year)
{
	if((year%4==0 && year%100!=0) || year%400==0)
	{
		monthes[1]=29;
		return 1;
	}
	else
	{
		monthes[1]=28;
		return 0;
	}
	
}
//��������
int countdays(int year1, int year2)
{
	int days = 0;
	for(int i=year1; i<year2; i++)
	{
		if(isyear(i))
			days += 366;
		else
			days += 365;
	}
	return days;
} 

int main()
{
	cin >> a >> b >> c >> y1 >> y2;	
	int num = countdays(1850,y1);
	for(int i=y1; i<=y2; i++)
	{
		int days = 0;
		//���㵽a��1��֮ǰһ�������� 
		days += num;
		days += countdays(y1,i);
		isyear(i);
		//����ǰa-1���µ����� 
		for(int j=0; j<a-1; j++)
			days += monthes[j];
		//����a��1�������ڼ�
		//cout << days << endl;
		int weeks = (days) % 7 + 2;
		if(weeks == 8)
			weeks = 1;
		//���a��1�յ�����С������c
		int daynum;
		if(c >= weeks)
			//a��(c-week+1)��������c 
			daynum = (c-weeks+1)+(b-1)*7;
		else  //a��(8-week+c)��������c 
			daynum = (1-weeks+c)+b*7;
		if(daynum <= monthes[a-1])
			printf("%d/%02d/%02d\n",i,a,daynum); 
		else
			cout << "none" << endl;
	}
	return 0;
} 

