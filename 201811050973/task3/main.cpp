#include <iostream>
using namespace std;
#define MAX 20

int main()
{
    struct stu
    {
        int stunum;
        int Chinese;
        int Math;
        int English;
        int sum;
    };

    int total = 0;
    stu student[MAX];
    stu temp = {0};
    cin >> total;
    int num_assign = 0;
    int flag = 0;
    for (int i = 0; i < total; i++)
    {
        cin >> student[i].Chinese >> student[i].Math >> student[i].English;
        student[i].sum = student[i].Chinese + student[i].Math + student[i].English;
        student[i].stunum = ++num_assign;
    }
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - i - 1; j++)
        {
            if (student[j].sum < student[j + 1].sum)
            {
               flag = 1;
            }
            else if(student[j].sum == student[j + 1].sum)
            {
                if (student[j].Chinese < student[j + 1].Chinese)
                {
                    flag = 1;
                }
                else if (student[j].Chinese == student[j + 1].Chinese)
                {
                    if (student[j].stunum > student[j + 1].stunum)
                    {
                        flag = 1;
                    }
                }
            }

            if (flag == 1)
            {
                flag = 0;
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << student[i].stunum << ' ' << student[i].sum << endl;
    }
}