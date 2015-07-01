#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack
{
	char data;
	struct stack *next;
};



int isoperand(char ch)
{
	if(ch>='a' && ch<='z' || ch >='A' && ch<='Z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(struct stack**head,char n)
{
	struct stack *temp=NULL;
	temp=(struct stack*)malloc(sizeof(struct stack));
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

//	printf("pushed in stack\n");
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

char pop(struct stack**head)
{	
	char popped;
	
	if(isempty(*head))
	{
		printf("stack is empty\n");
	}
	
	
		struct stack*temp=*head;
		popped=temp->data;
		*head=(*head)->next;
		free(temp);
		return(popped);
	
}

char peek(struct stack *head)
{
	return head->data;

}

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

void infix2postfix(struct stack *head,char str[])
{
	int l,i;
	int j=0;
	char output[10];
	l=strlen(str);
//	printf("length of original expression %d\n",l);
	for(i=0;i<l;i++)
	{
		if(isoperand(str[i]))
		{
			output[j]=str[i];
				j++;
//			printf("is operand\n");
		}
			
		else // is an operator
		{
			
//			printf("is operator\n");
	
			if(isempty(head))  // if stack is empty, push the operator  
			{
//				printf("stack is empty\n");
				push(&head,str[i]);
			}
			else
			{
//				printf("checking predence\n");
					
				if(str[i]=='(')
				{
					push(&head,str[i]);
				}
				else
				{   if(str[i]==')')
					{	while (!isempty(head) && peek(head)!= '(')
                				output[j++] = pop(&head);
					}
				     else
					{	
						while(!isempty(head) && Prec(str[i])<=Prec(peek(head)))
						{
							output[j]=pop(&head);
							j++;
						}
					
						push(&head,str[i]);
					}
				}
			}
		}
	}

			while(!isempty(head))
			{
					output[j]=pop(&head);
					j++;
			}
		
			//printf("length of expression becomes %d\n",j);

		printf("postfix expression is\n");
		for(i=0;i<j;i++)
		{
			printf("%c",output[i]);
		}
		printf("\n");
}	

int main()
{
	struct stack *head=NULL;
	char str[]="abc+d/e";
	infix2postfix(head,str);
			
	return 0;
}
