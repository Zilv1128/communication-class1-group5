#define N 50
#include<iostream>
using namespace std;
main()
{
	void fun(int m,int n);
	int m,n;
	cout<<"输入m和n:";
	cin>>m>>n;
	fun(m,n);
}
void fun(int m,int n)
{
	int a[N];
	int i,j,sum;//i表示猴子的编号，j表示数到第几个，sum表示圈中剩余猴子的数量
	sum=m;
	for(i=1;i<=m;i++)
	{
		a[i]=1;
	}
	i=1;j=1;
	while(sum>1)
	{
		if(a[i]==1)
		{
			if(j==n)//数到第n个
			{
				a[i]=0;//表示该猴子离开圈
				sum--;
			}
			j++;
			if(j>n)
			{
				j=1;
			}
		}
		i++;
		if(i>m)
		{
			i=1;//从头开始数
		}
	}
	for(i=1;i<=m;i++)
	{
		if(a[i]==1)
			cout<<"大王为:"<<i<<"号"<<endl;
	}
}

/*
//普通用数组
#include<stdio.h>
#define N 1000
int main(void)
{
	int monkey[N];
	int index = 0; //当下标
	int i = 1;
	int counter; //记录猴子总数
	int num;
    scanf("%d",&num); 
    counter = num; 
	while(counter > 1)
    {
		if(monkey[index] != -1)
		{
			if(i == 3)
            {
				monkey[index] = -1;  //将数到3的猴子退出圈，并标志为-1
				counter--; 
            }
			i++;
			if(i > 3) //如果i>3了 再回到1 
            {
				i = 1;
            }
        }
		index++;
		if(index >= num)
        {
			index = 0;  //回到0 
        }
	}
	for(i = 0; i < num; i++)
    {
		if(monkey[i] != -1)
        {
			printf("%d",i+1);
        }
    }
	return 0;
}
*/
/*
//用递归（强的一批）
#include<stdio.h>
int fun(int n)
{
	if(n == 1)
		return0;
	return (fun(n-1)+3)%n;
}
int main(void)
{
	int num;
	scanf("%d",&num);
	printf("%d",fun(num)+1);
	return 0;
}
*/