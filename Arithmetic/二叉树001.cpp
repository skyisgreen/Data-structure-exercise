#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int h[101];//������Ŷѵ�����
int n;//�����洢����Ԫ�ظ�����Ҳ���ǶѵĴ�С

//�������� ���������������� 
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
		{
			
		}
	 } 
  } 











int main(int argc, char** argv) 
{
	
	
	
	return 0;
}
