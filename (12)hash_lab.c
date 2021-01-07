#include<stdio.h>
#include<stdlib.h>
struct emp
{
	int eid;
	char e_name[20];
	int sal;
};
typedef struct emp E;
struct hash_table
{
	int K;
	long int L;
};
typedef struct hash_table ht;
void insert(FILE *fp,ht h[100],int hz,int n);
int hash(int num,int hz);
void search(FILE *fp,ht h[100],int hz);
void display(FILE *fp,ht h[100],int hz);
int main()
{
	ht h[100];
	int hz,N,choice,i;
	FILE *fp;
	fp=fopen("Emp.txt","w+");
	printf("enter the value of hz:");
	scanf("%d",&hz);
	for(i=0;i<hz;i++)
	{
		h[i].K=-1;
	}
	while(1)
	{
		printf("enter choice:\n");
		printf("1-create\n2-search\n3-display\n4-exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter no.of emp:");
				scanf("%d",&N);
				insert(fp,h,hz,N);
				break;
			case 2: search(fp,h,hz);
				break;
			case 3: display(fp,h,hz);
				break;
			default:exit(0);
		}
	}
}
int hash(int num,int hz)
{
	int digit;
	digit=num%hz;
	return digit;
}
void insert(FILE *fp,ht h[100],int hz,int n)
{
	int h_value,i,count_index;
	E emp1;
	for(i=0;i<n;i++)
	{
		printf("enter the employee ID,Name & salary\n");
		scanf("%d",&(emp1.eid));
		scanf("%s",emp1.e_name);
		scanf("%d",&(emp1.sal));
		h_value=hash(emp1.eid,hz);
		count_index=h_value;
		while(h[h_value].K!=-1)
		{
			h_value=(h_value+1)%hz;
			if(h_value==count_index)
			{
				printf("hash table is full\n");
				return;
			}
		}
		fseek(fp,0,SEEK_END);
		h[h_value].L=ftell(fp);
		h[h_value].K=emp1.eid;
		fwrite(&emp1,sizeof(E),1,fp);
	}
}
void display(FILE *fp,ht h[100],int hz)
{
	E emp1;
	int i;
	printf("EID\tName\tSalary\n");
	for(i=0;i<hz;i++)
	{
		if(h[i].K!=-1)
		{
			fseek(fp,h[i].L,SEEK_SET);
			fread(&emp1,sizeof(E),1,fp);
			printf("%d\t%s\t%d\n",emp1.eid,emp1.e_name,emp1.sal);
		}
	}
}

void search(FILE *fp,ht h[100],int hz)
{
	int h_value,count_index;
	E emp1;
	printf("enter EMP ID to be searched: ");
	scanf("%d",&(emp1.eid));
	h_value=hash(emp1.eid,hz);
	count_index=h_value;
	while(h[h_value].K!=emp1.eid)
	{
		h_value=(h_value+1)%hz;
		if(h_value==count_index)
		{
			printf("unsuccessful search\n");
			return;
		}
	}
	fseek(fp,h[h_value].L,SEEK_SET);
	fread(&emp1,sizeof(E),1,fp);
	printf("EID\tName\tSalary\n");
	printf("%d\t%s\t%d\n",emp1.eid,emp1.e_name,emp1.sal);
}	
