#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct poly
{
	int cf,px,py,pz;
	struct poly * link;
};
typedef struct poly * POLY;
void add(POLY poly1, POLY poly2, POLY polysum);
POLY getnode()
{
	POLY temp;
	temp=(POLY)malloc(sizeof(struct poly));
	if(temp==NULL)
	{
		printf("Memory not allocated.\n");
		exit(0);
	}
	return temp;
}
void insert(POLY head,int cf,int px,int py,int pz)
{
	POLY first,temp;
	temp=getnode();
	temp->link=NULL;
	temp->cf=cf;
	temp->px=px;
	temp->py=py;
	temp->pz=pz;
	first=head->link;
	temp->link=first;
	head->link=temp;
}
void accept(POLY head)
{
	int i,terms,n,cf,px,py,pz;
	printf("enter no of terms\n");
	scanf("%d",&terms);
	for(i=0;i<terms;i++)
	{
		printf("enter coef, pow x,pow y,pow z\n");
		scanf("%d %d %d %d",&cf,&px,&py,&pz);
		insert(head,cf,px,py,pz);
	}
}


void display(POLY head)
{
	POLY cur = head->link;
	if(head->link==head)
	{
		printf("circular linked list empty\n");
		return;
	}
	printf("\n\n");
	printf("terms of polynomial are\n");
	while(cur!=head)
	{
		if(cur->cf<0)
		{
			printf("%dx^%dy^%dz^%d",cur->cf,cur->px,cur->py,cur->pz);
		
		}
		else
		{	
			printf("+%dx^%dy^%dz^%d",cur->cf,cur->px,cur->py,cur->pz);
			
		}
		cur=cur->link;
	}
	printf("\n\n");
}

POLY search_pow(POLY term, POLY poly2)
{
	POLY cur = poly2->link;
	while(cur!=poly2)
	{
		if(cur->px==term->px && cur->py==term->py && cur->pz==term->pz)
			return cur;
		cur=cur->link;
	}
	return NULL;
}
void add_poly(POLY poly1, POLY poly2, POLY polysum)
{
	POLY cur, index,pos;
	index=poly1->link;
	while(index!=poly1)
	{
		pos=search_pow(index,poly2);
		if(pos==NULL)
			insert(polysum,index->cf,index->px, index->py, index->pz);
		else
		{
			insert(polysum,index->cf+pos->cf,index->px, index->py, index->pz);
			pos->cf=-999;
			
		}
		index=index->link;
	}
	cur=poly2->link;
	
	while(cur!=poly2)
	{
		if(cur->cf!=-999)
			insert(polysum,cur->cf,cur->px, cur->py, cur->pz);
		cur=cur->link;
	}
	
}

void evaluate(POLY p)
{
	double res=0,x,y,z,val=1;
	POLY index=p->link;
	printf("\nEnter the values of x,y,z:");
	scanf("%lf%lf%lf",&x,&y,&z);
	while(index!=p)
	{
		val=(index->cf)*pow(x,index->px)*pow(y,index->py)*pow(z,index->pz);
		res+=val;
		index=index->link;
	}
	printf("\nResult=%lf\n",res);
}
int main()
{
	POLY poly1,poly2,polysum,p;
	poly1=getnode();
	poly1->link=poly1;
	poly2=getnode();
	poly2->link=poly2;
	polysum=getnode();
	polysum->link=polysum;
	p=getnode();
	p->link=p;
	int ch;
	while(1)
	{
		printf("\n1.evaluate of the polynomial\n2.sum of two polynomial\n3.exit\n");
		printf("\nenter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nenter the polynomial\n");
				accept(p);
				display(p);
				evaluate(p);
			      break;
			case 2:printf("\nenter the polynomial 1\n");
				accept(poly1);
				display(poly1);
				printf("\nenter the polynomial 2\n");
			       accept(poly2);
			       display(poly2);
			       add_poly(poly1,poly2,polysum);
			       printf("\nresultant polynomial is\n");
			      display(polysum);
			       break;
			default:exit(0);
		}
	}
}

