//Program to search and replace string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Accept main, search, rs
void accept(char ms[30], char ss[10], char rs[20])
{
	printf("Enter the main string:");
	//scanf("%s", ms);
	gets(ms);
	printf("Enter the search string:");
	scanf("%s", ss);
	printf("Enter the replace string:");
	scanf("%s", rs);
}
//Function to chk if ss exists in ms
int chk_ss(char ms[30],char ss[10],int pos)
{
	int i=0,l1,l2;
	l1=strlen(ms);
	l2=strlen(ss);
	for(i=0;i<l2;i++,pos++)
		if(ms[pos]!=ss[i] || pos==l1)
			return -1;
	return 1;
}
//Function to copy the string
int cpy_str(char rs[20], char res[40],int pos)
{
	int i=pos,l;
	l=strlen(rs);
	for(i=0;i<l;i++,pos++)
		res[pos]=rs[i];
	return pos;
}
//Function to print
void print(char res[40])
{
	printf("The replaced string: ");
	puts(res);
}
//Main function
int main()
{
	int pos_ms=0,pos_rs=0,len;
	char rs[20],ss[10],ms[30],res[40];
	accept(ms,ss,rs);
	len=strlen(ms);
	for(pos_ms=0;pos_ms<len;)
	{
		if(chk_ss(ms,ss,pos_ms)==1)
		{
			pos_ms+=strlen(ss);
			//increment the main string by lenth of search string
			pos_rs=cpy_str(rs,res,pos_rs);
		}
		else
		{
			res[pos_rs]=ms[pos_ms];
			//Copy the individual character
			pos_ms++;
			pos_rs++;
		}
	}
	res[pos_rs]=0;
	print(res);
}
