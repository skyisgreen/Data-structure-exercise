#include <iostream>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//����һ���ṹ��������ʾ����Ľ������
struct node{
	int data;
	struct node *next;
}; 


int main(int argc, char** argv) {
	
	struct  node *next,*head; 
	struct node *p,*q,*t;
	int i ,n, a ;
	scanf("%d",&n);
	head=NULL;//ͷָ���ʼΪ��
	
	for(i=1;i<n;i++)
	{
		scanf("%d",&a);
		//��̬����һ���ռ䣬�������һ����㣬������ʱָ��pָ��������
		p=(struct node *) malloc(sizeof (struct node));
		p->data=a;//�����ݴ洢����ǰ����data����
		p->next=NULL;//���õ�ǰ���ĺ��ָ��ָ��գ�Ҳ���ǵ�ǰ������һ�����Ϊ�� 
		
		if(head==NULL)
		head=p;//������ǵ�һ�������Ľ�㣬��ͷָ��ָ�������� 
		else
		q->next=p;//������ǵ�һ����㣬����һ�����ĺ��ָ��ָ��ǰ���
		q=p;//ָ��qҲָ��ǰ��� 
	 } 
	 //��������е�������
	  t=head;
	  while(t!=NULL)
	  {
	  	printf("%d",t->data);
	  	t=t->next;//������һ����� 
	  }
	
	
	return 0;
}
