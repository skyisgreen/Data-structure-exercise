#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct list{
	int data;
	struct list*next;//��¼��һ���ڵ�ĵ�ַ 
}list;

 struct list*L0=NULL;//ͷָ�� 
 struct list*head0=NULL;//��ָ�� 
 struct list*p0=NULL;//��һ�� 
 
 struct list*L1=NULL;
 struct list*head1=NULL;
 struct list*p1=NULL;//�ڶ��� 
 
 struct list*L2=NULL;
 struct list*q=NULL;
 struct list*q1=NULL;//�������� 
 
int main(int argc, char *argv[]) {
	
	int i=0;
	int length;//����
	printf("��������ĳ���\n");
	scanf("%d",&length);
	
head0=(struct list*)malloc(sizeof(struct list));//��̬�����ڴ� 
	L0=head0; 
	
	printf("�����������������\n");
	for(i=0;i<length;i++){
		p0=(struct list*)malloc(sizeof(struct list));
		scanf("%d",&p0->data);
		p0->next=NULL;
		head0->next=p0;
		head0=p0; 
	}
	
	int i1=0;
	int length1;
	printf("��������ĳ���\n");
	scanf("%d",&length1);
	
	head1=(struct list*)malloc(sizeof(struct list));
	L1=head1;
	
	printf("�����������������\n");
	for(i=0;i1<length1;i1++){
		p1=(struct list*)malloc(sizeof(struct list));
		scanf("%d",&p1->data);
		p1->next=NULL;
		head1->next=p1;
		head1=p1; 
		
}
    L2=(struct list*)malloc(sizeof(struct list));
    q=L2;
    p0=L0->next;
     p1=L1->next;
	while(p0&&p1){	
	  if(p0->data<p1->data){
     	L2->next=p0;
		L2=p0;
		p0=p0->next;
	}else if(p0->data==p1->data){
		L2->next=p0;
		L2=p0;
		p0=p0->next;
		q1=p1->next;//������ͬԪ�ص���һ����ַָ�� 
		free(p1);
		p1=q1;
		
	}else if(p0->data>p1->data){
		L2->next=p1;
		L2=p1;
		p1=p1->next;
	}		
	}
   L2->next=p0?p0:p1;
   free(L1);
   printf("�ϲ������������\n");
    p0=q->next;
    while(p0){
	printf("%d ",p0->data);
	p0=p0->next;
	}

}

