#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
 {
	char a[101];
	char s[101];//stack
	int i,len,mid,next,top;
	
	gets(a);//��ȡһ���ַ���
	len=strlen(a);//���ַ����ĳ���
	mid=len/2-1;//���ַ������е�
	
	top=0;//stack�ĳ�ʼ��
	
	//��midǰ���ַ�������stack
	for(i=0;i<=mid;i++)
		s[++top]=a[i]; 
		
		
	 //�ж��ַ����ĳ�������������ż�������ҳ���Ҫ�����ַ���ƥ�����ʼ�±� 
	if(len%2==0)
	   next=mid+1;
	else
	   next=mid+2;//??
	   
	//��ʼƥ��
	for(i=next;i<=len-1;i++)
	{
		if(a[i]!=s[top])
		 break;
		 top--;
		 
	   }   
	   
	if(top==0)
	   printf("Yes");
	else
	   printf("No"); 
	
	getchar();getchar(); 
	return 0;
}
