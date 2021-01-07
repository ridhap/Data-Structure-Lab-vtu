//Program for Tower of Hanoi
#include<stdio.h>
#include<stdlib.h>
void towerh(int n, char src, char temp, char dst)
{
	if(n==0)
		return;
	towerh(n-1,src,dst,temp);
	printf("Move %d disc from tower %c to %c\n",n,src,dst);
	towerh(n-1,temp,src,dst);
}
int main()
{
	int n;
	printf("Enter no of discs: ");
	scanf("%d",&n);
	if(n>0)
		towerh(n,'a','b','c');
	else
		printf("Invalid no of discs\n");
}
