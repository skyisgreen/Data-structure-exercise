#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int q[20]={0,6,3,1,7,5,8,9,2,4};
	int head;
	int tail;
	
	//��ʼ������
	head = 1;
	tail = 10;
	
	while(head<tail)//���в�Ϊ��ʱִ��ѭ�� 
	{
		//��ӡ���ײ������׳���
		printf("%d",q[head]); 
		head++;
		
		//�����׵�������ӵ���β
		q[tail]=q[head];
		tail++;//��β����һ���� 
		head++; 
		
	}
	return 0;
}
