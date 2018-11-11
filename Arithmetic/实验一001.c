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
 
 
void link_malloc(Link *new_node)    //空间分配
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
		  
		printf("修改失败！\n");
		}
		else 
			p=p->next;
	}
	if(p==head)
		printf("修改成功！\n");
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
		  
		printf("删除失败！\n");
		}
		else 
			p=p->next;
	}
	if(p==head)
		printf("删除成功！\n");
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
		printf("没有查到！");
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
	    printf("序号:%d\n",p->num);
		printf("姓名: %s\n",p->name);
		printf("电话号码: %s\n",p->tel);
		printf("邮箱:%s\n",p->Email);
		printf("地址:%s\n",p->addr);
		break;
		}
		else 
			p=p->next;
	}
	if(p==NULL)
		printf("没有查到！");
			return 0;
}
void display_link(Link head)//链表输出
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
		printf("序号:%d\n",p->num);
		printf("姓名: %s\n",p->name);
		printf("电话号码: %s\n",p->tel);
		printf("邮箱:%s\n",p->Email);
		printf("地址:%s\n",p->addr);
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
	  printf("未找到此人！\n");
	  return 0;
         }
        }
     }
}
 
int main()    //主函数
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
		printf("       ******主菜单*********\n");
		printf("[1]查看联系人       [2]新建联系人\n");
		printf("[3]删除联系         [4]修改联系人\n");
		printf("[5]显示所有联系人   [6]退出\n");
		printf("***若没联系人需要先添加***\n");
		printf("___________________________________\n");
		scanf("%d",&num1);
 
		switch(num1)
		{
			case 1:
				{ //查找联系人
					printf("请输入查找姓名: ");
					scanf("%s",fullname);
					searchpoint=Search(head,fullname);
					printf("\n你查找的人为:%s,号码为:%s,邮箱为：%s\n",
							&searchpoint ->name,&searchpoint->tel,
							&searchpoint->Email);
					printf("\n按回车键回到主菜单。");
					getchar();getchar();
					break;
				}
 
 
			case 2:{   //新建联系人
 
 
					   link_malloc( &new_node );//空间分配
					   new_node->num=i;
					   i++;
 
					   printf("请输入姓名:");
					   scanf("%s",new_node->name);
					   printf("\n");
					   printf("请输入手机号码:");
					   scanf("%s",new_node->tel);
					   printf("\n");
					   printf("请输入邮箱:");
					   scanf("%s",new_node->Email);
					   printf("\n");
					   printf("请输入地址:");
					   scanf("%s",new_node->addr);
					   printf("\n");
					   node_sort(head,new_node,num);
					   printf("\n");
				       display_only(head,new_node->name);
					   printf("\n按回车键回到主菜单。");
					   getchar();getchar();
					   break;
 
				   }
			case 3:{
 
					   //删除
					   printf("\n输入你所要删除的人的姓名:");
					   scanf("%s",fullname);
					   SearchDel(head,fullname);
				       Del_play(head,fullname);
					   printf("\n按回车键回到主菜单。");
					   getchar();getchar();
					   break;
				   }
			case 4:{
 
					   //修改
					   printf("请输入要修改的姓名:");
					   scanf("%s",fullname);
					   searchpoint=Search(head,fullname);
					   printf("请输入新号码:");
					   scanf("%s",searchpoint->tel);
	                   printf("\n是否要修改地址(Y/N):");
					   getchar();
					   if(getchar()=='Y')
					   {    printf("请输入新的地址:");
						   scanf("%s",searchpoint->addr);
					   }
					   printf("\n是否要修改邮箱(Y/N):");
					   getchar();
					   if(getchar()=='Y')
					   {
						   printf("请输入新的邮箱:");
						   scanf("%s",searchpoint->Email);
						   printf("\n");
					   }
					   Tel_play(head,*&searchpoint->tel);
				       display_only(head,fullname);
					   printf("\n按回车键回到主菜单。");
					   getchar();getchar();
					   break;
				   }
			case 5:{
 
					   display_link( head );
					   printf("\n按回车键回到主菜单。");
					   getchar();getchar();
					   break;
				   }
			case 6: exit(-1);
					break;
		}
	}
	return 0;
}

