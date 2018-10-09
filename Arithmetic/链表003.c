#include <stdio.h>
#include <stdlib.h>

 
typedef struct polyNode{
    int coef;
    int exp;
    struct polyNode *next;
}polyNode, *polyList;
 
void DestroyList(polyList L);
 
void printList(polyList L);
 
polyList creatList(int n);
 
polyList add(polyList a, polyList b);
 
polyList mul(polyList a, polyList b);
 
int main()
{
    int n1, n2, i;
    polyList a, b, L1, L2;
 
    scanf("%d", &n1);
    a = creatList(n1);
    scanf("%d", &n2);
    b = creatList(n2);
 
    L1 = mul(a, b);
    L2 = add(a, b);
 
    printList(L1);
    printf("\n");
    printList(L2);
    DestroyList(L1);
    DestroyList(L2);
    //system("pause");
    ;
}
 
void DestroyList(polyList L)
{
    polyNode * tmp;
    while (L)
    {
        tmp = L->next;
        free(L);
        L = tmp;
    }
}
 
polyList creatList(int n)
{
    polyNode *head, *r, *p;
    int coef, exp;
    head = (polyNode *)malloc(sizeof(polyNode));
    r = head;
 
    while (n--)
    {
        scanf("%d%d", &coef, &exp);
        p = (polyNode *)malloc(sizeof(polyNode));
        p->coef = coef;
        p->exp = exp;
 
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return head;
}
 
polyList add(polyList a, polyList b)
{
    polyNode *ha, *hb, *p, *r, *h;
    int temp;
 
    ha = a->next;
    hb = b->next;
 
    h = (polyNode *)malloc(sizeof(polyNode));
    r = h;
 
    while (ha != NULL && hb != NULL)
    {
        p = (polyNode *)malloc(sizeof(polyNode));
        if (ha->exp < hb->exp)
        {
            p->exp = hb->exp;
            p->coef = hb->coef;
            hb = hb->next;
 
            r->next = p;
            r = p;
        }
        else if (ha->exp > hb->exp)
        {
            p->exp = ha->exp;
            p->coef = ha->coef;
            ha = ha->next;
 
            r->next = p;
            r = p;
        }
        else
        {
            temp = ha->coef + hb->coef;
            
            {
                p->exp = ha->exp;
                p->coef = temp;
 
                r->next = p;
                r = p;
            }
            ha = ha->next;
            hb = hb->next;
        }
    }
    while ( hb != NULL )
    {
        p = (polyNode *)malloc(sizeof(polyNode));
        p->exp = hb->exp;
        p->coef = hb->coef;
        hb = hb->next;
        r->next = p;
        r = p;
    }
    while ( ha != NULL )
    {
        p = (polyNode *)malloc(sizeof(polyNode));
        p->exp = ha->exp;
        p->coef = ha->coef;
        ha = ha->next;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    DestroyList(a);
    DestroyList(b);
    return h;
}
 
polyList mul(polyList a, polyList b)
{
    polyNode *ha, *hb , *r, *p;
    polyList c, tempc;
 
    ha = a->next;
    hb = b->next;
 
    c = (polyNode *)malloc(sizeof(polyNode));
    c->next = NULL;
 
    if (ha == NULL || hb == NULL)
    {
        return c;
    }
 
    while (ha != NULL)
    {
        tempc = (polyNode *)malloc(sizeof(polyNode));
        r = tempc;
        hb = b->next;
        while (hb != NULL)
        {
            p = (polyNode *)malloc(sizeof(polyNode));
            p->exp = ha->exp + hb->exp;
            p->coef = ha->coef * hb->coef;
 
            hb = hb->next;
            r->next = p;
            r = p;
        }
        r->next = NULL;
        c = add(c,tempc);
        ha = ha->next;
    }
    return c;
}
 
void printList(polyList L)
{
    polyNode * x;
    x = L->next;
    if (x == NULL)
    {
        printf("0 0");
    }
    while (x != NULL)
    {
        if (x->next == NULL)
        {
            printf("%d %d", x->coef, x->exp);
        }
        else
            printf("%d %d ", x->coef, x->exp);
        x = x->next;
    }
}
