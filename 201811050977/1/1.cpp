#include<iostream>
using namespace std;
main()
{
	int fun1(int a,int b);
	void fun2(int& a,int& b);
	void fun3(int *a,int *b);
	int a,int b;
	int c;
	cout<<"输入a和b:";
	cin>>a>>b;
	c=fun1(a,b);
	cout<<"通过返回值实现:"<<c<<endl;
	fun2(a,b);
	fun3(&a,&b);
}
int fun1(int a,int b)//通过返回值将新数c传给主函数
{
	int c;
	c=1000*(a%10)+100*(b%10)+10*(a/10)+b/10;
	return c;
}
void fun2(int& a,int& b)//通过引用参数将新数传给主函数
{
	int c;
	c=1000*(a%10)+100*(b%10)+10*(a/10)+b/10;
	cout<<"通过引用参数实现:"<<c<<endl;
}
void fun3(int *a,int *b)//通过指针型参数将新数传给主函数
{
	int c;
	c=1000*((*a)%10)+100*((*b)%10)+10*((*a)/10)+(*b)/10;
	cout<<"通过指针型参数实现:"<<c<<endl;
}