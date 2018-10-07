#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct queue
{
	int data[100];//队列的主体，用来存储内容
	int head;//队首
	int tail;//队尾 
};
 

int main(int argc, char *argv[]) {
	struct queue q;
	int i;
	//初始化队列
	q.head=1;
	q.tail=1;
	for(i=1;i<=9;i++)
	{
		//依次向队列插入9个数
		
		scanf("%d",&q.data[q.tail]); 
		q.tail++;
		
	} 
	
	while(q.head<q.tail){
		
		printf("%d",&q.data[q.head]);
		q.head++;
		
		q.data[q.
		tail]=q.data[q.head];
		q.tail++;
		q.head++;
		
	}
	
	
	return 0;
}
