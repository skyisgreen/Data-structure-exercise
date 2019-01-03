#pragma once
#define SIZE 20
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>s

typedef struct Str
{
    char elem[SIZE];//elem数组用来存放串的元素
    int length;//定义一个串长度
}Str;

void StrAssign(Str *s, const char *chars);//初始化串
void StrCpy(Str*s, Str*t);//拷贝串
int Getlength(Str *s);//获取串的长度
void Clear(Str *s);//清空串s
bool Inset(Str *s,int pos,Str *t);//在串s的pos位置插入串t
void Show(Str *s) ;//打印串
int BF(Str *s,Str *sub,int pos);//在串s里找第一个串sub，并返回串sub的第一个元素的下标
bool DeletePos(Str* s,int pos,int len);//在串中的pos位置开始删除len长度个元素
bool Delete(Str *s,int pos,Str *t);//在串中的pos位置开始删除串t
bool Replace(Str *s,Str *t,Str *v,int pos);//用v替换从pos位置开始的第一个t
bool RepIaceAll(Str *s,Str *t,Str *v);//在串s中查找到串t并用串v替换




void StrAssign(Str *s, const char *chars)//初始化串
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

void StrCpy(Str*s, Str*t)//拷贝串
{   int i;
    for( i = 0;i<t->length;i++)
    {
        s->elem[i] = t->elem[i];
    }
    s->length = t->length;
}

int Getlength(Str *s)//获取串的长度
{
    return s->length ;
}

void Clear(Str *s)//清空串s
{
    s->length = 0;
}

bool SubStr(Str *sub,Str *s,int pos,int len)//空白字符不拷贝
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

bool Inset(Str *s,int pos,Str *t)//在串s的pos位置插入串t
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
int BF(Str *s,Str *sub,int pos)//在串s里找第一个串sub，并返回串sub的第一个元素的下标
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

bool DeletePos(Str* s,int pos,int len)//从pos位置开始删除len个长度
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

bool Delete(Str *s,int pos,Str *t)//在串中的pos位置开始删除串t
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
bool Replace(Str *s,Str *t,Str *v,int pos)//用v替换从pos位置开始的第一个t
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
bool RepIaceAll(Str *s,Str *t,Str *v)//在串s中查找到串t并用串v替换
{
    assert(s!=NULL);
    assert(t!=NULL);
    assert(v!=NULL);

    while(Replace(s,t,v,0));
    return true;
}
void Show(Str *s) //打印
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

