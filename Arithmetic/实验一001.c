#include <stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct node
{
	int num;
	char name[20];
	char Email[20];
	char tel[12];
	char addr[30];
	struct node *next;
};
 
typedef struct node Node;
typedef struct node *Link;
 
 
void link_malloc(Link *new_node)    //�ռ����
{   
 
	*new_node = (Link)malloc(sizeof(Node));
 
	if( new_node == NULL)
	{
		printf("malloc error!\n");
		exit(-1);
	}
 
}
 
void create_link(Link *head)
{
	link_malloc(head);
	(*head)->next = *head;
 
}
 
 
 
Link Tel_play(Link head,char *old_tel)
{
	Link p;
	p = head -> next;
	while(p!=head)
	{
		if(strcmp(p->name,old_tel)==0)
		{
		  
		printf("�޸�ʧ�ܣ�\n");
		}
		else 
			p=p->next;
	}
	if(p==head)
		printf("�޸ĳɹ���\n");
			return 0;
}
Link Del_play(Link head,char *fullname)
{
	Link p;
	p = head -> next;
	while(p!=head)
	{
		if(strcmp(p->name,fullname)==0)
		{
		  
		printf("ɾ��ʧ�ܣ�\n");
		}
		else 
			p=p->next;
	}
	if(p==head)
		printf("ɾ���ɹ���\n");
			return 0;
}
 
Link Search(Link head,char *fullname)
{
	Link p;
	p = head -> next;
	while(p!=head)
	{
		if(strcmp(p->name,fullname)==0)
			return p;
		else 
			p=p->next;
	}
	if(p==NULL)
		printf("û�в鵽��");
			return 0;
}
 
 
Link display_only(Link head,char *fullname)
{
	Link p;
	p = head -> next;
	while(p!=head)
	{    
		if(strcmp(p->name,fullname)==0)
		{
			printf("\n");
	    printf("���:%d\n",p->num);
		printf("����: %s\n",p->name);
		printf("�绰����: %s\n",p->tel);
		printf("����:%s\n",p->Email);
		printf("��ַ:%s\n",p->addr);
		break;
		}
		else 
			p=p->next;
	}
	if(p==NULL)
		printf("û�в鵽��");
			return 0;
}
void display_link(Link head)//�������
{   
	int i = 0;
 
	Link p = NULL;
	p = head ->next;
 
	if(p == head)
	{
		printf("Empty!\n");
	}
   else
   {
 
	while( p != head && p != NULL)
	{   
		printf("\n");
		printf("���:%d\n",p->num);
		printf("����: %s\n",p->name);
		printf("�绰����: %s\n",p->tel);
		printf("����:%s\n",p->Email);
		printf("��ַ:%s\n",p->addr);
		p = p -> next;	
	}
 
   }
	printf("\n");
}
Link  node_sort(Link head,Link new_node,int num)
{   	Link p = NULL;
	Link q = NULL;
	p = head -> next;
	q = head ->next;
	if(head ->next == head)
	{
		head ->next = new_node;
		new_node->next=head;
	}
 
	else
	{
		if(num < (head ->next)->num)
		{
			new_node->next = head ->next;
			head ->next = new_node;
		}	
		else
		{
 
 
			while(p!=head && p->num < new_node->num)
			{
				q = p;
 
				p = p ->next;
			}
 
			if(p == head)
			{
				q -> next =new_node;
				new_node -> next = head;
			}
 
			else	
 
			{
				new_node ->next =p;
				q -> next = new_node;
			}
 
		}
	}
}
 
Link SearchDel(Link head,char *fullname)
{
	Link q,p;
	p=head->next;
	q=head->next;
 
	if(p==head)
	{
		return;
	}
	else
	{   
		if(strcmp((head->next)->name,fullname)==0)
		{
			head->next=p->next;
			free(p);
		}
		else
		{
		while(p!=head && strcmp(p->name,fullname)!=0)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		free(p);
		if(p==head)
		{
	  printf("δ�ҵ����ˣ�\n");
	  return 0;
         }
        }
     }
}
 
int main()    //������
{   
	char fullname[20];
	Link searchpoint;
	int key,num1,num2;
	char name,Email,addr,old_tel;
	int num;
	int tel,i=1;
	Link new_node = NULL;
	Link head = NULL;
 
	create_link( &head );
	while(1)
	{
       
		printf("___________________________________\n");
		printf("       ******���˵�*********\n");
		printf("[1]�鿴��ϵ��       [2]�½���ϵ��\n");
		printf("[3]ɾ����ϵ         [4]�޸���ϵ��\n");
		printf("[5]��ʾ������ϵ��   [6]�˳�\n");
		printf("***��û��ϵ����Ҫ�����***\n");
		printf("___________________________________\n");
		scanf("%d",&num1);
 
		switch(num1)
		{
			case 1:
				{ //������ϵ��
					printf("�������������: ");
					scanf("%s",fullname);
					searchpoint=Search(head,fullname);
					printf("\n����ҵ���Ϊ:%s,����Ϊ:%s,����Ϊ��%s\n",
							&searchpoint ->name,&searchpoint->tel,
							&searchpoint->Email);
					printf("\n���س����ص����˵���");
					getchar();getchar();
					break;
				}
 
 
			case 2:{   //�½���ϵ��
 
 
					   link_malloc( &new_node );//�ռ����
					   new_node->num=i;
					   i++;
 
					   printf("����������:");
					   scanf("%s",new_node->name);
					   printf("\n");
					   printf("�������ֻ�����:");
					   scanf("%s",new_node->tel);
					   printf("\n");
					   printf("����������:");
					   scanf("%s",new_node->Email);
					   printf("\n");
					   printf("�������ַ:");
					   scanf("%s",new_node->addr);
					   printf("\n");
					   node_sort(head,new_node,num);
					   printf("\n");
				       display_only(head,new_node->name);
					   printf("\n���س����ص����˵���");
					   getchar();getchar();
					   break;
 
				   }
			case 3:{
 
					   //ɾ��
					   printf("\n��������Ҫɾ�����˵�����:");
					   scanf("%s",fullname);
					   SearchDel(head,fullname);
				       Del_play(head,fullname);
					   printf("\n���س����ص����˵���");
					   getchar();getchar();
					   break;
				   }
			case 4:{
 
					   //�޸�
					   printf("������Ҫ�޸ĵ�����:");
					   scanf("%s",fullname);
					   searchpoint=Search(head,fullname);
					   printf("�������º���:");
					   scanf("%s",searchpoint->tel);
	                   printf("\n�Ƿ�Ҫ�޸ĵ�ַ(Y/N):");
					   getchar();
					   if(getchar()=='Y')
					   {    printf("�������µĵ�ַ:");
						   scanf("%s",searchpoint->addr);
					   }
					   printf("\n�Ƿ�Ҫ�޸�����(Y/N):");
					   getchar();
					   if(getchar()=='Y')
					   {
						   printf("�������µ�����:");
						   scanf("%s",searchpoint->Email);
						   printf("\n");
					   }
					   Tel_play(head,*&searchpoint->tel);
				       display_only(head,fullname);
					   printf("\n���س����ص����˵���");
					   getchar();getchar();
					   break;
				   }
			case 5:{
 
					   display_link( head );
					   printf("\n���س����ص����˵���");
					   getchar();getchar();
					   break;
				   }
			case 6: exit(-1);
					break;
		}
	}
	return 0;
}

