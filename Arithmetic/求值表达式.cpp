#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>             // �����ڴ�
#include <ctype.h>              // �ں�isdigit()����
#include <assert.h>             // ���Ժ���
#include <string.h>             // �ں��ַ���������
#define STACK_INIT_SIZE 100     // ջ����
#define STACK_INCREMENT 10      // ջ����
 
typedef float DATATYPE;
typedef char SYMBOLTYPE;
 
typedef struct stack
{
    int *base;         // ����ַ
    int *top;          // ջ��ָ��
    int stackSize;          // ջ����
}*Stack;
 
// ջ�ĳ�ʼ��
Stack Init_Stack(Stack S)
{
    S=(Stack)malloc(sizeof(Stack));
    if(!S)
        exit(0);
    S->base = (int*)malloc(STACK_INIT_SIZE*sizeof(DATATYPE));
    if(!S->base)
        exit(0);
    S->top = S->base;
    S->stackSize = STACK_INIT_SIZE;
    return S;
}
 
// ��ջ��
int IsEmpty(Stack S)
{
    if (S->top == S->base)
    {
        return 1;
    } else
    {
        return 0;
    }
}
 
// ��ջ��
int IsFull(Stack S)
{
    if (S->top - S->base == S->stackSize)
    {
        return 1;
    } else
    {
        return 0;
    }
}
 
// ������ѹջ
void Push(Stack S, DATATYPE e)
{
    assert(S);
    if (IsFull(S))
    {
        S->base = (int*)malloc((STACK_INIT_SIZE+STACK_INCREMENT)*sizeof(DATATYPE));
        if (!S->base)
            exit(0);        // �洢����ʧ��
        S->top = S->base + S->stackSize;
        S->stackSize += STACK_INCREMENT;
    }
    *S->top++ = e;
}
 
// �����ѹջ
void PushSymbol(Stack S, SYMBOLTYPE e)
{
    assert(S);
    if (IsFull(S))
    {
        S->base = (int*)malloc((STACK_INIT_SIZE+STACK_INCREMENT)*sizeof(DATATYPE));
        if (!S->base)
            exit(0);        // �洢����ʧ��
        S->top = S->base + S->stackSize;
        S->stackSize += STACK_INCREMENT;
    }
    *S->top++ = e;
}
 
// ��������ջ
DATATYPE Pop(Stack S)
{
    assert(S);
    if (S->top == S->base)
        return 0;              // ��ջ����0��֤���ָ�������ȷ����
    else
    {
        return *--S->top;     // *--S->top����*(--S->top)
    }
}
 
// �������ջ
SYMBOLTYPE PopSymbol(Stack S)
{
    assert(S);
    if (S->top == S->base)
        return 0;
    else
    {
        return *--S->top;
    }
}
 
// ջ������
void DestroyStack(Stack S) {
      free(S->base);
      free(S);
}
 
// ��������ȼ���
char Priority[7][7] =
{           // '+' '-' '*' '/' '(' ')' '#'          ��row����ߵģ���ջ�����������col���ϱߵģ�����ջ�����
   {/*'+'*/'>','>','<','<','<','>','>'},
    {/*'-'*/'>','>','<','<','<','>','>'},
    {/*'*'*/'>','>','>','>','<','>','>'},
    {/*'/'*/'>','>','>','>','<','>','>'},
    {/*'('*/'<','<','<','<','<','=','0'},
    {/*')'*/'>','>','>','>','0','>','>'},
   {/*'#'*/'<','<','<','<','<','0','='}
};
 
// ȷ����������ڵ�����������
int Operator(char c)
{
    switch(c)
    {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '(': return 4;
        case ')': return 5;
        case '#': return 6;
        default:  return -1;
    }
}
 
// ���㵯���������������뵯��ջ���������ֵ
float Calculation(float a, char op, float b)
{
    switch(op)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default:  return -1;
    }
}
 
// ���ʽ��ֵ����
float CalculatingExpression(char *s)
{
    int i;
    strcat(s, "#");                 // Ϊ���ʽs����"#"
    Stack OPND=NULL;
    OPND = Init_Stack(OPND);        // ����������ջ
    Stack OPTR=NULL;
    OPTR = Init_Stack(OPTR);        // ���������ջ
    PushSymbol(OPTR, '#');          //"#"ѹջ��Ϊ�����ջ��ջ��Ԫ��
    for (i=0; i<strlen(s); ++i)
    {
        while(s[i]==' ')            // whileѭ�������ո�
            ++i;
        if (isdigit(s[i]))          // �ж��Ƿ�������
        {
            int j=i;
            ++i;
            while(isdigit(s[i]))        // ȷ���Ǽ�λ��
            {
                ++i;
            }
            if (!isdigit(s[i]))     // ��whileѭ�������ж��Ƿ������ֶ�ӵ�iֵ��ȥ
                --i;
            char str[10]="";
            for (; j<=i; ++j)           // ���ַ��������±�j��i�������ַ�ת��Ϊ�ַ���
            {
                char c[2] = {s[j]};
                strcat(str, c);
            }
            float operand = atof(str);  // ���ַ���ת��Ϊ������
            Push(OPND, operand);        // ������ѹ�������ջ
        }
 else {
            int row = Operator(*(OPTR->top-1)), col = Operator(s[i]);       // ȷ��ջ�����������������ջ�����������
            switch(Priority[row][col])              // ȷ�����ȼ�
            {
                case '<': PushSymbol(OPTR, s[i]); break;
                case '>': Push(OPND, Calculation(Pop(OPND), PopSymbol(OPTR), Pop(OPND))); --i; break;       
                             //Push()�������ұߵ�Pop��ִ�У�--i��Ϊ���´μ����Ե�ǰ��ջ�����s[i]�����ж�
                case '=': PopSymbol(OPTR); break;
                default:  printf("���������������֮���Ƿ��пո񣬱��ʽ�Ƿ���ȷ��\n");
                          DestroyStack(OPTR);
                          DestroyStack(OPND);
                          return -4294967296;           // ���е���һ����˵�����ʽ����ֱ�ӷ��ص��ú�������������
            }
        }
    }
    DestroyStack(OPTR);
    return Pop(OPND);       // ���е���һ����˵�����ʽ��ȷ������������ջ��ֵ��Ϊ������
}
 
int main()
{
    char s[100];
    printf("������Ҫ����ı��ʽ��\n");
    gets(s);
    printf("���ʽ %s ��ֵΪ��\n", s);
    printf("%1.2f", CalculatingExpression(s));
 
    return 0;
}

