#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N = 0;
    int M = 0;
    int cycle = 0;
    char dummy;

    cin >> N >> M;
    cin.get(dummy);
    char **map = new char *[M];
    char **map_temp = new char *[M];

    for (int i = 0; i < M; i++)
    {
        map[i] = new char[N + 1];
    }

    for (int i = 0; i < M; i++)
    {
        map_temp[i] = new char[N + 1];
    }

    for (int i = 0; i < M; i++)
    {
        cin.getline(map[i], N + 1, '\n');
        
    }

    for (int i = 0; i < M; i++)
    {
        strcpy(map_temp[i], map[i]);
    }


    cin >> cycle;

    while (cycle > 0)
    {
        cycle--;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == 0 && j == 0)
                {
                    if (map[i][j] == 'O')
                    {
                        if (map[i + 1][j] == 'X' || map[i][j + 1] == 'X')
                        {
                            map_temp[i][j] = 'X';
                        }
                    }
                }

                else if (i == M - 1 && j == 0)
                {
                    if (map[i][j] == 'O')
                    {
                        if (map[i - 1][j] == 'X' || map[i][j + 1] == 'X')
                        {
                            map_temp[i][j] = 'X';
                        }
                    }
                }

                else if (i == 0 && j == N - 1)
                {
                    if (map[i][j] == 'O')
                    {
                        if (map[i + 1][j] == 'X' || map[i][j - 1] == 'X')
                        {
                            map_temp[i][j] = 'X';
                        }
                    }
                }

                else if (i == M - 1 && j == N - 1)
                {
                    if (map[i][j] == 'O')
                    {
                        if (map[i - 1][j] == 'X' || map[i][j - 1] == 'X')
                        {
                            map_temp[i][j] = 'X';
                        }
                    }
                }

                else if (i == 0)
                {
                    if (map[i][j] == 'O')
                    {
                        if (map[i + 1][j] == 'X' || map[i][j - 1] == 'X' || map[i][j + 1] == 'X')
                        {
                            map_temp[i][j] = 'X';
                        }
                    }
                }

                else if (i == M - 1)
                {
                    if (map[i][j] == 'O')
                    {
                        if (map[i - 1][j] == 'X' || map[i][j - 1] == 'X' || map[i][j + 1] == 'X')
                        {
                            map_temp[i][j] = 'X';
                        }
                    }
                }

                else if (j == 0)
                {
                    if (map[i][j] == 'O')
                    {
                        if (map[i - 1][j] == 'X' || map[i + 1][j] == 'X' || map[i][j + 1] == 'X')
                        {
                            map_temp[i][j] = 'X';
                        }
                    }
                }

                else if (j == N - 1)
                {
                    if (map[i][j] == 'O')
                    {
                        if (map[i - 1][j] == 'X' || map[i + 1][j] == 'X' || map[i][j - 1] == 'X')
                        {
                            map_temp[i][j] = 'X';
                        }
                    }
                }

                else
                {
                    if (map[i][j] == 'O')
                    {
                        if (map[i - 1][j] == 'X' || map[i + 1][j] == 'X' || map[i][j + 1] == 'X' || map[i][j - 1] == 'X')
                        {
                            map_temp[i][j] = 'X';
                        }
                    }
                }
            }
        }

        for (int i = 0; i < M; i++)
        {
        strcpy(map[i], map_temp[i]);
        }
    }

    for (int i = 0; i < M; i++)
    {
        cout << map[i] << endl;
    }
   
}