//2020-12-21AM
//LZL
#include <iostream>
using namespace std;

int fun1(int a,int b) //��ֵ����
{
	int m,n,p,q,result;
	m=a%10;     //mΪa�ĸ�λ
	n=a/10;     //nΪa��ʮλ
	p=b%10;     //pΪb�ĸ�λ
	q=b/10;     //qΪb��ʮλ
	result=1000*m+100*p+10*n+q;
	return result;
}

int fun2(int &a,int &b) //���ô���
{
	int m,n,p,q,result;
	m=a%10;     //mΪa�ĸ�λ
	n=a/10;     //nΪa��ʮλ
	p=b%10;     //pΪb�ĸ�λ
	q=b/10;     //qΪb��ʮλ
	result=1000*m+100*p+10*n+q;
	return result;
}

int fun3(int *a,int *b) //ָ�봫��
{
	int m,n,p,q,result;
	m=*a%10;     //mΪa�ĸ�λ
	n=*a/10;     //nΪa��ʮλ
	p=*b%10;     //pΪb�ĸ�λ
	q=*b/10;     //qΪb��ʮλ
	result=1000*m+100*p+10*n+q;
	return result;
}

int main()
{
	int n1,n2,n3;
	int a,b;
	cout<<"����������������"<<endl;
	cin>>a>>b;
	n1=fun1(a,b);
	cout<<"��ֵ���ݵĽ��Ϊ��n1="<<n1<<endl;
	n2=fun2(a,b);
	cout<<"���ô��ݵĽ��Ϊ��n1="<<n1<<endl;
	n3=fun3(&a,&b);
	cout<<"ָ�봫�ݵĽ��Ϊ��n1="<<n1<<endl;
}
