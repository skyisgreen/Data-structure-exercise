#include <iostream>

#include<stdlib.h>



typedef struct node *ptrNode;

typedef ptrNode LinkList;  //头结点

typedef ptrNode Position;//中间节点

typedef int ElementType;

struct node{

	ElementType Coefficient;

	ElementType Exponent;

	Position next;

};



int IsEmpty(LinkList L)

{

	return L->next == NULL;

}



LinkList creatList(int n)

{

	LinkList head,r,p;

	int coe,exp;

	head = (struct node*)malloc(sizeof(struct node));    //生成新结点

	r = head;



	while(n--){

        scanf("%d%d",&coe,&exp);

		p = (struct node*)malloc(sizeof(struct node));

		p->Coefficient = coe;

        p->Exponent = exp;

		r->next = p;

		r = p;

	}

	r->next = NULL;

	return head;

}



LinkList add_List(LinkList a, LinkList b)

{

	Position ha, hb;

	LinkList c,r,p;

	int temp;



	ha = a->next;

	hb = b->next;



	c = (struct node*)malloc(sizeof(struct node));

	r = c;

	while((ha != NULL)&&(hb != NULL)){

		p = (struct node*)malloc(sizeof(struct node));

		if(ha->Exponent < hb->Exponent){

			p->Exponent = hb->Exponent;

			p->Coefficient = hb->Coefficient;

			hb = hb->next;

            r->next = p;

            r = p;

		}

		else if(ha->Exponent > hb->Exponent){

			p->Exponent = ha->Exponent;

			p->Coefficient = ha->Coefficient;

			ha = ha->next;

            r->next = p;

            r = p;

		}

		else{

            temp = ha->Coefficient + hb->Coefficient;

            if(temp != 0){

                p->Exponent = ha->Exponent;

                p->Coefficient = temp;

                r->next = p;

                r = p;

            }

            hb = hb->next;

            ha = ha->next;

        }

	}

	if(ha == NULL){

		while(hb != NULL){

			p = (struct node*)malloc(sizeof(struct node));

			p->Exponent = hb->Exponent;

			p->Coefficient = hb->Coefficient;

			hb = hb->next;

			r->next = p;

		    r = p;

		}

	}

	if(hb == NULL){

		while(ha != NULL){

			p = (struct node*)malloc(sizeof(struct node));

			p->Exponent = ha->Exponent;

			p->Coefficient = ha->Coefficient;

			ha = ha->next;

			r->next = p;

		    r = p;

		}

	}



	r->next = NULL;

	return c;

}





LinkList mul_List(LinkList a, LinkList b)

{

	Position ha, hb;

	LinkList c,tempC,r,p;

	ha = a->next;

    hb = b->next;

	//c = (struct node*)malloc(sizeof(struct node));

	//c->next = NULL;

    c = creatList(0);

	if(ha == NULL || hb == NULL){

        return c;

	}



	while(ha != NULL ){

        tempC = (struct node*)malloc(sizeof(struct node));

        r = tempC;

        hb = b->next;

        while(hb != NULL){

            p = (struct node*)malloc(sizeof(struct node));

            p->Exponent = ha->Exponent + hb->Exponent;

            p->Coefficient = ha->Coefficient*hb->Coefficient;

			hb = hb->next;

            r->next = p;

            r = p;

        }

        r->next = NULL;

        c = add_List(c,tempC);


        ha = ha->next;

	}

	return c;



}

void printList(LinkList L)

{

	LinkList hc;

	int flag = 0;



	hc = L->next;

	if(hc == NULL)

		printf("0 0");

	while(hc != NULL){

		if(flag)

			printf(" ");

		else

			flag = 1;

		printf("%d %d",hc->Coefficient,hc->Exponent);

		hc = hc->next;

	}

}



int main(void)

{

    int n1,n2;

	LinkList L1,L2,L3,L4;



    scanf("%d",&n1);

	L1 = creatList(n1);

	scanf("%d",&n2);

	L2 = creatList(n2);



	L3 = add_List(L1,L2);

    L4 = mul_List(L1,L2);

	printList(L4);

	printf("\n");

	printList(L3);



	return 0;

}
