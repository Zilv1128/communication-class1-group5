#include <iostream>
using namespace std;
struct Monkey
{
    int num;  //���ӵı��
    struct Monkey *next; //��һֻ����
};
main()
{
    int m,n,i,j,king;
    Monkey *head,*p1,*p2;
	cout<<"����m��n:";
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
            p1=new Monkey;//p1�������ӵ�
            p1->num=i+1;
            p2->next=p1;
            p2=p1;
        }
        p2->next=head;
        p1=head;
        for(i=1;i<m;i++)//ɾ��m-1�����
        {
            for(j=1;j<n-1;j++)//������n-1��
			{
                p1=p1->next;
			}
            p2=p1->next;
            cout<<"��"<<i<<"��"<<p2->num<<"���뿪Ȧ"<<endl;
            p1->next=p2->next;
            p1=p2->next;//��һ�������������
            delete p2;//ɾ���뿪Ȧ�ĺ���
        }
        king=p1->num;
        delete p1;
    }
    cout<<"����Ϊ:"<<king<<"��"<<endl;
}
