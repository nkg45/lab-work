#include <stdio.h>
#include <stdlib.h>
struct node
{
   int data;
   struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;
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
      printf("no space");
   }
   else
   {  
      printf("enter the element");
      scanf("%d",&newnode->data);
      newnode->link=NULL;
      if(front==NULL)
      {
         front=newnode;
         rear=newnode;
      }
      else
      {
         rear->link=newnode;
         rear=newnode;
      }
   }
}
void pop()
{
   if(front==NULL)
   {
      printf("queue is empty");
   }
   else
   {
      if(front==rear)
      {
         free(front);
         front=rear=NULL;
      }
      else
      {
         temp=front;
         front=front->link;
         free(temp);
      }
   }
}     
void display()
{
   temp=front;
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
        
		printf("\n1. Push into queue\n 2.Pop from queue\n 3.Display queue\n4. Exit\nEnter your choice : ");
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

