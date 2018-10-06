#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int q[20]={0,6,3,1,7,5,8,9,2,4};
	int head;
	int tail;
	
	//初始化队列
	head = 1;
	tail = 10;
	
	while(head<tail)//队列不为空时执行循环 
	{
		//打印队首并将队首出列
		printf("%d",q[head]); 
		head++;
		
		//将队首的数字添加到队尾
		q[tail]=q[head];
		tail++;//队尾增加一个数 
		head++; 
		
	}
	return 0;
}
