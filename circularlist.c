#include<stdio.h>
#include<stdlib.h>
//using namespace std;



struct node
{
	int data;
	struct node*next;

};


void createlist(struct node**head)
{	
	int n,i;
	struct node*temp=NULL;
	
	for(i=0;i<4;i++)
	{	struct node *ptr=(struct node*)malloc(sizeof(struct node));
		printf("enter data\n");
		scanf("%d",&n);
		ptr->data=n;
		ptr->next=*head;
	
		if(*head==NULL)
		{	
			ptr->next=ptr;
			*head=ptr;
			temp=ptr;
		}
		else
		{
				
		temp->next=ptr;
		temp=ptr;		
		}
	}	
		

}


void printList(struct node *head)
{
    struct node *temp = head;
   
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
	printf("\n");
}

void split(struct node**head)
{	
	int i;
	int count=0;
		
	struct node*start=*head;
	struct node*temp=*head;
	struct node*end=NULL;
	struct node*temp1=NULL;

		do
		{
			temp=temp->next;
			count++;
		}
		while(temp!=*head);

	for(i=1;i<count/2;i++)
	{
		start=start->next;
	}

		end=start->next;
		temp1=end;
		start->next=*head;

	while(temp1->next!=*head)
		{
			temp1=temp1->next;
		}	

	temp1->next=end;


		printf("---first half is---\n");
		printList(temp);
		printf("---second half is---\n");
		printList(end);

}



int main()
{

	struct node*head=NULL;
	createlist(&head);
//	printList(head);
	split(&head);	
	return 0;
}
