#include<stdio.h>
void create(int *,int *);
void display(int *,int );
void insert(int *,int *);
void delete(int *,int *);
int main()
{
	int a[20],n,ch;
	for(;;)
	{
		printf("1.Creating an array\n2.Displaying an array\n3.Inserting an array\n4.Deleting an array\n5.exit\n");
		printf("Enter your choise\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create(&n,a);
				break;
			case 2:display(a,n);
				break;
			case 3:insert(a,&n);
				break;
			case 4:delete(a,&n);
				break;
			case 5:return 0;
		}
	}
}
void create(int *n,int *a)
{
	int i;
	printf("Enter the number of elements\n");
	scanf("%d",n);
	printf("Enter the array elements\n");
	for(i=0;i<(*n);i++)
	scanf("%d",(a+i));
}
void display(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d",*(a+i));
}
void insert(int *a,int *n)
{
	int pos,elem,i;
	printf("Enter the position and element\n");
	scanf("%d%d",&pos,&elem);
	for(i=(*n)-1;i>=pos;i--)
		a[i+1]=a[i];
	a[pos]=elem;
	(*n)++;
}
void delete(int *a,int *n)
{
	int pos,i;
	printf("Enter the position of element to be deleted\n");
	scanf("%d",&pos);
	for(i=(*n)-1;i>=pos;i--)
	a[i]=a[i+1];
	(*n)--;
}	 
	
