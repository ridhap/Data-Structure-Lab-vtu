#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

//USN,Name,Branch,Sem,PhNo
struct node
{
	int usn;
	char Name[11];
	char Branch[20];
	int Sem;
	char PhNo[20];
	struct node *link ;
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
	printf("EnterStudentUSN:\n");
	scanf("%d",&(first->usn));
	printf("EnterStudentName:\n");
	scanf("%s",(first->Name));
	printf("EnterStudentBranch:\n");
	scanf("%s",(first->Branch));
	printf("EnterSemester:\n");
	scanf("%d",& (first->Sem));
	printf("EnterStudentPhone:\n");
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
	temp->link=NULL;
	ReadData(temp);
	if(first==NULL)
		return temp;
	else
	{
		temp->link=first;
		Display(temp);
		return temp;
	}
	
}
NODE InsRear(NODE first)
{
	NODE temp, cur ,prev;
	temp=get_node();
	temp->link=NULL;
	ReadData(temp);
	if(first==NULL)
		return NULL;
	else if(first->link==NULL)
	{
		first->link=first;
		return first;
	}
	else
	{
		cur=first;
		prev=NULL;
		while(cur!=NULL)
		{
			prev=cur;
			cur=cur->link;
		}
		prev->link=temp;
		return first;
	}
}

NODE DelFront(NODE first)
{
	NODE next;
	if(first==NULL)
	{
		printf("Can't delete , list is empty\n");
		return first;
	}
	else if(first->link==NULL)
	{
		printf("The deleted info is\n usn=%d\n name=%s\n branch=%s\n sem=%d\n PhNo=%s\n",(first->usn),(first->Name),(first->Branch),(first->Sem),(first->PhNo));
		free(first);
		return NULL;
	}
	else
	{
		next=first->link;
		printf("The deleted info is\n usn=%d\n name=%s\n branch=%s\n sem=%d\n PhNo=%s\n",(first->usn),(first->Name),(first->Branch),(first->Sem),(first->PhNo));
		free(first);
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
	else if(first->link==NULL)
	{
		printf("The deleted info is\n usn=%d\n name=%s\n branch=%s\n sem=%d\n PhNo=%s\n",(first->usn),(first->Name),(first->Branch),(first->Sem),(first->PhNo));
		free(first);
		return NULL;
	}
	else
	{
		//morethanonenode*/
		cur=first;
		while(cur->link!=NULL)
		{
			prev=cur;
			cur=cur->link;
		}
		printf("The deleted info is\n usn=%d\n name=%s\n branch=%s\n sem=%d\n PhNo=%s\n",(cur->usn),(cur->Name),(cur->Branch),(cur->Sem),(cur->PhNo));
		free(cur);
		prev->link=NULL;
		return first;
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
	}
	else
	{
		cur=first;
		while(cur!=NULL)
		{
			printf("The student info is\n usn=%d\n name=%s\n branch=%s\n sem=%d\n PhNo=%s\n",(cur->usn),(cur->Name),(cur->Branch),(cur->Sem),(cur->PhNo));
		cur=cur->link;
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
			printf("EnterStudentData<%d>:\n",i);
			first=InsFront(first);
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
			 
void count(NODE first)
{
	int c=0;
	NODE cur=first;
	while(cur!=NULL)
	{
		cur=cur->link;
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
			case 1: printf("EnterNo.ofStudents:\n");
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
			case 8:	printf("1.implimentation as STACK\t2.implimentation as QUEUE\n");
				scanf("%d",&ch);
				switch(ch)
				{
					case 1: stack();
						break;
					case 2: queue();
						break;
				}
				break;
			default: exit(0);
		}
	}
}
