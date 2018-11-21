#include <iostream>
using namespace std;
 
struct Node
{
    int coef;
    int exp;
    Node *next;
};
 
//初始化
void InitList(Node * &L)
{
    L = new Node;
    L->next = NULL;
    L->coef = 0;
    L->exp = 0;
}
 
//在多项式链表的第i个位置插入结点 
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
 
//按指数非递减给多项式排序
void SortList(Node *&L)
{
    Node *p, *q, *pre;
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        if (L->next == NULL)       //处理第一个结点  
        {
            L->next = p;
            p = p->next;
            L->next->next = NULL;
        }
        else         //处理剩余其他结点  
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
 
Node *AddPoly(Node *L1, Node *L2)       //一元多项式相加  
{
    Node *pa, *pb, *s, *pc, *p;
    Node *tc;    //创建尾节点  
    pc = new Node;
    pc->next = NULL;    /*pc为新建单链表的头结点*/
    tc = pc;   /*tc始终指向新建单链表的最后结点*/
    pa = L1->next;
    pb = L2->next;   //获得多项式单链表的第一个结点  
    while (pa != NULL && pb != NULL)    //pa,pb都不为空，就进行比较，否则，跳出while  
    {
        if (pa->exp < pb->exp)         //将*pa结点复制到*s并链到pc尾  
        {
            s = new Node;
            s->coef = pa->coef;
            s->exp = pa->exp;
            s->next = NULL;
            tc->next = s;
            tc = s;
            pa = pa->next;
        }
        else if (pa->exp > pb->exp)      //将*pb结点复制到*s并链到pc尾  
        {
            s = new Node;
            s->coef = pb->coef;
            s->exp = pb->exp;
            s->next = NULL;
            tc->next = s;
            tc = s;
            pb = pb->next;
        }
        else         //pa->expn=pa->expn时的情况  
        {
            if (pa->coef + pb->coef != 0)     //如果相加系数之和不为0，则将新结点插在tc后面  
            {
                s = new Node;
                s->coef = pa->coef + pb->coef;
                s->exp = pa->exp;
                s->next = NULL;
                tc->next = s;
                tc = s;
            }
            pa = pa->next;   //跳过当前的结点，继续后面的结点的比较  
            pb = pb->next;
        }
    }
    //将尚未扫描完的余下结点复制并链接到pc单链表之后  
    if (pa != NULL)        //pb为空     
        p = pa;
    else                  //pa为空  
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
    cout << "多项式A：";
    print(la);
    cout << "多项式B：";
    print(lb);
 
    cout << "多项式相加的结果为：" << endl;
    lc = AddPoly(la, lb);
    print(lc);
 
    return 0;
 
}

