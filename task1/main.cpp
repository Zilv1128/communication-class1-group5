#include <iostream>
using namespace std;

int fun1(int a, int b)
{
    int temp1 = a % 10;
    int temp2 = a / 10;
    int temp3 = b % 10;
    int temp4 = b / 10;
    int c = 0;
    c = temp1 * 1000 + temp2 * 10 + temp3 * 100 + temp4;
    return (c);
}

void fun2(int a, int b, int &c)
{
    int temp1 = a % 10;
    int temp2 = a / 10;
    int temp3 = b % 10;
    int temp4 = b / 10;
    c = temp1 * 1000 + temp2 * 10 + temp3 * 100 + temp4;
}

void fun3(int a, int b, int *c)
{
    int temp1 = a % 10;
    int temp2 = a / 10;
    int temp3 = b % 10;
    int temp4 = b / 10;
    *c = temp1 * 1000 + temp2 * 10 + temp3 * 100 + temp4;
}

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    cin >> a >> b;
    //c = fun1(a, b);
    //fun2(a, b, c);
    fun3(a, b, &c);
    cout << c << endl;
}