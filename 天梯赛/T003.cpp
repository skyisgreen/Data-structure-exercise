#include<stdio.h>
#include<string.h>
int main()
{   
  int y,n;
  int a,b,c,d;//����λ���ϵ�ֵ��aΪǧλ��bΪ��λ��cΪʮλ��dΪ��λ
  int f[10];
  int x=0;
  scanf("%d %d",&y,&n);
  for(int i=y;i<10000;i++)
  {
    a=i/1000;
    b=i/100%10;
    c=i%100/10;
    d=i%10;
    memset(f,0,sizeof(f));//������f�����Ե�Ԫ�س�ʼ��Ϊ0
    f[a]=1;
    if(f[b]!=1)
    f[b]=1;
    if(f[c]!=1)
    f[c]=1;
    if(f[d]!=1)
    f[d]=1;//���±�Ϊa,b,c,d������Ԫ�ظ�ֵΪ1�����±���ͬ�򲻻ḳֵ���������������м���Ϊ1��Ԫ�أ�����ǲ�ͬ���ֵĸ���
    int sum=0;
    for(int j=0;j<10;j++)
    {
      sum=sum+f[j];//����Ϊ1��Ԫ�ظ�������Ϊ��ͬ���ֵ��ܺ�
    }
    if(sum==n&&x==0)
    {
      printf("%d %04d",i-y,i);
      x++;
    }
  }
  return 0;
}
