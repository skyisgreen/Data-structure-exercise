#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct BiNode{
         char  data;
         struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

void InitBiTree(BiTree *B){
    *B= NULL;
}

void CreateBiTree(BiTree *b){
      char a ;
      scanf("%c",&a);
      if('*'== a){
        (*b)= NULL;
      }else{
            *b =(BiTree)malloc(sizeof(BiNode));
            (*b)->data = a;
            CreateBiTree(&(*b)->lchild);
            CreateBiTree(&(*b)->rchild);
      }
}

//��������
void  InOrderTraverse(BiTree B){
    if(B){
        printf("%c",B->data);
        InOrderTraverse(B->lchild);
        InOrderTraverse(B->rchild);
    }
}

int main()
{
    printf("��������������:");  //ABD***CE**FG***
    BiTree b;
    CreateBiTree(&b);
    printf("\nǰ��������Ϊ��");
    InOrderTraverse(b);
    return 0;}


