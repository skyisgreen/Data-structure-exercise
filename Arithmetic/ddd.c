//实现顺序栈的出栈，取栈顶元素操作
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#define  OVERFLOW -1
#define  OK 1
#define ERROR 0
#define STACK_INIT_SIZE 10			// 存储空间初始分配量
#define STACKINCREMENT 2			// 存储空间分配增量
typedef int SElemType;
//栈的顺序存储结构

typedef struct SqStack

{

	SElemType *base;				// 在栈构造之前和销毁之后，base的值为NULL

	SElemType *top;					// 栈顶指针

	int stacksize;					// 当前已分配的存储空间，以元素为单位

}SqStack;



/*

 *构造一个栈

 * */

int InitStack(SqStack *S)

{

	// 为栈底分配一个指定大小的存储空间

	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));

	if( !(*S).base )

		exit(0);		// 存储分配失败

	(*S).top = (*S).base;	// 栈底与栈顶相同表示一个空栈

	(*S).stacksize = STACK_INIT_SIZE;

	return 1;

}



/*

 *获取栈顶元素

 * */

int GetTop(SqStack S,SElemType *e)

{

	if(S.top > S.base)

	{

		*e = *(S.top-1);	// 栈顶指针的下一个位置为栈顶元素

		return 1;

	}

	else

		return 0;

}



/*

 *入栈（压栈）

 * */

 /*由S.base所指向的空间，只容纳S.stacksize个元素。重新分配空间之后，
 可以容纳“S.stacksize+STACKINCREMENT”个元素，就是新拓展了STACKINCREMENT个元素的空间。
 每个元素占据SElemType大小的空间。*/

int Push(SqStack *S, SElemType e)

{

	if((*S).top - (*S).base >= (*S).stacksize)	// 栈满，追加存储空间

	{

		(*S).base = (SElemType *)realloc((*S).base,

			((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));

		if( !(*S).base )

			exit(0); // 存储分配失败

		(*S).top = (*S).base+(*S).stacksize;

		(*S).stacksize += STACKINCREMENT;

	}

	*((*S).top)++=e;

	// 这个等式的++ * 优先级相同，但是它们的运算方式，是自右向左

	return 1;

}





/*

 *出栈

 * */

int Pop(SqStack *S,SElemType *e)

{

	if((*S).top == (*S).base)

		return 0;

	*e = *--(*S).top;

	return 1;

}



void main(){//主函数
	int n,e,i;
	SqStack s;

	InitStack(&s);//初始化栈

	printf("请输入栈的长度n\n");
	scanf("%d",&n);
	printf("请输入%d个数据\n",n);
	for(i=1;i<=n;i++){
		scanf("%d",&e);
		Push(&s,e);//入栈
	}
	printf("\n");

	GetTop(s,&e);
    printf("栈顶元素是:%d",e);

	Pop(&s,&e);
    GetTop(s,&e);
    printf("栈顶元素是:%d",e);

}
