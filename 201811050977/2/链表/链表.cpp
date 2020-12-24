#include <iostream>
using namespace std;
struct Monkey
{
    int num;  //猴子的编号
    struct Monkey *next; //下一只猴子
};
main()
{
    int m,n,i,j,king;
    Monkey *head,*p1,*p2;
	cout<<"输入m和n:";
    cin>>m>>n;
    if(n==1)
    {
		king=m;
    }
    else
    {
        p1=p2=new Monkey;
        head=p1;
        p1->num=1;
        for(i=1;i<m;i++)
        {
            p1=new Monkey;//p1是新增加的
            p1->num=i+1;
            p2->next=p1;
            p2=p1;
        }
        p2->next=head;
        p1=head;
        for(i=1;i<m;i++)//删除m-1个结点
        {
            for(j=1;j<n-1;j++)//数到第n-1个
			{
                p1=p1->next;
			}
            p2=p1->next;
            cout<<"第"<<i<<"轮"<<p2->num<<"号离开圈"<<endl;
            p1->next=p2->next;
            p1=p2->next;//下一轮数数的新起点
            delete p2;//删除离开圈的猴子
        }
        king=p1->num;
        delete p1;
    }
    cout<<"大王为:"<<king<<"号"<<endl;
}
