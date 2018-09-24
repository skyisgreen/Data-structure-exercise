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
		printf("请输入第%d个元素的值:",i+1);
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
	printf("链表最大元素值:%d\n",pmax->data);
}
 
int main(){
	LinkList L;
	
	if(InitList(L)){
		printf("链表L初始化成功!\n");
	}else{
		printf("链表L初始化失败!\n");
	}
	
	printf("请输入链表L的长度:");
	int n;
	scanf("%d",&n);
	CreateList(L,n);
	//TraveList(L);
	getMax(L);
}

