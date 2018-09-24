#include <iostream>

 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
 
int InitList(LinkList &L){
	L=new LNode;
	L->next=NULL;
	return 1;
}
 
void CreateList(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;
	struct LNode *r;
	r=L;
	for(int i=0;i<n;i++){
		printf("�������%d��Ԫ�ص�ֵ:",i+1);
		struct LNode *s;
		s=new LNode;
		scanf("%d",&s->data);
		s->next=NULL; 
		r->next=s;
		r=s;
	}
}

void getMax(LinkList L){
	struct LNode *pmax;
	pmax=L->next;
	struct LNode *p;
	p=L->next;
	while(p){
		if(p->data>pmax->data){
			pmax=p;
		}
		p=p->next;
	}
	printf("�������Ԫ��ֵ:%d\n",pmax->data);
}
 
int main(){
	LinkList L;
	
	if(InitList(L)){
		printf("����L��ʼ���ɹ�!\n");
	}else{
		printf("����L��ʼ��ʧ��!\n");
	}
	
	printf("����������L�ĳ���:");
	int n;
	scanf("%d",&n);
	CreateList(L,n);
	//TraveList(L);
	getMax(L);
}

