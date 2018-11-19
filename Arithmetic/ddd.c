//ʵ��˳��ջ�ĳ�ջ��ȡջ��Ԫ�ز���
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#define  OVERFLOW -1
#define  OK 1
#define ERROR 0
#define STACK_INIT_SIZE 10			// �洢�ռ��ʼ������
#define STACKINCREMENT 2			// �洢�ռ��������
typedef int SElemType;
//ջ��˳��洢�ṹ

typedef struct SqStack

{

	SElemType *base;				// ��ջ����֮ǰ������֮��base��ֵΪNULL

	SElemType *top;					// ջ��ָ��

	int stacksize;					// ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ

}SqStack;



/*

 *����һ��ջ

 * */

int InitStack(SqStack *S)

{

	// Ϊջ�׷���һ��ָ����С�Ĵ洢�ռ�

	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));

	if( !(*S).base )

		exit(0);		// �洢����ʧ��

	(*S).top = (*S).base;	// ջ����ջ����ͬ��ʾһ����ջ

	(*S).stacksize = STACK_INIT_SIZE;

	return 1;

}



/*

 *��ȡջ��Ԫ��

 * */

int GetTop(SqStack S,SElemType *e)

{

	if(S.top > S.base)

	{

		*e = *(S.top-1);	// ջ��ָ�����һ��λ��Ϊջ��Ԫ��

		return 1;

	}

	else

		return 0;

}



/*

 *��ջ��ѹջ��

 * */

 /*��S.base��ָ��Ŀռ䣬ֻ����S.stacksize��Ԫ�ء����·���ռ�֮��
 �������ɡ�S.stacksize+STACKINCREMENT����Ԫ�أ���������չ��STACKINCREMENT��Ԫ�صĿռ䡣
 ÿ��Ԫ��ռ��SElemType��С�Ŀռ䡣*/

int Push(SqStack *S, SElemType e)

{

	if((*S).top - (*S).base >= (*S).stacksize)	// ջ����׷�Ӵ洢�ռ�

	{

		(*S).base = (SElemType *)realloc((*S).base,

			((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));

		if( !(*S).base )

			exit(0); // �洢����ʧ��

		(*S).top = (*S).base+(*S).stacksize;

		(*S).stacksize += STACKINCREMENT;

	}

	*((*S).top)++=e;

	// �����ʽ��++ * ���ȼ���ͬ���������ǵ����㷽ʽ������������

	return 1;

}





/*

 *��ջ

 * */

int Pop(SqStack *S,SElemType *e)

{

	if((*S).top == (*S).base)

		return 0;

	*e = *--(*S).top;

	return 1;

}



void main(){//������
	int n,e,i;
	SqStack s;

	InitStack(&s);//��ʼ��ջ

	printf("������ջ�ĳ���n\n");
	scanf("%d",&n);
	printf("������%d������\n",n);
	for(i=1;i<=n;i++){
		scanf("%d",&e);
		Push(&s,e);//��ջ
	}
	printf("\n");

	GetTop(s,&e);
    printf("ջ��Ԫ����:%d",e);

	Pop(&s,&e);
    GetTop(s,&e);
    printf("ջ��Ԫ����:%d",e);

}
