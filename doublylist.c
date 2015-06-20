#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;	
	struct node*prev;
	struct node*next;
};

void printlist(struct node*head)
{
	struct node*temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
		printf("\n-------");
}


void add_at_front(struct node**head)
{
	struct node*temp=NULL;
	int n;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data of new node");
	scanf("%d",&n);
	temp->data=n;
	temp->prev=NULL;
	temp->next=*head;
	*head=temp;
}	

void add_after_node(struct node**head,int key)
{
	struct node*temp=NULL;
	int n;
	struct node*start=*head;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data of new node\n");
	scanf("%d",&n);
	temp->data=n;
	while(key!=1)
	{
		start=start->next;
		key--;
	}
	
	temp->next=start->next;
	start->next->prev=temp;
	temp->prev=start;
	start->next=temp;
}

void createlist(struct node **head)
{
	struct node*temp=NULL;
	struct node*start=NULL;
	int n,i;
	for(i=0;i<5;i++)
	{	temp=(struct node*)malloc(sizeof(struct node));
		printf("enter data\n");
		scanf("%d",&n);
		temp->data=n;
		temp->prev=NULL;	
		temp->next=NULL;
		
			if(*head==NULL)
			{
				*head=temp;
				start=temp;
			}
			else
			{
				temp->prev=start;
				start->next=temp;
				start=temp;
			}

	}
}
			

int main()
{
	struct node*head=NULL;
	createlist(&head);
	printlist(head);
	add_at_front(&head);
	printlist(head);
	add_after_node(&head,3);
	printlist(head);
	return 0;
}
