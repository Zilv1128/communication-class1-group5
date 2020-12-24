#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int dx[4]={1,-1,0,0};     
int dy[4]={0,0,1,-1};
char a[1005][1005];
int n,m;
 
void dfs(int x,int y)
{ 
	for(int i=0;i<4;i++)
	{
		int xnew=x+dx[i];
        int ynew=y+dy[i];
        if(a[xnew][ynew]=='O')
		{
			a[xnew][ynew]='X';
		}
	}
    return;
}
int main()
{
	int i=1,j=1,k=1,t;
	int x_place,y_place;
    scanf("%d%d",&n,&m);

    string s;           //用来砍掉末尾的回车和空格 
    getline(cin,s);


    for(i=1;i<=m;i++)
	{
        for(j=1;j<=n;j++)
		{
            scanf("%c",&a[i][j]);
        }

        string sss;         
        getline(cin,sss);

    }
	//scanf("%d",&t);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]=='X')
				{
					x_place=i;
					y_place=j;
				}
			}
		}
         dfs(x_place,y_place);
//输出结果
    for(i=1;i<=m;i++)
	{
        for(j=1;j<=n;j++)
		{
           printf("%c",a[i][j]);
		}
		printf("\n"); 
	}
    return 0;
}