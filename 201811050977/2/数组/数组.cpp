#define N 50
#include<iostream>
using namespace std;
main()
{
	void fun(int m,int n);
	int m,n;
	cout<<"����m��n:";
	cin>>m>>n;
	fun(m,n);
}
void fun(int m,int n)
{
	int a[N];
	int i,j,sum;//i��ʾ���ӵı�ţ�j��ʾ�����ڼ�����sum��ʾȦ��ʣ����ӵ�����
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
			if(j==n)//������n��
			{
				a[i]=0;//��ʾ�ú����뿪Ȧ
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
			i=1;//��ͷ��ʼ��
		}
	}
	for(i=1;i<=m;i++)
	{
		if(a[i]==1)
			cout<<"����Ϊ:"<<i<<"��"<<endl;
	}
}

/*
//��ͨ������
#include<stdio.h>
#define N 1000
int main(void)
{
	int monkey[N];
	int index = 0; //���±�
	int i = 1;
	int counter; //��¼��������
	int num;
    scanf("%d",&num); 
    counter = num; 
	while(counter > 1)
    {
		if(monkey[index] != -1)
		{
			if(i == 3)
            {
				monkey[index] = -1;  //������3�ĺ����˳�Ȧ������־Ϊ-1
				counter--; 
            }
			i++;
			if(i > 3) //���i>3�� �ٻص�1 
            {
				i = 1;
            }
        }
		index++;
		if(index >= num)
        {
			index = 0;  //�ص�0 
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
//�õݹ飨ǿ��һ����
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