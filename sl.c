#include <stdio.h>
#include <stdlib.h>
struct node
{
   int data;
   struct node *link;
};
struct node *top=NULL;
struct node *temp;
struct node *newnode;
struct node *getNode()
{
   struct node *ptr;
   ptr=(struct node *)malloc(sizeof(struct node));
   return ptr;
}    
void push()
{
   newnode=getNode();
   if(newnode==NULL)
   {
      printf("No space");
    }
   else
   {
      if(top==NULL)
      {
         printf("enter the element");
         scanf("%d",&newnode->data);
         newnode->link=NULL;
      }
      else
      {
         printf("enter the element");
         scanf("%d",&newnode->data);
         newnode->link=top;
      }
      top=newnode;
    }
}
void pop()
{
   if(top==NULL)
   {
      printf("the stack is empty");
   }
   else
   {
      temp=top;
      top=top->link;
      free(temp);
    }
}
void display()
{
   temp=top;
   while(temp!=NULL)
   {
      printf("%d\n",temp->data);
      temp=temp->link;
   }
}     
void main()
{
   int n;
   do
	{
        
		printf("\n1. Push into stack\n 2.Pop from stack\n 3.Display stack\n4. Exit\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case  1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: exit(1);
			default: printf(" Wrong choice ");
		}
	}while(n>=1&&n<=4);
}

