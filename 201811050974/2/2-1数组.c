//2020-12-21
//LZL
//
#include<stdio.h>
#define MaxSize 100
void king(int m,int n)
{
	int monkey[MaxSize];
	int i,j,t;
	for(i=0;i<m;i++)  //构建初始序列，记录m只猴子在p[0]~p[m-1]中
	{
		monkey[i]=i+1; 
	}
	t=0;    //首次报数的位置为0

	for(i=m;i>=1;i--)//循环要执行m次，有m个猴子要出圈；共有i从m开始递减至1，i还表示在圈中猴子的数目
	{
	  t=(t+n-1)%i;      //从t开始数1到n，t加n-1用%i取余，目的是到达最后一个猴子可以折回去继续数
      for (j=t+1; j<=i-1; j++)//后面的元素前移一个位置，删除了编号为p[t]的猴子
		  monkey[j-1]=monkey[j];
	}
    printf("按照%d个猴子，数%d个数的方法，猴子大王是%d号\n",m,n,monkey[t]);
}
int main()
{
	int m,n;
    printf("请输入猴子个数m和报数n：");
	scanf("%d %d",&m,&n);
	king(m,n);
	return 0;
}

