#define N 12
#define M 6//因会出现边缘被感染时，该代码会造成数组下标超出范围的问题，故将二维数组的行和列增加2
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
	cout<<"实际有用的为第二行到第M-1行，第二列到第N-1列组成的二维数组"<<endl;
	for(k=0;k<c;k++)
	{
		for(i=1;i<M-1;i++)
		{
			for(j=1;j<N-1;j++)
			{
				if(map[i][j]=='X'+k)//这样使得前后感染的区域具有区分度
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