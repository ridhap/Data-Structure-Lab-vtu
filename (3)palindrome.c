//palindrome stack
#include<stdio.h>
#include<string.h>
void push(char s[], char ele, int *top, int me)
{
	if(*top==me-1)
	{
		printf("Overflow");
		return;
	}
	(*top)++;
	s[*top]=ele;
	
}
char pop(char s[],int *top)
{
	char ele;
	if(*top==-1)
	{
		printf("Underflow");
		return 0;
	}
	ele=s[*top];
	(*top)--;
	return ele;
}
int palin(char  s[], char ms[], int l, int top)
{
	int i,ele;
	for(i=0;i<l;i++)
	{
		ele=pop(s,&top);		
		if(ele!=ms[i])
			return -1;
	}
	return 1;
}
int main()
{
	char ms[20],s[20];
	int l,top=-1,palind=0,i;
	printf("Enter the string:");
	scanf("%s",ms);
	l=strlen(ms);
	for(i=0;i<l;i++)
	{
		push(s,ms[i],&top,l);
	}	
	palind=palin(s,ms,l,top);
	if(palind==1)
		printf("%s is palindrome\n",ms);
	else
		printf("%s is not a palindrome\n",ms);
}
