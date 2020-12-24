//2020-12-21 PM
//LZL
//循环链表
#include<iostream>
using namespace std;

//对node建立结构体
typedef struct node//节点存放一个数据和指向下一个节点的指针
{
	int data;//数据域 
	struct node *pnext;//指针域，而且必须指向下一个同类型的节点的指针变量 struct node这个类型 
} Node;
 
Node *create(int n)//创建n个节点的循环链表，函数名前加*表示返回Node类型的指针 
{
	//先创建第1个节点
	Node *p,*q,*head;//p,q,head为指向struct node类型的指针变量
	int i;
	p = (Node *)malloc(sizeof(Node));//malloc函数为p动态分配内存空间 
	head = p;//头部也就是第一个节点 
	p->data = 1;
 
	for(i = 2;i<=n;i++)//再创建剩余节点
	{
		q = (Node *)malloc(sizeof(Node));//添加新节点所以重新分配内存空间，动态分配 
		q->data = i;
		p->pnext = q;//p在q前面所以p指向q 
		p = q;//这个时候p就得是q了，因为要往后创建 ，也就是说q就变成下一个节点的前驱 
	}
	p->pnext = head;//最后一个节点指向头部，形成循环链表
	return head;
}
void Josephus(Node *head,int k,int m)//从编号为k(1<=k<=n)的人开始报数，数到m的那个人出列；
{
	int i;
	Node *p = head,*tmp1;
	while(p->data != k)//p指向的节点data为k，先找到开始的数的那个位置 
		p = p->pnext;
	printf("离开此圈的猴子：");
	while(p->pnext != p)//模拟报数的过程直到剩下自己一个人的时候，这时只有一个他指向自己 
	{
		for(i=1;i<m;i++)//数到第m个 
		{
			tmp1 = p;//tmp1在这里用于记录出局人的前一个人 
			p = p->pnext;
		}
	
		printf("%d ",p->data);//输出出局的人的编号 
		//链表的精髓在下面这个部分
		tmp1->pnext= p->pnext;//只需改变指针指向的数据元素，就可以去掉出局的那个人，从他下一个位置的人开始数 
		free(p);//释放p指向的内存空间，彻底地把出局人的位置都清空他就不存在了 
		p = tmp1->pnext;//下一轮开始的位置 
 
	}
	printf("\n猴王是%d\n",p->data);//猴王
	free(p);//释放p指向的内存空间 
}
 
int main()
{
	int n,m,s;
	printf("please input the sum,interval，start position\n");
	scanf("%d %d %d",&n,&m,&s);
	Node *head = create(n);//调用函数创建含n个节点的循环链表	
	Josephus(head,s,m);//调用模拟Josephus的函数 
	return 0;
}