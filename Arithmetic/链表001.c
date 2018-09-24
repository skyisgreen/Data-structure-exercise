#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct list{
	int data;
	struct list*next;//记录下一个节点的地址 
}list;

 struct list*L0=NULL;//头指针 
 struct list*head0=NULL;//首指针 
 struct list*p0=NULL;//第一条 
 
 struct list*L1=NULL;
 struct list*head1=NULL;
 struct list*p1=NULL;//第二条 
 
 struct list*L2=NULL;
 struct list*q=NULL;
 struct list*q1=NULL;//过渡链表 
 
int main(int argc, char *argv[]) {
	
	int i=0;
	int length;//长度
	printf("输入链表的长度\n");
	scanf("%d",&length);
	
head0=(struct list*)malloc(sizeof(struct list));//动态分配内存 
	L0=head0; 
	
	printf("依次输入链表的内容\n");
	for(i=0;i<length;i++){
		p0=(struct list*)malloc(sizeof(struct list));
		scanf("%d",&p0->data);
		p0->next=NULL;
		head0->next=p0;
		head0=p0; 
	}
	
	int i1=0;
	int length1;
	printf("输入链表的长度\n");
	scanf("%d",&length1);
	
	head1=(struct list*)malloc(sizeof(struct list));
	L1=head1;
	
	printf("依次输入链表的内容\n");
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
		q1=p1->next;//备用相同元素的下一个地址指向 
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
   printf("合并后链表的内容\n");
    p0=q->next;
    while(p0){
	printf("%d ",p0->data);
	p0=p0->next;
	}

}

