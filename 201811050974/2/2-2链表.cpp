//2020-12-21 PM
//LZL
//ѭ������
#include<iostream>
using namespace std;

//��node�����ṹ��
typedef struct node//�ڵ���һ�����ݺ�ָ����һ���ڵ��ָ��
{
	int data;//������ 
	struct node *pnext;//ָ���򣬶��ұ���ָ����һ��ͬ���͵Ľڵ��ָ����� struct node������� 
} Node;
 
Node *create(int n)//����n���ڵ��ѭ������������ǰ��*��ʾ����Node���͵�ָ�� 
{
	//�ȴ�����1���ڵ�
	Node *p,*q,*head;//p,q,headΪָ��struct node���͵�ָ�����
	int i;
	p = (Node *)malloc(sizeof(Node));//malloc����Ϊp��̬�����ڴ�ռ� 
	head = p;//ͷ��Ҳ���ǵ�һ���ڵ� 
	p->data = 1;
 
	for(i = 2;i<=n;i++)//�ٴ���ʣ��ڵ�
	{
		q = (Node *)malloc(sizeof(Node));//����½ڵ��������·����ڴ�ռ䣬��̬���� 
		q->data = i;
		p->pnext = q;//p��qǰ������pָ��q 
		p = q;//���ʱ��p�͵���q�ˣ���ΪҪ���󴴽� ��Ҳ����˵q�ͱ����һ���ڵ��ǰ�� 
	}
	p->pnext = head;//���һ���ڵ�ָ��ͷ�����γ�ѭ������
	return head;
}
void Josephus(Node *head,int k,int m)//�ӱ��Ϊk(1<=k<=n)���˿�ʼ����������m���Ǹ��˳��У�
{
	int i;
	Node *p = head,*tmp1;
	while(p->data != k)//pָ��Ľڵ�dataΪk�����ҵ���ʼ�������Ǹ�λ�� 
		p = p->pnext;
	printf("�뿪��Ȧ�ĺ��ӣ�");
	while(p->pnext != p)//ģ�ⱨ���Ĺ���ֱ��ʣ���Լ�һ���˵�ʱ����ʱֻ��һ����ָ���Լ� 
	{
		for(i=1;i<m;i++)//������m�� 
		{
			tmp1 = p;//tmp1���������ڼ�¼�����˵�ǰһ���� 
			p = p->pnext;
		}
	
		printf("%d ",p->data);//������ֵ��˵ı�� 
		//����ľ����������������
		tmp1->pnext= p->pnext;//ֻ��ı�ָ��ָ�������Ԫ�أ��Ϳ���ȥ�����ֵ��Ǹ��ˣ�������һ��λ�õ��˿�ʼ�� 
		free(p);//�ͷ�pָ����ڴ�ռ䣬���׵ذѳ����˵�λ�ö�������Ͳ������� 
		p = tmp1->pnext;//��һ�ֿ�ʼ��λ�� 
 
	}
	printf("\n������%d\n",p->data);//����
	free(p);//�ͷ�pָ����ڴ�ռ� 
}
 
int main()
{
	int n,m,s;
	printf("please input the sum,interval��start position\n");
	scanf("%d %d %d",&n,&m,&s);
	Node *head = create(n);//���ú���������n���ڵ��ѭ������	
	Josephus(head,s,m);//����ģ��Josephus�ĺ��� 
	return 0;
}