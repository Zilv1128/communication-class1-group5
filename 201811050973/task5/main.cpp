#include <iostream>
#include <cstring>
using namespace std;
#define MAXSIZE 50

typedef struct
{
    char *base;
    char *top;
    int stacksize;
} SqStack2;

typedef struct
{
    int *base;
    int *top;
    int stacksize;
} SqStack1;

int InitStack1(SqStack1 &S)
{
    S.base = new int[MAXSIZE];
    if (!S.base)
        return 0;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return 1;
}

int InitStack2(SqStack2 &S)
{
    S.base = new char[MAXSIZE];
    if (!S.base)
        return 0;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return 1;
}

int Push1(SqStack1 &S, int e)
{
    if (S.top - S.base == S.stacksize)
        return 0;
    *S.top++ = e;
    return 1;
}

int Push2(SqStack2 &S, char e)
{
    if (S.top - S.base == S.stacksize)
        return 0;
    *S.top++ = e;
    return 1;
}

int Pop1(SqStack1 &S, int &e)
{
    if (S.top == S.base)
        return 0;
    e = *--S.top;
    return 1;
}

int Pop2(SqStack2 &S, char &e)
{
    if (S.top == S.base)
        return 0;
    e = *--S.top;
    return 1;
}

int GetTop1(SqStack1 S)
{
    if (S.top != S.base)
        return *(S.top - 1);
}

char GetTop2(SqStack2 S)
{
    if (S.top != S.base)
        return *(S.top - 1);
}
int compare_list[7][7] =
    {
        1, 1, -1, -1, -1, 1, 1,
        1, 1, -1, -1, -1, 1, 1,
        1, 1, 1, 1, -1, 1, 1,
        1, 1, 1, 1, -1, 1, 1,
        -1, -1, -1, -1, -1, 0, -2,
        1, 1, 1, 1, -2, 1, 1,
        -1, -1, -1, -1, -1, -2, 0};

int Compare(char a, char b)
{
    int p1, p2;
    switch (a)
    {
    case '+':
        p1 = 0; break;
    case '-':
        p1 = 1; break;
    case '*':
        p1 = 2; break;
    case '/':
        p1 = 3; break;
    case '(':
        p1 = 4; break;
    case ')':
        p1 = 5; break;
    case '#':
        p1 = 6; break;
    };

    switch (b)
    {
    case '+':
        p2 = 0; break;
    case '-':
        p2 = 1; break;
    case '*':
        p2 = 2; break;
    case '/':
        p2 = 3; break;
    case '(':
        p2 = 4; break;
    case ')':
        p2 = 5; break;
    case '#':
        p2 = 6; break;
    };

    return compare_list[p1][p2];
}

int calculate(char op, int a, int b)
{
    if (op == '+')
        return (a + b);
    else if (op == '-')
        return (a - b);
    else if (op == '*')
        return (a * b);
    else if(op == '/')
        return (a / b);
    else 
        exit;
}
int main()
{
    char exp[MAXSIZE];
    char *p;
    int com_result;
    char optr_temp;
    int num1, num2;
    int exp_length;
    SqStack1 OPND;
    SqStack2 OPTR;
    InitStack1(OPND);
    InitStack2(OPTR);
    cin.getline(exp, MAXSIZE + 2, '\n');
    exp_length = strlen(exp);
    exp[exp_length] = '#';
    exp[exp_length + 1] = '\0';
    
    p = exp;
    Push2(OPTR, '#');
    
    while (*p != '#' || GetTop2(OPTR) != '#')
    {
        if (*p != '+' && *p != '-' && *p != '*' && *p != '/' && *p != '#' && *p != '(' && *p != ')')
        {
            Push1(OPND, *p - '0');
            p++;
        }
        else
        {
            com_result = Compare(GetTop2(OPTR), *p);
            if (com_result == -1)
            {
                Push2(OPTR, *p);
                p++;
            }

            else if (com_result == 1)
            {
                Pop2(OPTR, optr_temp);
                Pop1(OPND, num1);
                Pop1(OPND, num2);
                Push1(OPND, calculate(optr_temp, num2, num1));
            }

            else if (com_result == 0)
            {
                Pop2(OPTR, optr_temp); 
                p++;
            }
        }
    }

    cout << GetTop1(OPND);
}