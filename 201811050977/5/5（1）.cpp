#define MAX 100
#include<iostream>
using namespace std;
int level(char p)//�涨��������ȼ�
{
    int temp;
    switch (p)
    {
	case '*':
    case '/':temp=3;break;
    case '+':
    case '-':temp=2;break;
    case '(':temp=1;break;
    case '@':temp=-1;break;
    }
    return temp;
}

void cal(int number[],int* numberTop,char Symbol[],int* SymbolTop)
{
	char operation;
	int value1,value2,temp;
    operation=Symbol[*SymbolTop];
    (*SymbolTop)--;
    value1=number[*numberTop];
    (*numberTop)--;
    value2=number[*numberTop];
    (*numberTop)--;
    switch (operation)
    {
	case '+':temp=value2+value1;break;
    case '-':temp=value2-value1;break;
    case '*':temp=value2*value1;break;
    case '/':temp=value2/value1;break;
    }
    (*numberTop)++;
    number[*numberTop]=temp;//�����Ľ���ŵ���ֵջջ��
}
int fun(char str[])
{
    char Symbol[MAX];
    int SymbolTop=-1;
    int numberTop=-1;
    int number[MAX];
    int y=0;
    int i=0;
    Symbol[++SymbolTop]='@'; //�Ȱ�@�뵽����ջ��,�Ͳ����ж�ջ�Ƿ����
    while(str[i])//�ȱ������ַ���
	{
        if(str[i]<='9'&&str[i]>='0')//����
		{
			while(str[i]<='9'&&str[i]>='0')
			{
                y=str[i]-'0';
                i++;
            }
            number[++numberTop]=y;//������ѹ��ջ��
        }
        else if((str[i]>'9'||str[i]<'0')&&str[i]!='('&&str[i]!=')')//�������ֺ���������
		{
            while(level(str[i])<=level(Symbol[SymbolTop]))//������������ȼ�С�ڵ���ջ�����ŵ����ȼ�
			{
				cal(number,&numberTop,Symbol,&SymbolTop);
			}
            Symbol[++SymbolTop]=str[i];
            i++;
        }
        else if(str[i]=='(')//����������ֱ����ջ
		{
            Symbol[++SymbolTop] = '(';
            i++;
        }
        else if(str[i]==')')//����������
		{
            while(Symbol[SymbolTop]!='(')//ջ�����Ų���������
			{
				cal(number,&numberTop,Symbol,&SymbolTop);
            }
            SymbolTop--;//ջ�����ų�ջ
            i++;
        }
    }
    while(Symbol[SymbolTop]!='@')//����ջ��û��
	{
        cal(number,&numberTop,Symbol,&SymbolTop);
    }
    return number[numberTop];
}
main()
{
    char str[MAX];
    int result;
	cin>>str;
    result=fun(str);
	cout<<result<<endl;
}