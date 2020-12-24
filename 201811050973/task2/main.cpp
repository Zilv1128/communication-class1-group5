#include <iostream>
using namespace std;
#define MAX 100

// ʹ������
/*
int main()
{
    int m, n;
    int total = 0;
    int flag;
    int count = 0;
    cin >> m >> n;
    int Monkeys[MAX];
    total = m;

    for (int i = 0; i < m; i++)
    {
        Monkeys[i] = i + 1;
    }

   
    flag = 0;
    while (total > 1)
    {
        count += 1;
        if (count == n)
        {
            count = 0;
            cout << Monkeys[flag] << " �ź��ӳ���"<< endl;
            for (int i = flag; i < total - 1; i++)
            {
                Monkeys[i] = Monkeys[i + 1];
            }
            total = total - 1;
        }
        else
        {
            flag = flag + 1;
        }

        if (flag == total)
        {
            flag = 0;
        }
    }
    cout << "��Ϸ����" << Monkeys[flag] << " �ź����Ǵ���" << endl;
}*/

// ʹ������

int main()
{
    struct Monkey
    {
        int number;
        Monkey *last;
        Monkey *next;
    };

    int m = 0;
    int n = 0;
    cin >> m >> n;

    int total = m;
    int count = 0;
    Monkey *flag = new Monkey[m];

    for (int i = 0; i < m - 1; i++)
    {
        flag[i].number = i + 1;
        flag[i].next = flag + i + 1;
    }
    flag[m - 1].next = flag;
    flag[m - 1].number = m;

    for (int i = 1; i < m; i++)
    {
        flag[i].last = flag + i - 1;
    }
    flag[0].last = flag + m - 1;

    Monkey *temp1 = flag;
    Monkey *temp2 = NULL;
    while (total > 1)
    {
        count = count + 1;
        if (count == n)
        {
            count = 0;
            cout << (*temp1).number << "�ź��ӳ���"<< endl;
            (*(*temp1).last).next = (*temp1).next;
            (*(*temp1).next).last = (*temp1).last;
            temp2 = temp1;
            temp1 = (*temp1).next;
            total = total - 1;
        }

        else
        {
            temp1 = (*temp1).next;
        }
        
    }
    cout << (*temp1).number << "�ź����Ǵ���" << endl;
}
