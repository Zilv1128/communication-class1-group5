#include "iostream"
#include "stack"
//定义了两个栈
using namespace std;
 
int Priority(char ch)   //定义优先级
{
	// 左括号'(' > 乘除 '*' = '/' > 加减 '+' = '-' > 右括号')'
    switch(ch)
    {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
 
int main()
{
    stack<char> s_opt;   //符号栈
    stack<int> s_num;    //数据栈
    char opt[1024] = {0};
    int i=0,tmp=0,num1=0,num2=0;
 
    cout<<"Please input: "<<endl;
    cin>>opt;
 
    while(opt[i]!='\0'||s_opt.empty()!=true)
    {
		if(opt[i]>='0'&&opt[i]<='9')
		{
			tmp=tmp*10+opt[i]-'0';
			i++;
			if(opt[i]>'9'||opt[i]<'0')
			{
				s_num.push(tmp);   //压栈
				tmp = 0;
			}    
		}
        else
        {
			//当遇到符号)入栈并且栈顶元素是(,进行符号匹配
            if((opt[i]==')')&&(s_opt.top()=='('))  
            {
                s_opt.pop();  //符号出栈
                i++;
                continue;
            }
            //符号栈为空 ||符号优先级高于栈顶符号 ||栈顶符号是(并且下一个符号不是)
			//符号入栈
            if((s_opt.empty())==true||(Priority(opt[i])>Priority(s_opt.top()))||
              (s_opt.top()=='('&&(opt[i]!=')')))
            {
                s_opt.push(opt[i]);//符号压栈
                i++;
                continue;
            }
			//符号集为空并且符号栈不为空 || 输入右括号并且栈顶元素不为左括号 ||输入符号的优先级
			//出栈  + - * / 
            if( ((opt[i]=='\0')&&(s_opt.empty()!=true))||( (opt[i]==')')&&(s_opt.top()!='(') )||
                (Priority(opt[i])<= Priority(s_opt.top())) )
            {
                char ch = s_opt.top();
                s_opt.pop();
                int num1,num2;
                switch(ch)
                {
                    case'+':
                        num1=s_num.top();
                        s_num.pop();
                        num2=s_num.top();
                        s_num.pop();
                        s_num.push(num1+num2);
                    break;
 
                    case'-':
                        num1=s_num.top();
                        s_num.pop();
                        num2=s_num.top();
                        s_num.pop();
                        s_num.push(num1-num2);
                    break;
					
                    case'*':
                        num1=s_num.top();
                        s_num.pop();
                        num2=s_num.top();
                        s_num.pop();
                        s_num.push(num1*num2);
                    break; 
					
                    case'/':
                        num1=s_num.top();
                        s_num.pop();
                        num2=s_num.top();
                        s_num.pop();
                        s_num.push(num1/num2);
                    break;    
                }
            }    
        }
    }
    //输出栈顶元素
    cout << s_num.top() << endl;
 
    return 0;
 
 
}
