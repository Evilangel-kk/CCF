#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a,b,c;
int y1,y2;
int monthes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

//判断是不是闰年
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
//计算天数
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
		//计算到a月1日之前一共多少天 
		days += num;
		days += countdays(y1,i);
		isyear(i);
		//计算前a-1个月的天数 
		for(int j=0; j<a-1; j++)
			days += monthes[j];
		//计算a月1日是星期几
		//cout << days << endl;
		int weeks = (days) % 7 + 2;
		if(weeks == 8)
			weeks = 1;
		//如果a月1日的星期小于星期c
		int daynum;
		if(c >= weeks)
			//a月(c-week+1)日是星期c 
			daynum = (c-weeks+1)+(b-1)*7;
		else  //a月(8-week+c)日是星期c 
			daynum = (1-weeks+c)+b*7;
		if(daynum <= monthes[a-1])
			printf("%d/%02d/%02d\n",i,a,daynum); 
		else
			cout << "none" << endl;
	}
	return 0;
} 

