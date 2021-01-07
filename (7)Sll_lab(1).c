//program to perform polynomial addition & evaluation using header SCLL
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
	int cf,px,py,pz;
	struct poly *link;
};
typedef struct poly * POLY;
void evaluate(POLY P);
void insert(POLY head,int cf,int px,int py,int pz);
void accept(POLY head);
void display(POLY head);
POLY getnode();
POLY search_pow(POLY poly2,POLY term);
void add_poly(POLY poly1,POLY poly2,POLY polysum);
int main()
{
	int ch;
	POLY poly1,poly2,polysum,P;
	poly1=getnode();
	poly1->link=poly1;
	poly2=getnode();
	poly2->link=poly2;
	polysum=getnode();
	polysum->link=polysum;
	P=getnode();
	P->link=P;
	while(1)
	{
		printf("Enter the choice:\n1-Evaluate\n2-Add 2 polynomial\n3-exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the poly P\n");
				accept(P);
				evaluate(P);
				break;
			case 2: printf("Enter poly1\n");
				accept(poly1);
				printf("Enter poly2\n");
				accept(poly2);
				add_poly(poly1,poly2,polysum);
				break;
			default:exit(0);
		}
	}
}
void insert(POLY head,int cf,int px,int py,int pz)
{
	POLY first,temp;
	temp=getnode();
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
	int i,n,cf,px,py,pz;
	printf("enter no. of terms\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter cf,px,py,pz\n");
		scanf("%d%d%d%d",&cf,&px,&py,&pz);
		insert(head,cf,px,py,pz);
	}
}
void display(POLY head)
{
	POLY cur;
	cur=head->link;
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
}
POLY getnode()
{
	POLY temp;
	temp=(POLY) malloc(sizeof(struct poly));
	if(temp==NULL)
	{
		printf("no memory available in the heap segment\n");
		exit(0);
	}
	return temp;
}
POLY search_pow(POLY poly2,POLY term)
{
	POLY cur=poly2->link;
	while(cur!=poly2)
	{
		if((term->px==cur->px)&&(term->py==cur->py)&&(term->pz==cur->pz))
		{
			return cur;
		}
		cur=cur->link;
	}
	return NULL;
}
void add_poly(POLY poly1,POLY poly2,POLY polysum)
{
	POLY index=poly1->link,cur,pos;
	printf("POLY1(x,y,z)= ");
	display(poly1);
	printf("\nPOLY2(x,y,z)= ");
	display(poly2);
	while(index!=poly1)
	{
		pos=search_pow(poly2,index);
		if(pos==NULL)
		{
			insert(polysum,index->cf,index->px,index->py,index->pz);
		}
		else
		{
			insert(polysum,index->cf+pos->cf,index->px,index->py,index->pz);
			pos->cf=-999;
		}
		index=index->link;
	}
	cur=poly2->link;
	while(cur!=poly2)
	{
		if(cur->cf!=-999)
		{
			insert(polysum,cur->cf,cur->px,cur->py,cur->pz);
		}
		cur=cur->link;
	}
	printf("\nsum of POLY1 & POLY2=POLYSUM(x,y,z)= ");
	display(polysum);
	printf("\n");
}
void evaluate(POLY P)
{
	POLY cur;
	double res,x,y,z;
	printf("Enter the values of x,y &z\n");
	scanf("%lf%lf%lf",&x,&y,&z);
	res=0;
	cur=P->link;
	while(cur!=P)
	{
		res+=(cur->cf)*pow(x,cur->px)*pow(y,cur->py)*pow(z,cur->pz);
		cur=cur->link;
	}
	printf("P(x,y,z)= ");
	display(P);
	printf("\n");
	printf("result of evaluation of P(x,y,z)=%lf\n",res);
}
	
