#include<iostream>
using namespace std;
main()
{
	int fun1(int a,int b);
	void fun2(int& a,int& b);
	void fun3(int *a,int *b);
	int a,int b;
	int c;
	cout<<"����a��b:";
	cin>>a>>b;
	c=fun1(a,b);
	cout<<"ͨ������ֵʵ��:"<<c<<endl;
	fun2(a,b);
	fun3(&a,&b);
}
int fun1(int a,int b)//ͨ������ֵ������c����������
{
	int c;
	c=1000*(a%10)+100*(b%10)+10*(a/10)+b/10;
	return c;
}
void fun2(int& a,int& b)//ͨ�����ò�������������������
{
	int c;
	c=1000*(a%10)+100*(b%10)+10*(a/10)+b/10;
	cout<<"ͨ�����ò���ʵ��:"<<c<<endl;
}
void fun3(int *a,int *b)//ͨ��ָ���Ͳ�������������������
{
	int c;
	c=1000*((*a)%10)+100*((*b)%10)+10*((*a)/10)+(*b)/10;
	cout<<"ͨ��ָ���Ͳ���ʵ��:"<<c<<endl;
}