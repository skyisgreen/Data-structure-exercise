#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
typedef struct
{
char data[maxsize];
int top;
}sqstack,*Stack;
Stack initstack()
{
Stack s;
s=(Stack)malloc(sizeof(sqstack));
s->top=-1;
return s;
}
int push(Stack s,char ch)
{
if(s->top>=maxsize)
return 0;
else
{
s->data[++s->top]=ch;
return 1;
}
}
int pop(Stack s,char *ch)
{
if(s->top==-1)
return 0;
else
{
*ch=s->data[s->top--];
return 1;
}
}
void Convert (int n, char str[], unsigned p)//十进制数据n向p进制转换
{
Stack s;
int i=0;
s=initstack();
while(n)
{
if(n%p<10)
push(s,n%p+'0');
else
push(s,n%p+'A'-10);
n=n/p;
}
while(s->top!=-1)
pop(s,&str[i++]);
str[i]='\0';
}
int main()
{
int n;
char str[maxsize];
unsigned p;
printf("请输入数据n\n");
scanf("%d",&n);
printf("请输入数据p\n");
scanf("%d",&p);
Convert(n,str,p);
printf("%s\n",str);
return 0;
}
