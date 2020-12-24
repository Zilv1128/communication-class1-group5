#include "iostream"
#include "stack"
//����������ջ
using namespace std;
 
int Priority(char ch)   //�������ȼ�
{
	// ������'(' > �˳� '*' = '/' > �Ӽ� '+' = '-' > ������')'
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
    stack<char> s_opt;   //����ջ
    stack<int> s_num;    //����ջ
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
				s_num.push(tmp);   //ѹջ
				tmp = 0;
			}    
		}
        else
        {
			//����������)��ջ����ջ��Ԫ����(,���з���ƥ��
            if((opt[i]==')')&&(s_opt.top()=='('))  
            {
                s_opt.pop();  //���ų�ջ
                i++;
                continue;
            }
            //����ջΪ�� ||�������ȼ�����ջ������ ||ջ��������(������һ�����Ų���)
			//������ջ
            if((s_opt.empty())==true||(Priority(opt[i])>Priority(s_opt.top()))||
              (s_opt.top()=='('&&(opt[i]!=')')))
            {
                s_opt.push(opt[i]);//����ѹջ
                i++;
                continue;
            }
			//���ż�Ϊ�ղ��ҷ���ջ��Ϊ�� || ���������Ų���ջ��Ԫ�ز�Ϊ������ ||������ŵ����ȼ�
			//��ջ  + - * / 
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
    //���ջ��Ԫ��
    cout << s_num.top() << endl;
 
    return 0;
 
 
}
