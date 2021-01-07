//stack implement
#include<stdio.h>
#include<stdlib.h>
void push(int s[], int *top, int me)
{
	int ele;
	printf("Enter the element:");
	scanf("%d",&ele);	
	if(*top==me-1)
	{
		printf("Overflow");
		return;
	}
	(*top)++;
	s[*top]=ele;	
}
void pop(int s[],int *top)
{
	int ele;
	if(*top==-1)
	{
		printf("Underflow");
		return;
	}
	ele=s[*top];
	(*top)--;
	printf("%d is popped",ele);
}
void display(int st[], int top)
{
	int i;
	if(top==-1)
		printf("No elements");
	else
		for(i=top;i>=0;i--)
			printf("%d\t",st[i]);
	printf("\n");
}
int main()
{
	int st[20],me,top=-1,ch;
	printf("Enter no of elements: ");
	scanf("%d",&me);
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Display\nelse Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push(st,&top,me);
				break;
			case 2:pop(st,&top);
				break;
			case 3:display(st,top);
				break;
			default:exit(0);
		}
	}
}
