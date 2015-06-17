#include<stdio.h>
#include<stdlib.h>
using namespace std;

// input linked list 10101
//output l1=111
// temp=00
struct node
{
 int data;
 struct node*next;
};

struct node * dismiss(int key,struct node *head)
{
        struct node*temp=head;
        if(temp->data==key)
        {
            head=temp->next;

            free(temp);
          //  printf("delete funcion called");
        }

        else
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

    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}

struct node *altsplit(struct node *head)
{
         struct node*temp=head;
         int counter=0;
         struct node*start=NULL;
         struct node*header=NULL;
         while(temp!=NULL)
         {
             if(counter%2==0)
             {
                 struct node *l1=(struct node*)malloc(sizeof(struct node));
                 l1->data=temp->data;
                 l1->next=NULL;
                 if(counter==0)
                 {
                     header=start=l1;
                 }
                 else
                 {
                     start->next=l1;
                     start=l1;
                 }
                 counter++;
               //  printf("this is %d",temp->data);
                head=dismiss(temp->data,head);
             //   printf("this is aftr %d",temp->data);

             }

             else
            {
                temp=temp->next;
                counter++;
             }
         }
                //printlist(head);
                //printlist(header);

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
    for(i=0;i<4;i++)
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

	return(head);
}




int main()
{
     struct node*head=NULL;
	head=create_list(head);
  //  printlist(head);
    //head=sorted(head,4);
    //printlist(head);
    //head=removeduplicates2(head);
    //head=pairwiseswap(head);
    //printlist(head);
    head=altsplit(head);
    //printlist(head);
    return 0;
}
