/* Design, Develop and Implement a menu driven Program in C for the
following Array operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Inserting an Element (ELEM) at a given valid Position (POS)
d. Deleting an Element at a given valid Position(POS)
e. Exit.
Support the program with functions for each of the above operations
*/

#include <stdio.h>
#include <stdlib.h>
#define size 20

void create(int arr[],int n)
int insert(int arr[], int n);
int delete (int arr[], int n);
void display(int arr[], int n);

//function to create an array of n elements//
void create(int arr[],int n)
{
	int i=0;
	printf("enter the array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",%arr[i]);
	}
}
//function to insert element into the array//
int insert(int arr[], int n)
{
	int i, pos, ele;
	printf("Enter Element\n");
	scanf("%d", &ele);
	printf("Enter Position\n");
	scanf("%d", &pos);
	//check is the position entered is a valid position
	if(pos>0 && pos<n-1)
	{
		for (i =n;i>pos;i--)
		{
			arr[i] = arr[i+1];
		}
		arr[pos]=ele;
		n=n+1;
	}
	else
	{
		printf("invalid input\n");
	}
	return n;
}

void delete (int arr[], int *n)
{
	int i, pos,ele;
	printf("Enter the Position to delete the element\n");
	scanf("%d", &pos);
	//check is the position entered is a valid position
	if(pos>0 && pos<n-1)
	{
		ele=a[pos];
		for(i=pos;i<n-1; i++)
		{		
			arr[i] = arr[i + 1];
		}
	n = n-1;
	printf("the deleted element is %d\n",ele);
	return n;
}
//function to display the array elements//
void display(int arr[], int n)
{
	int i;
	if(n==0)
	{
		printf("the array is empty\n");
		return;
	}
	else
	{
		printf("the array elements are\n");
		for (i=0; i<n ;i++)
			{
				printf("%d",arr[i]);
				printf("\n");
			}
	}
}

int main()
{
	int arr[size], i, n, ch;
	printf("Enter Initial size of Array\n");
	scanf("%d", &n);
	while(1)
	{
		printf("\n----Menu----\n");
		printf("1. Create\n2. Insert\n2. Delete\n3. Display\n4. Exit\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:create(arr,&n);
				break;
		case 2:
			insert(arr, &n);
			break;
		case 3:
			delete (arr, &n);
			break;
		case 4:
			display(arr, n);
			break;
		case 5:
			exit(0);
		}
	}
}