//2020-12-21
//LZL
//
#include<stdio.h>
#define MaxSize 100
void king(int m,int n)
{
	int monkey[MaxSize];
	int i,j,t;
	for(i=0;i<m;i++)  //������ʼ���У���¼mֻ������p[0]~p[m-1]��
	{
		monkey[i]=i+1; 
	}
	t=0;    //�״α�����λ��Ϊ0

	for(i=m;i>=1;i--)//ѭ��Ҫִ��m�Σ���m������Ҫ��Ȧ������i��m��ʼ�ݼ���1��i����ʾ��Ȧ�к��ӵ���Ŀ
	{
	  t=(t+n-1)%i;      //��t��ʼ��1��n��t��n-1��%iȡ�࣬Ŀ���ǵ������һ�����ӿ����ۻ�ȥ������
      for (j=t+1; j<=i-1; j++)//�����Ԫ��ǰ��һ��λ�ã�ɾ���˱��Ϊp[t]�ĺ���
		  monkey[j-1]=monkey[j];
	}
    printf("����%d�����ӣ���%d�����ķ��������Ӵ�����%d��\n",m,n,monkey[t]);
}
int main()
{
	int m,n;
    printf("��������Ӹ���m�ͱ���n��");
	scanf("%d %d",&m,&n);
	king(m,n);
	return 0;
}

