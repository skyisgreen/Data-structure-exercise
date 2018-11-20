
//ջʵ�ֱ��ʽ

//˼·���˳����˼·�ǣ���ȡ������ַ�����Ȼ���ж�ÿ���ַ���

//�������������������ʱ���������ջ�����Ű�ջ��������Ԫ��

//��ջ��Ȼ�����㣬Ȼ���ٽ��õĽ��ѹջ


#include <stdio.h>

#include <stdlib.h>



typedef int SElemType;				// ջ��Ԫ������



#define STACK_INIT_SIZE 10			// �洢�ռ��ʼ������

#define STACKINCREMENT 2			// �洢�ռ��������



/*

 *˳��ջ�Ľṹ��

 * */

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

	// �����ʽ��++ * ���ȼ���ͬ���������ǵ����㷽ʽ������������

	return 1;

}







/*

 *�ж����ȼ�

 * */

SElemType Precede(SElemType t1,SElemType t2)

{

	SElemType f;

	switch(t2)

	{

	case '+':

	case '-':

		if(t1=='('||t1=='#')

			f='<';

		else

			f='>';

		break;

	case '*':

	case '/':

		if(t1=='*'||t1=='/'||t1==')')

			f='>';

		else

			f='<';

		break;

	case '(':

		if(t1==')')

		{

			printf("ERROR1\n");

			exit(0);

		}

		else

			f='<';

		break;

	case ')':

		switch(t1)

		{

		case '(':

			f='=';

			break;

		case '#':

			printf("ERROR2\n");

			exit(0);

		default:

			f='>';

		}

		break;

	case '#':

		switch(t1)

		{

		case '#':

			f='=';

			break;

		case '(':

			printf("ERROR3\n");

			exit(0);

		default:

			f='>';

		}

	}

	return f;

}







/*

 *���������

 * */

int In(SElemType c)

{

	switch(c)

	{

	case'+':

	case'-':

	case'*':

	case'/':

	case'(':

	case')':

	case'#':return 1;

	default:return 0;

	}

}



/*

 *����

 * */

SElemType Operate(SElemType a,SElemType theta,SElemType b)

{

	SElemType c;

	//a=a-48;												//ASCIIֵת��Ϊ��Ӧ��ʮ����ֵ

	//b=b-48;												//ASCIIֵת��Ϊ��Ӧ��ʮ����ֵ



	switch(theta)

	{

	case'+':

		c=a+b;

		break;

	case'-':

		c=a-b;

		break;

	case'*':

		c=a*b;

		break;

	case'/':c=a/b;

	}

	return c;

}



/*

 *�Ƚ���������ȼ�

 * */

SElemType EvaluateExpression()

{

	SqStack OPTR,OPND;

	SElemType a,b,c,x,theta;

	InitStack(&OPTR);

	Push(&OPTR,'#');

	InitStack(&OPND);

	c=getchar();

	GetTop(OPTR,&x);

	while(c!='#'||x!='#')

	{

		if(In(c)) // ��7�������֮һ

		switch(Precede(x,c))  //�Ƚ��������ʽ�����ȼ�

		{

         case'<':

			 Push(&OPTR,c); // ջ��Ԫ������Ȩ��

			 c=getchar();

			 break;

         case'=':

			 Pop(&OPTR,&x); // �����Ų�������һ�ַ�

			 c=getchar();

			 break;

         case'>':

			 Pop(&OPTR,&theta); // ��ջ������������ջ

			 Pop(&OPND,&b);

			 Pop(&OPND,&a);

			 Push(&OPND,Operate(a,theta,b));

			 break;

		}

		else if(c>='0'&&c<='9') // c�ǲ�����

		{

			Push(&OPND,c);

			c=getchar();

		}

		else	// c�ǷǷ��ַ�

		{

			printf("�Ƿ��ַ�����\n");

			exit(0);

		}



		GetTop(OPTR,&x);

	}

	GetTop(OPND,&x);

	return x;

}



int main()

{

	printf("�������������ʽ,����#����\n");

	printf("���磺3*(7-5)#\n");

	printf("%c\n",EvaluateExpression());

	return 0;

}



