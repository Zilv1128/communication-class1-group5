//2020-12-21AM
//LZL
#include <iostream>
using namespace std;

int fun1(int a,int b) //按值传递
{
	int m,n,p,q,result;
	m=a%10;     //m为a的个位
	n=a/10;     //n为a的十位
	p=b%10;     //p为b的个位
	q=b/10;     //q为b的十位
	result=1000*m+100*p+10*n+q;
	return result;
}

int fun2(int &a,int &b) //引用传递
{
	int m,n,p,q,result;
	m=a%10;     //m为a的个位
	n=a/10;     //n为a的十位
	p=b%10;     //p为b的个位
	q=b/10;     //q为b的十位
	result=1000*m+100*p+10*n+q;
	return result;
}

int fun3(int *a,int *b) //指针传递
{
	int m,n,p,q,result;
	m=*a%10;     //m为a的个位
	n=*a/10;     //n为a的十位
	p=*b%10;     //p为b的个位
	q=*b/10;     //q为b的十位
	result=1000*m+100*p+10*n+q;
	return result;
}

int main()
{
	int n1,n2,n3;
	int a,b;
	cout<<"请输入两个整数："<<endl;
	cin>>a>>b;
	n1=fun1(a,b);
	cout<<"按值传递的结果为：n1="<<n1<<endl;
	n2=fun2(a,b);
	cout<<"引用传递的结果为：n1="<<n1<<endl;
	n3=fun3(&a,&b);
	cout<<"指针传递的结果为：n1="<<n1<<endl;
}
