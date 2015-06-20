#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack*next;
};


void push(struct stack**head)
{
	int i,n;
	struct stack *temp=NULL;
	for(i=0;i<5;i++)
	{
		temp=(struct stack*)malloc(sizeof(struct stack));
		printf("enter data\n");
		scanf("%d",&n);
		temp->data=n;
		temp->next=NULL;
	
		if(*head==NULL)
		{
			*head=temp;
		}
		else
		{
			temp->next=*head;
			*head=temp;
		}
	}
}

int isempty(struct stack*head)
{
	if(head==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int pop(struct stack**head)
{	
	int popped;
	
	if(isempty(*head))
	{
		printf("stack is empty\n");
		return 0;
	}
	
	
		struct stack*temp=*head;
		popped=temp->data;
		*head=(*head)->next;
		free(temp);
		return(popped);
	
}	



int main()
{
	struct stack *head=NULL;
	push(&head);	
	int a;
	a=pop(&head);	
	printf("---popped element is--- \n %d\n",a);
	return 0;	
}
