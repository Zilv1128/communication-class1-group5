#define N 12
#define M 6//�����ֱ�Ե����Ⱦʱ���ô������������±곬����Χ�����⣬�ʽ���ά������к�������2
#include<iostream>
using namespace std;
main()
{
	char map[M][N];
	int i,j,k,c;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			cin>>map[i][j];
		}
	}
	cin>>c;
	cout<<"ʵ�����õ�Ϊ�ڶ��е���M-1�У��ڶ��е���N-1����ɵĶ�ά����"<<endl;
	for(k=0;k<c;k++)
	{
		for(i=1;i<M-1;i++)
		{
			for(j=1;j<N-1;j++)
			{
				if(map[i][j]=='X'+k)//����ʹ��ǰ���Ⱦ������������ֶ�
				{
					if(map[i][j+1]=='P')
					{
						map[i][j-1]='X'+k+1;
						map[i-1][j]='X'+k+1;
						map[i+1][j]='X'+k+1;
					}
					else if(map[i][j-1]=='P')
					{
						map[i][j+1]='X'+k+1;
						map[i-1][j]='X'+k+1;
						map[i+1][j]='X'+k+1;
					}
					else if(map[i+1][j]=='P')
					{
						map[i][j-1]='X'+k+1;
						map[i][j+1]='X'+k+1;
						map[i-1][j]='X'+k+1;
					}
					else if(map[i-1][j]=='P')
					{
						map[i][j-1]='X'+k+1;
						map[i][j+1]='X'+k+1;
						map[i+1][j]='X'+k+1;
					}
					else
					{
						map[i][j+1]='X'+k+1;
						map[i][j-1]='X'+k+1;
						map[i-1][j]='X'+k+1;
						map[i+1][j]='X'+k+1;
					}
				}
				else
					continue;
			}
		}
	}
	for(i=1;i<M-1;i++)
	{
		for(j=1;j<N-1;j++)
		{
			for(k=1;k<=c;k++)
			{
				if(map[i][j]=='X'+k)
					map[i][j]='X';
				else
					continue;
			}
		}
	}
	for(i=1;i<M-1;i++)
	{
		for(j=1;j<N-1;j++)
		{
			cout<<map[i][j];
		}
		cout<<endl;
	}
}