#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

//SSS, Name, Dept
struct node
{
	struct node *rlink;
	int SSN;
	char Name[10];
	char Dept[10];
	char Desig[10];
	float Sal;
	char PhNo[10];
	
	struct node *llink;
};
typedef struct node* NODE;
NODE Create (NODE,int);
NODE InsFront(NODE);
NODE InsRear (NODE);
NODE DelFront(NODE);
NODE DelRear (NODE);
void Display (NODE);
void ReadData(NODE first)
{
	printf("Enter SSN:\n");
	scanf("%d",& (first->SSN));
	printf("Enter Employee Name:");
	scanf("%s",(first->Name));
	printf("Enter EmployeeDepartment:");
	scanf("%s",(first->Dept));
	printf("Enter Designation:");
	scanf("%s",(first->Desig));
	printf("Enter Salary:");
	scanf("%f",&(first->Sal));
	printf("Enter Phone:");
	scanf("%s",(first->PhNo));
}

NODE get_node()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if (temp==NULL)
	{
		printf("no memory available in the heap segment\n");
		exit(0);	
	}
	return temp;
}
NODE InsFront(NODE first)
{
	NODE temp;
	temp=get_node();
	temp->llink=NULL;
	temp->rlink=NULL;
	ReadData(temp);
	if(first==NULL)
	{	
		temp->llink=NULL;
		temp->rlink=NULL;
	return temp;
	}
	else
	{
		temp->rlink=first;
		first->llink=temp;
		temp->llink=NULL;
		//Display(temp);
		return temp;
	}
	
}
NODE InsRear(NODE first)
{
	NODE temp, cur ,prev;
	temp=get_node();
	temp->llink=NULL;
	temp->rlink=NULL;
	ReadData(temp);
	if(first==NULL)
	{	
		temp->llink=NULL;
		temp->rlink=NULL;
	return temp;
	}
	else
	{
		cur=first;
		prev=NULL;
		while(cur->rlink!=NULL)
		{
			prev=cur;
			cur=cur->rlink;
		}
		cur->llink=prev;
		cur->rlink=temp;
		temp->llink=cur;
		temp->rlink=NULL;
		return first;
	}
}

NODE DelFront(NODE first)
{
	NODE next;
	if(first==NULL)
	{
		printf("Can't delete , list is empty\n");
		return NULL;
	}
	/*else if(first->link==NULL)
	{
		printf("The deleted info is\n usn=%d\n name=%s\n branch=%s\n sem=%d\n PhNo=%s\n",(first->usn),(first->Name),(first->Branch),(first->Sem),(first->PhNo));
		free(first);
		return NULL;
	}*/
	else
	{
		next=first->rlink;
		printf("The deleted info is\n SSN=%d\n Name=%s\n Department=%s\n Designation=%s\n Salary=%f\n PhNo=%s\n",(first->SSN),(first->Name),(first->Dept),(first->Desig),(first->Sal),(first->PhNo));
		free(first);
		if(next!=NULL)
		{
		next->rlink=NULL;
		}
		return next;
	}
}
NODE DelRear(NODE first)
{
	NODE cur,prev;
	if(first==NULL)
	{
		printf("Can'tdelete,listisempty\n");
		return	first;
	}
	/*else if(first->link==NULL)
	{
		printf("The deleted info is\n usn=%d\n name=%s\n branch=%s\n sem=%d\n PhNo=%s\n",(first->usn),(first->Name),(first->Branch),(first->Sem),(first->PhNo));
		free(first);
		return NULL;
	}*/
	else
	{
		//more than one node
		cur=first;
		while(cur->rlink!=NULL)
		{
			prev=cur;
			cur=cur->rlink;
		}
		if(prev!=NULL)
		{
			prev->rlink=NULL;
			printf("The deleted info is\n SSN=%d\n Name=%s\n Department=%s\n Designation=%s\n Salary=%f\n PhNo=%s\n",(first->SSN),(first->Name),(first->Dept),(first->Desig),(first->Sal),(first->PhNo));
			free(cur);
			return first;
		}
		else
		{
			free(first);
			return NULL;
		}
	}
}
	/*Displaysthecontentsofthelist*/
void Display(NODE first)
{
	int	count=0;
	NODE cur;
	if(first==NULL)
	{
		printf("no elements present in sll\n");
		return;
	}
	else
	{
		cur=first;
		while(cur!=NULL)
		{
			printf("The deleted info is\n SSN=%d\n Name=%s\n Department=%s\n Designation=%s\n Salary=%f\n PhNo=%s\n",(first->SSN),(first->Name),(first->Dept),(first->Desig),(first->Sal),(first->PhNo));
		cur=cur->rlink;
		count++;
		}
		printf("count of nodes=%d\n",count);
	}
}

NODE Create(NODE first,int n)
{
	int i;
	if(first==NULL)
	{
		for(i=1;i<=n;i++)
		{
			printf("EnterEmployeeData<%d>:\n",i);
			first=InsRear(first);
		}
	return first;
	
	}
	else 
	{	
		printf("List already has some student data\n");
		return first;
	}
}
void stack()
{	
	int ch;
	NODE top;
	top=NULL;
	while (1)
	{
		printf("1.PUSH\n2.POP\n3.Display\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: top=InsFront(top);
				break;
			case 2: top=DelFront(top);
				break;
			case 3: Display(top);
				break;
			default: return;
		}
	}
}
void queue()
{
	int ch;
	NODE first;
	first=NULL;
	while (1)
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: first=InsFront(first);
				break;
			case 2: first=DelRear(first);
				break;
			case 3: Display(first);
				break;
			default: return;
		}
	}
}
void deck()
{
	int ch;
	NODE first;
	first=NULL;
	while (1)
	{
		printf("1.Insert_front_end\n2.Delete_front_end\nInsert_Rear_end\nDelete_Rear_end\n3.Display\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: first=InsFront(first);
				break;
			case 2: first=DelRear(first);
				break;
			case 3: Display(first);
				break;
			default: return;
		}
	}
}
			 
void count(NODE first)
{
	int c=0;
	NODE cur=first;
	while(cur!=NULL)
	{
		cur=cur->rlink;
		c++;
	}
	printf("No of students=%d",c);
}
		
int main()
{
	int choice,done,ch;
	NODE first; /*FIRSTnode*/
	first=NULL;
	int n; /*no.ofstudents*/
	
	while(1)
	{
		printf("EnterChoice:");
		printf("\n1.Create\t\n2.Insert_Front\t3.Insert_Rear\t4.Delete_Front\n5.Delete_Rear\t6.Display\t7.Count\t8.implimentation\t9.Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("EnterNo.ofEmployees:\n");
				scanf("%d",&n);
				first=Create(first,n);
				break;
			case 2: first=InsFront(first);
				Display(first);
				break;
			case 3: first=InsRear(first);
				Display(first);
				break;

			case 4: first=DelFront(first);
				break;

			case 5: first=DelRear(first);
				break;
			case 6: Display(first);
				break;
			case 7: count(first);
				break;	
			case 8:	printf("1.implimentation as STACK\t2.implimentation as QUEUE\t3.implimentation as a Deck\n");
				scanf("%d",&ch);
				switch(ch)
				{
					case 1: stack();
						break;
					case 2: queue();
						break;
					case 3: deck();
						break;
				}
				break;
			default: exit(0);
		}
	}
}
