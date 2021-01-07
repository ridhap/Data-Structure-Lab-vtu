//Program to convert infix to postfix
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void push(char s[], int * top, char ele, int me)
{
	if(*top==me-1)
	{
		printf("Overflow");
		return;
	}
	(*top)++;
	s[*top]=ele;
}
char pop(char s[], int * top)
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
void pushi(int s[], int * top, int ele, int me)
{
	if(*top==me-1)
	{
		printf("Overflow");
		return;
	}
	(*top)++;
	s[*top]=ele;
}
int popi(int s[], int * top)
{
	int ele;	
	if(*top==-1)
	{
		printf("Underflow");
		return 0;
	}
	ele=s[*top];
	(*top)--;
	return ele;
}
int F(char sym)
{
	switch(sym)
	{
		case '+':
		case '-':return 2;
		case '*':
		case '/':
		case '%':return 4;
		case '^':
		case '$':return 5;
		case '(':return 0;
		case '#':return -1;
		default:return 8 ;
	}
}
int G(char sym)
{
	switch(sym)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':
		case '%':return 3;
		case '^':
		case '$':return 6;
		case '(':return 9;
		case ')':return 0;
		default:return 7;
	}
}
int compute(char op, int op1, int op2)
{
	switch(op)
	{
		case '+':return op1+op2;
		case '-':return op1-op2;
		case '*':return op1*op2;
		case '/':if(op2==0)
			{
				printf("Divide by zero");
				exit(0);
			}
			return op1/op2;
		case '%':if(op2==0)
			{
				printf("Divide by zero");
				exit(0);
			}
			return op1%op2;
		case '^':
		case '$':return pow(op1,op2);
	}
}
int eval(char postfix[])
{
	char ele;
	int num,i,dig[20],top=-1,op1,op2,res,l;
	l=strlen(postfix);
	for(i=0;i<l;i++)
	{
		ele=postfix[i];
		if(isdigit(ele))
		{
			num=ele-48;
			pushi(dig,&top,num,20);
		}
		else
		{
			op2=popi(dig,&top);
			op1=popi(dig,&top);
			res=compute(ele,op1,op2);
			pushi(dig,&top,res,20);
		}		
	}
	res=popi(dig,&top);
	return res;
}
char* convert(char infix[])
{
	int top=-1,l,i,pindex=0,res;
	char *postfix,s[20],sym,popele;
        postfix = (char *) malloc(sizeof(char)*20);
	l=strlen(infix);
	push(s,&top,'#',20);
	for(i=0;i<l;i++)
	{
		sym=infix[i];
		
		while(F(s[top])>G(sym))
			postfix[pindex++]=pop(s,&top);
		if(F(s[top])!=G(sym))
			push(s,&top,sym,20);
		else
			pop(s,&top);
	}
	popele=pop(s,&top);
	while(popele!='#')
	{
		postfix[pindex++]=popele;
		popele=pop(s,&top);
	}
	postfix[pindex]='\0';
	printf("Postfix: %s\n",postfix);
	return postfix;
}	
int main()
{
	char infix[20];
	printf("Enter the expression");
	scanf("%s",infix);
	int top=-1,l,i,pindex=0,res;
	char *postfix,s[20],sym,popele;
	/*l=strlen(infix);
	push(s,&top,'#',20);
	for(i=0;i<l;i++)
	{
		sym=infix[i];
		while(F(s[top])>G(sym))
			postfix[pindex++]=pop(s,&top);
		if(F(s[top])!=G(sym))
			push(s,&top,sym,20);
		else
			pop(s,&top);
	}
	popele=pop(s,&top);
	while(popele!='#')
	{
		postfix[pindex++]=popele;
		popele=pop(s,&top);
	}
	postfix[pindex]='\0';
	printf("Postfix: %s\n",postfix);*/
	postfix=convert(infix);
	res=eval(postfix);
	printf("Result=%d\n",res);
}
