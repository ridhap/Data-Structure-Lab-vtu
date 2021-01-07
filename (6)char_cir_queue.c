#include<stdio.h>
#include<stdlib.h>
#define ME 4
void insert_rear(char [],int *,int *,int *);
void delete_front(char [],int *,int *,int *);
void display(char [],int ,int);
int main()
{
	char cq[ME];
	int front=0,rear=ME-1,count =0,ch;
	while(1)
	{
		printf("enter the choice\n1:insert\n2:delete\n3:display\n4;exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_rear(cq,&front,&rear,&count);
				break;
			case 2: delete_front(cq,&front,&rear,&count);
				break;
			case 3: display(cq,front,count);
				break;
			default:exit(0);
		}
	}
}
void insert_rear(char cq[],int *front,int*rear,int *count)
{
	char elem;
	printf("enter the elem\n");
	scanf(" %c",&elem);
	if(*count==ME)
	{
		printf("queue is full\n");
		return;
	}
	(*rear)=((*rear)+1)%ME;
	cq[*rear]=elem;
	(*count)++;
	display(cq,*front,*count);
}
void delete(char cq[],int *front,int *rear,int *count)
{
	char elem;
	if(*count==0)
	{
		printf("queue is empty\n");
		return;
	}
	elem=cq[*front];
	(*front)=(*front+1)%ME;
	(*count)--;
	printf("elem deleted is %c\n",elem);
	printf("f=%d c=%d", *front,*count);
	display(cq,*front,*count);
}
void display(char cq[],int front,int count)
{
	int i;
	if(count==0)
	{
		printf("queue is empty\n");
		return;
	}
	printf("queue is\n");
	for(i=0;i<count;i++)
	{
		printf("%c\t",cq[front]);
		front=(front+1)%ME;
	}
}













