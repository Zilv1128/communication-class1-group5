#define MAX 100
#include<iostream>
using namespace std;
int level(char p)//规定运算符优先级
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
    number[*numberTop]=temp;//运算后的结果放到数值栈栈顶
}
int fun(char str[])
{
    char Symbol[MAX];
    int SymbolTop=-1;
    int numberTop=-1;
    int number[MAX];
    int y=0;
    int i=0;
    Symbol[++SymbolTop]='@'; //先把@入到符号栈中,就不用判断栈是否空了
    while(str[i])//先遍历该字符串
	{
        if(str[i]<='9'&&str[i]>='0')//数字
		{
			while(str[i]<='9'&&str[i]>='0')
			{
                y=str[i]-'0';
                i++;
            }
            number[++numberTop]=y;//将数字压入栈中
        }
        else if((str[i]>'9'||str[i]<'0')&&str[i]!='('&&str[i]!=')')//不是数字和左右括号
		{
            while(level(str[i])<=level(Symbol[SymbolTop]))//该运算符的优先级小于等于栈顶符号的优先级
			{
				cal(number,&numberTop,Symbol,&SymbolTop);
			}
            Symbol[++SymbolTop]=str[i];
            i++;
        }
        else if(str[i]=='(')//遇见左括号直接入栈
		{
            Symbol[++SymbolTop] = '(';
            i++;
        }
        else if(str[i]==')')//遇到右括号
		{
            while(Symbol[SymbolTop]!='(')//栈顶符号不是左括号
			{
				cal(number,&numberTop,Symbol,&SymbolTop);
            }
            SymbolTop--;//栈顶符号出栈
            i++;
        }
    }
    while(Symbol[SymbolTop]!='@')//符号栈还没空
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