#include <iostream>
using namespace std;
 
struct Node
{
    int coef;
    int exp;
    Node *next;
};
 
//��ʼ��
void InitList(Node * &L)
{
    L = new Node;
    L->next = NULL;
    L->coef = 0;
    L->exp = 0;
}
 
//�ڶ���ʽ����ĵ�i��λ�ò����� 
void InsertNode(Node *& L, int c, int e, int i)
{
    Node *p, *q; int j = 1;
    q = new Node;
    q->coef = c;
    q->exp = e;
    q->next = NULL;
 
    p = L;
    while (j <= i)
    {
        p = p->next;
        ++j;
    }
    q->next = p->next;
    p->next = q;
}
 
//��ָ���ǵݼ�������ʽ����
void SortList(Node *&L)
{
    Node *p, *q, *pre;
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        if (L->next == NULL)       //�����һ�����  
        {
            L->next = p;
            p = p->next;
            L->next->next = NULL;
        }
        else         //����ʣ���������  
        {
            pre = L;
            q = pre->next;
            while (q && q->exp < p->exp)
            {
                pre = q;
                q = q->next;
            }
            q = p->next;
            p->next = pre->next;
            pre->next = p;
            p = q;
        }
    }
}
 
void print(Node * L)
{
    SortList(L);
    Node *p;
    p = L->next;
    while (p != NULL)
    {
        cout << p->coef << "x^" << p->exp << "+";
        p = p->next;
    }
    cout << endl;
}
 
Node *AddPoly(Node *L1, Node *L2)       //һԪ����ʽ���  
{
    Node *pa, *pb, *s, *pc, *p;
    Node *tc;    //����β�ڵ�  
    pc = new Node;
    pc->next = NULL;    /*pcΪ�½��������ͷ���*/
    tc = pc;   /*tcʼ��ָ���½�������������*/
    pa = L1->next;
    pb = L2->next;   //��ö���ʽ������ĵ�һ�����  
    while (pa != NULL && pb != NULL)    //pa,pb����Ϊ�գ��ͽ��бȽϣ���������while  
    {
        if (pa->exp < pb->exp)         //��*pa��㸴�Ƶ�*s������pcβ  
        {
            s = new Node;
            s->coef = pa->coef;
            s->exp = pa->exp;
            s->next = NULL;
            tc->next = s;
            tc = s;
            pa = pa->next;
        }
        else if (pa->exp > pb->exp)      //��*pb��㸴�Ƶ�*s������pcβ  
        {
            s = new Node;
            s->coef = pb->coef;
            s->exp = pb->exp;
            s->next = NULL;
            tc->next = s;
            tc = s;
            pb = pb->next;
        }
        else         //pa->expn=pa->expnʱ�����  
        {
            if (pa->coef + pb->coef != 0)     //������ϵ��֮�Ͳ�Ϊ0�����½�����tc����  
            {
                s = new Node;
                s->coef = pa->coef + pb->coef;
                s->exp = pa->exp;
                s->next = NULL;
                tc->next = s;
                tc = s;
            }
            pa = pa->next;   //������ǰ�Ľ�㣬��������Ľ��ıȽ�  
            pb = pb->next;
        }
    }
    //����δɨ��������½�㸴�Ʋ����ӵ�pc������֮��  
    if (pa != NULL)        //pbΪ��     
        p = pa;
    else                  //paΪ��  
        p = pb;
    while (p != NULL)
    {
        s = new Node;
        s->coef = p->coef;
        s->exp = p->exp;
        s->next = NULL;
        tc->next = s;
        tc = s;
        p = p->next;
    }
    return pc;
}
 
int main()
{
    int c1[] = { 3, 7, 9, 5 }, c2[] = { 8, 22, -9 };
    int e1[] = { 2, 1, 8, 7 }, e2[] = { 9, 0, 8 };
 
    Node *la, *lb, *lc; int k;
    InitList(la);
    InitList(lb);
    InitList(lc);
    for (k = 0; k < 4; k++)
        InsertNode(la, c1[k], e1[k], k);
    for (k = 0; k < 3; k++)
        InsertNode(lb, c2[k], e2[k], k);
    cout << "����ʽA��";
    print(la);
    cout << "����ʽB��";
    print(lb);
 
    cout << "����ʽ��ӵĽ��Ϊ��" << endl;
    lc = AddPoly(la, lb);
    print(lc);
 
    return 0;
 
}

