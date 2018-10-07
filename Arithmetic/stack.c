#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
 {
	char a[101];
	char s[101];//stack
	int i,len,mid,next,top;
	
	gets(a);//读取一行字符串
	len=strlen(a);//求字符串的长度
	mid=len/2-1;//求字符串的中点
	
	top=0;//stack的初始化
	
	//将mid前的字符依次入stack
	for(i=0;i<=mid;i++)
		s[++top]=a[i]; 
		
		
	 //判断字符串的长度是奇数还是偶数，并找出需要进行字符串匹配的起始下标 
	if(len%2==0)
	   next=mid+1;
	else
	   next=mid+2;//??
	   
	//开始匹配
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
