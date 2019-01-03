#pragma once
#define SIZE 20
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>s

typedef struct Str
{
    char elem[SIZE];//elem����������Ŵ���Ԫ��
    int length;//����һ��������
}Str;

void StrAssign(Str *s, const char *chars);//��ʼ����
void StrCpy(Str*s, Str*t);//������
int Getlength(Str *s);//��ȡ���ĳ���
void Clear(Str *s);//��մ�s
bool Inset(Str *s,int pos,Str *t);//�ڴ�s��posλ�ò��봮t
void Show(Str *s) ;//��ӡ��
int BF(Str *s,Str *sub,int pos);//�ڴ�s���ҵ�һ����sub�������ش�sub�ĵ�һ��Ԫ�ص��±�
bool DeletePos(Str* s,int pos,int len);//�ڴ��е�posλ�ÿ�ʼɾ��len���ȸ�Ԫ��
bool Delete(Str *s,int pos,Str *t);//�ڴ��е�posλ�ÿ�ʼɾ����t
bool Replace(Str *s,Str *t,Str *v,int pos);//��v�滻��posλ�ÿ�ʼ�ĵ�һ��t
bool RepIaceAll(Str *s,Str *t,Str *v);//�ڴ�s�в��ҵ���t���ô�v�滻




void StrAssign(Str *s, const char *chars)//��ʼ����
{
    assert(s != NULL);
    int len = strlen(chars);

    /*if(s->length<len)
    {
        return;
    }*/
    s->length = len;
    int i;
    for( i = 0;i<len;i++)
    {
        s->elem[i] = chars[i];
    }
}

void StrCpy(Str*s, Str*t)//������
{   int i;
    for( i = 0;i<t->length;i++)
    {
        s->elem[i] = t->elem[i];
    }
    s->length = t->length;
}

int Getlength(Str *s)//��ȡ���ĳ���
{
    return s->length ;
}

void Clear(Str *s)//��մ�s
{
    s->length = 0;
}

bool SubStr(Str *sub,Str *s,int pos,int len)//�հ��ַ�������
{
    if(pos < 0 || len < 1||pos >=s->length||pos+len>s->length-1)
    {
        return false;
    }
    int i;
    for( i = pos;i<pos+len;i++)
    {
        sub->elem[i-pos] = s->elem[i];
    }
    sub->length = len;
    return true;
}

bool Inset(Str *s,int pos,Str *t)//�ڴ�s��posλ�ò��봮t
{
    assert(s!=NULL);
    assert(t!=NULL);
    int i ,j;
    if(pos<0||pos>s->length||pos+t->length>SIZE)
    {
        return false;
    }
    for( i = s->length-1;i>=pos;i--)
    {
        s->elem[i+t->length] = s->elem[i];
    }
    for(j = 0;j<t->length;j++)
        {
            s->elem[j+pos] = t->elem[j];
        }
    s->length +=t->length;
    return true;
}
int BF(Str *s,Str *sub,int pos)//�ڴ�s���ҵ�һ����sub�������ش�sub�ĵ�һ��Ԫ�ص��±�
{
    if(pos<0||pos>s->length)
    {
        return -1;
    }

    int i = pos;
    int j = 0;

    int lens = s->length;
    int lensub = sub->length;

    while (i < lens && j < lensub)
    {
        if (s->elem[i] == sub->elem[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= lensub)
        {
            return i - j;
        }
        else
            return -1;
}

bool DeletePos(Str* s,int pos,int len)//��posλ�ÿ�ʼɾ��len������
{
    assert(s!=NULL);
    if(pos<0||pos+len>s->length||len<0)
    {
        return false;
    }
    //for(int i = pos;i<len+pos;i++)
    int i;
    for(i = pos;i<s->length-len;i++)
    {
        s->elem[i] = s->elem[i+len];
    }
    s->length -= len;
    return true;
}

bool Delete(Str *s,int pos,Str *t)//�ڴ��е�posλ�ÿ�ʼɾ����t
{
    assert(s!=NULL);
    assert(t!=NULL);
    if(pos<0||pos>s->length||t->length>s->length)
    {
        return false;
    }
    int index = BF(s,t,pos);
    if(index < 0)
    {
        return false;
    }
    return DeletePos(s,index,t->length);
}
bool Replace(Str *s,Str *t,Str *v,int pos)//��v�滻��posλ�ÿ�ʼ�ĵ�һ��t
{
    assert(s!=NULL);
    assert(t!=NULL);
    assert(v!=NULL);

    int index = BF(s,t,pos);
    if(index < 0)
    {
        return false;
    }
    DeletePos(s,index,t->length);
    return Inset(s,index,v);
}
bool RepIaceAll(Str *s,Str *t,Str *v)//�ڴ�s�в��ҵ���t���ô�v�滻
{
    assert(s!=NULL);
    assert(t!=NULL);
    assert(v!=NULL);

    while(Replace(s,t,v,0));
    return true;
}
void Show(Str *s) //��ӡ
{
    int i;
    for( i=0;i<Getlength(s);i++)
    {
        printf("%c",s->elem[i]);
    }
    printf("\n");
}


int main()
{
    Str s;
    char *s1 = "abcdecdfcd";
    StrAssign(&s, s1);
    Show(&s);

    Str t;
    char *t1 = "cd";
    StrAssign(&t, t1);
    Show(&t);

    Inset(&s, 2, &t);
    Show(&s);

    Inset(&s, 7, &t);
    Show(&s);

    int index = BF(&s,&t,0);
    printf("index = %d\n",index);

    DeletePos(&s,3,2);
    Show(&s);

    /*Str v;
    char *v1 = "zkr";
    StrAssign(&v, v1);
    Show(&v);
    Replace(&s,&t,&v,0);
    Show(&s);*/

    Str v;
    char *v1 = "zkr";
    StrAssign(&v, v1);
    Show(&v);
    RepIaceAll(&s,&t,&v);
    Show(&s);
    system("pause");
    return 0;
}

