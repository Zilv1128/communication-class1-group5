#define N 8
#include<iostream>
using namespace std;
struct students
{
	int number;
	int grade[3];
	int sum;
};
main()
{
	students student[N];
	students k;
	int i,j;
	for(i=0;i<N;i++)
	{
		cin>>student[i].number;
		for(j=0;j<3;j++)
		{
			cin>>student[i].grade[j];
		}
		student[i].sum=0;
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<3;j++)
			student[i].sum=student[i].sum+student[i].grade[j];
	}
	for(i=0;i<N-1;i++)//按总分从高到低排序
	{
		for(j=0;j<N-i-1;j++)
		{
			if(student[j].sum<student[j+1].sum)
			{
				k=student[j];
				student[j]=student[j+1];
				student[j+1]=k;
			}
		}
	}
	for(i=0;i<N-1;i++)//如果总分相同，再按语文成绩从高到低排序
	{
		for(j=0;j<N-i-1;j++)
		{
			if(student[j].sum==student[j+1].sum)
			{
				if(student[j].grade[0]<student[j+1].grade[0])
				{
					k=student[j];
					student[j]=student[j+1];
					student[j+1]=k;
				}
			}
		}
	}
	for(i=0;i<N-1;i++)//如果总分和语文成绩都相同，再规定学号小的同学排在前面
	{
		for(j=0;j<N-i;j++)
		{
			if(student[j].sum==student[j+1].sum&&student[j].grade[0]==student[j+1].grade[0])
			{
				if(student[j].number>student[j+1].number)
				{
					k=student[j];
					student[j]=student[j+1];
					student[j+1]=k;
				}
			}
		}
	}
	for(i=0;i<5;i++)
		cout<<student[i].number<<" "<<student[i].sum<<endl;
}