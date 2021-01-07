//Program to implement circular queue for char array
#include<stdio.h>
#include<stdlib.h>
#define max 3
void insert(char q[], int *rear, int *count)
{
	char ele;
	printf("Enter the element:");
	scanf(" %c",&ele);
	if(*count==max)
	{
		printf("Queue is full\n");
		return;
	}
	(*rear)=(*rear+1)%max;
	q[*rear]=ele;
	(*count)++;
}
//delete function
void del(char q[], int *front, int *count)
{
	char ele;
	if(*count==0)
	{
		printf("Empty queue\n");
		return;
	}
	ele=q[*front];
	*front=(*front+1)%max;
	(*count)--;
	printf("%c is deleted\n",ele);
}
void display(char q[], int front, int count)
{
	int i;
	if(count==0)
	{
		printf("Empty queue\n");
		return;
	}
	for(i=1;i<=count;i++)
	{
		printf("%c ",q[front]);
		front=(front+1)%max;
	}
	printf("\n");
}
int main()
{
	int ch,front=0,rear=max-1,count=0;
	char q[max];
	while(1)
	{
		printf("1.Insert 2.Delete 3.Display else Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert(q,&rear,&count);
				display(q,front,count);
				break;
			case 2: del(q,&front, &count);
				display(q,front,count);
				break;
			case 3: display(q, front,count);
				break;
			default:exit(0);
		}
	}
}
