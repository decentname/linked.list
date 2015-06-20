#include<stdio.h>
#include<stdlib.h>


// input linked list 101010
//output two linked list one as header=111
// and other as head=000
struct node
{
 int data;
 struct node*next;
};

//delete function to delete a node
struct node * dismiss(int key,struct node *head)
{
        struct node*temp=head;
        //deleting first node 
        if(temp->data==key)
        {
            head=temp->next;

            free(temp);
        }

        else
        //deleting any other node 
        {
                while(temp->next->data!=key)
                {
                    temp=temp->next;
                }

            struct node*rev=temp->next;
            temp->next=rev->next;
            free(rev);

        }

        return(head);

}

void printlist(struct node*head)
{
	struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

//alternate split of singly linked list
struct node *altsplit(struct node *head)
{
         struct node* temp=head;
         struct node* temp1=head;
         int counter=0;
         struct node* start=NULL;
         struct node* header=NULL;
         while(temp!=NULL)
         {
         	//odd positons
         	
             if(counter%2==0)
             {
                 struct node *l1=(struct node*)malloc(sizeof(struct node));
                 l1->data=temp->data;
                 l1->next=NULL;
                 if(counter==0)
                 {
                     header=start=l1;
    //                 printf("\nhead is with data %d\n",header->data);
                 }
                 else
                 {
                     start->next=l1;
                     start=l1;
      //               printf("node added with data %d\n",l1->data);
                 }
                 counter++;
                 
             // save in new linked list and delete from old linked list  
                head=dismiss(temp->data,head);
             	//temp=head;

             }

             else
            {
                temp=temp->next->next;
                counter++;
             }
  //           printf("counter value is %d\n",counter);
         }
        printf("---first list---\n");        
	printlist(head);
	printf("\n---second list---\n");
	printlist(header);
                return(head);

}

struct node* get_node(struct node*head)
{
		int n;
	    struct node*temp=NULL;
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter data");
		printf("\n");
		scanf("%d",&n);
	    temp->data=n;
		temp->next=NULL;
		return(temp);
}

struct node* create_list(struct node*head)
{
     int i;
        struct node*temp=NULL;
	head=(struct node*)malloc(sizeof(struct node));
	head->data=1;
	head->next=NULL;

        temp=head;
    for(i=0;i<5;i++)
    {
            struct node *new_node=NULL;
            new_node=get_node(head);

            if(head->next==NULL)
            {
              head=temp;
              temp->next=new_node;
              temp=new_node;
            }
            else
            {
                   temp->next=new_node;
                    temp=new_node;
            }
    }
//	                                                  printf("list created\n");
//	                                                  printlist(head);
	return(head);
}




int main()
{
     struct node*head=NULL;
	head=create_list(head);
    head=altsplit(head);
    //printlist(head);
    return 0;
}
