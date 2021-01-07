#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *llink;
	int info;
	struct node *rlink;
};
typedef struct node*NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("insufficient memory\n");
		exit(0);
	}
	return temp;
}
NODE insert_BST(NODE,int);
NODE delete_BST(NODE,int);
void preorder(NODE);
void inorder(NODE);
void postorder(NODE);
void search_BST(NODE);
NODE insert_BST(NODE root,int item)
{
	NODE temp,cur,prev;
	cur=root;
	prev=NULL;
	temp=getnode();
	temp->llink=temp->rlink=NULL;
	temp->info=item;
	if(root==NULL)
	{
		return temp;
	}
	while(cur!=NULL)
	{
		prev=cur;
		if(cur->info>item)
		{
			cur=cur->llink;
		}
		else
		{
			cur=cur->rlink;
		}
	}
	if(prev->info>item)
	{
		prev->llink=temp;
	}
	else
	{
	prev->rlink=temp;
	}
	return root;
}
void preorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	printf(" %d",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}
void inorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->llink);
	printf(" %d",root->info);
	inorder(root->rlink);
}
void postorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->llink);
	postorder(root->rlink);
	printf(" %d",root->info);
}
void search_BST(NODE root)
{
	NODE cur;
	int key;
	printf("enter key element\n");
	scanf("%d",&key);
	if(root==NULL)
	{
		printf("empty BST\n");
		return ;
	}
	else
	{	
		cur=root;
		while(cur!=NULL)
		{
			if(cur->info==key)
			{
				printf("Search is successful\n");
				return ;
			}
			else if(cur->info<key)
			{
				cur=cur->rlink;
			}
			else
			{
				cur=cur->llink;
			}
		}
		printf("Search is unsuccessful\n");
		return ;
	}
}
NODE delete_BST(NODE root,int elem)
{
	NODE cur,suc,next,parent;
	if(root==NULL)
	{
	printf("BST is empty\n");
	return NULL;
	}
	parent=NULL;
	cur=root;
	while(cur!=NULL)
	{
		if(cur->info==elem)
		{
			break;
		}
		parent=cur;
		if(cur->info<elem)
		{
			cur=cur->rlink;
		}
		else
		{
			cur=cur->llink;
		}
	}
	if(cur==NULL)
	{
		printf("Element does not exist\n");
		return root;
	}
	if(cur->llink==NULL)
	{
		next=cur->rlink;
	}
	else if(cur->rlink==NULL)
	{
		next=cur->llink;
	}
	else
	{
		suc=cur->rlink;
		while(suc->llink!=NULL)
		{
			suc=suc->llink;
		}
		suc->llink=cur->llink;
		next=cur->rlink;
	}
	if(parent==NULL)
	{
		free(cur);
		return next;
	}
	if(cur==parent->llink)
	{
		parent->llink=next;
	}
	else
	{
		parent->rlink=next;
	}
	free(cur);
	return root;
}
int main()
{
	NODE root;
	root=NULL;
	int ch,c,i,ele,item,n;
	while(1)
	{
		printf("Enter\n1.Create\n2.Traverse\n3.Search\n4.Delete\n5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the no.of elements\n");
				scanf("%d",&n);
				printf("Enter the %d items\n",n);
				for(i=0;i<n;i++)
				{
					
					scanf("%d",&item);
					root=insert_BST(root,item);
				}
				break;
			case 2:printf("Enter\n1.Preorder\n2.Inorder\n3.Postorder\n");
				scanf("%d",&c);
				switch(c)
				{
					case 1:preorder(root);
						printf("\n");
						break;
					case 2:inorder(root);
						printf("\n");
						break;
					case 3:postorder(root);
						printf("\n");
						break;
				}
				break;
			case 3:search_BST(root);
				break;
			case 4:printf("Enter the element to be deleted\n");
				scanf("%d",&ele);
				root=delete_BST(root,ele);
				printf("Inorder representation after deletion of %d is:\n",ele);
				inorder(root);
				printf("\n");
				break;
			default:exit(0);
		}
	}
}
			
