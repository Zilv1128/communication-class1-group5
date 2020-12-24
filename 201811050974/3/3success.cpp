#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct student
{
	int chinese; //语文成绩
	int math;    //数学成绩
	int english; //英语成绩
	int sore;    //总成绩
	int sn;     //学号
};
student grade[100]={0};
bool compare(student x,student y)
{
	if(x.sore>y.sore)
		return true;
	else if(x.sore==y.sore&&x.chinese>y.chinese)
		return true;
	else if(x.sore==y.sore&&x.chinese==y.chinese&&x.sn<y.sn)
		return true;
	else 
		return false;	
}
int main()
{
	int num,i;
	cout<<"请输入学生个数:"<<endl;
	cin>>num;
	cout<<"请输入学生成绩:"<<endl;
	for(i=1;i<=num;i++)
	{
		cin>>grade[i].chinese>>grade[i].math>>grade[i].english;
		grade[i].sore=grade[i].chinese+grade[i].math+grade[i].english;
		grade[i].sn=i;
	}
	sort(grade+1,grade+num+1,compare);
	for(i=1;i<=5;i++)
	{
		cout<<grade[i].sn<<' '<<grade[i].sore<<endl;
	}
	return 0;
}
