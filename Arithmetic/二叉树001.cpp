#include <iostream>
//�����Լ������� 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int h[101];//������Ŷѵ�����
int n;//�����洢����Ԫ�ظ�����Ҳ���ǶѵĴ�С

//�������� �������������е�����Ԫ�ص�ֵ 
void swap(int x ,int y)
{
	int t;
	t=h[x];
	h[x]=h[y];
	h[y]=t;
	return;
 } 
 
 //���µ�������
 void siftdown (int i)//����һ����Ҫ���µ����Ľ����i�����ﴫ��1�����ӶѵĶ��㿪ʼ
 //���µ��� 
 {
 	int t,flag=0;//flag��������Ƿ���Ҫ�������µ���
	//��i����ж��ӣ���ʵ��������ӣ���������Ҫ����������ʱ��ѭ����ִ��
	while(i*2<=n&&flag==0)
	{
		//���жϺ�����ӵĹ�ϵ������t��¼ֵ��С�Ľ����
		if(h[i]>h[i*2])
		t=i*2;
		else
		t=i;
		
		//��������Ҷ��ӣ��ٶ��Ҷ��ӽ�������
		if(i*2+1<=n)
		{
			//����Ҷ��Ӹ�С�����½�С�Ľ���� 
			if(h[t]>h[i*2+1])
			t=i*2+1;
			 
		 } 
		 
		 //���������С�Ľ���Ų����Լ���˵���ӽ�����бȸ�����С��
		 if(t!=i)
		 {
		 	swap(t,i);
		 	i=t;
		  } 
		  else
		       flag=1;
	 } 
	 return;
  } 











int main(int argc, char** argv) 
{
	
	
	
	return 0;
}
