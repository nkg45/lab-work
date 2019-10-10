#include <stdio.h>
#include<stdlib.h>
struct node
{
   int coeff;
   int exp;
   struct node *link;
};
struct node *insertion(int n,struct node *head);
struct node *multi(struct node *phead,struct node *qhead,struct node *rhead);
struct node *expo(struct node *rhead);
void traversal(struct node *head);
struct node *newnode;
struct node *rptr1;
struct node *temp;
struct node *temp1;
struct node *phead=NULL;
struct node *qhead=NULL;
struct node *rhead=NULL;
struct node *pptr;
struct node *qptr;
struct node *rptr;
struct node *getNode()
{
   struct node *ptr;
   ptr=(struct node *)malloc(sizeof(struct node));
   return ptr;
}    
void main()
{
  newnode=getNode();
  if(newnode==NULL)
  {
    printf("no space");
   }
  else
  {
    int n1,n2;
    printf("First polynomial\n");
    printf("Enter the no of terms : ");
    scanf("%d",&n1);
    phead = insertion(n1,phead);
    traversal(phead);
    printf("Second polynomial\n");
    printf("Enter the no of terms : ");
    scanf("%d",&n2);
    qhead = insertion(n2,qhead);
    traversal(qhead);
    rhead=multi(phead,qhead,rhead);
    rhead=expo(rhead);
    printf("\nmultiplication of the polynomials is : \n");
    traversal(rhead);
    
   }
    
}
struct node *insertion(int n,struct node *head)
{
   int i;
   for(i=0;i<n;i++)
   {
      newnode=getNode();
      if(newnode==NULL)
      {
        printf("no space");
      }
      else
      {
         printf("Enter the coeff: ");
         scanf("%d",&newnode->coeff);
         printf("Enter the exp: ");
         scanf("%d",&newnode->exp);
         newnode->link=NULL;
         if(head==NULL)
         {
             head=newnode;
          }
         else
         {
             temp=head;
             while(temp->link!=NULL)
             {
                 temp=temp->link;
              }
             temp->link=newnode;
           }
       }
     }
     return(head);
}
struct node *multi(struct node *phead,struct node *qhead,struct node *rhead)
{  
   pptr=phead;
   qptr=qhead;
   rptr=rhead;
   /*if((pptr->link==NULL) || (qptr->link==NULL))
   {
     printf("invalid");
    }*/
   while(pptr!=NULL)
   {
      while(qptr!=NULL)
      {
         newnode=getNode();
         if(newnode==NULL)
         {
           printf("no space");
           break;
          }
         else
         {
            newnode->coeff=pptr->coeff*qptr->coeff;
            newnode->exp=pptr->exp+qptr->exp;
            newnode->link=NULL;
            if(rhead==NULL)
            {
                rhead=newnode;
                rptr=rhead;
            }
            else
            {
              rptr->link=newnode;
              rptr=newnode;
            }
            qptr=qptr->link;
          }
       
        }
       qptr=qhead;
       pptr=pptr->link;
      
   }       
   return(rhead);
}
struct node *expo(struct node *rhead)
{
   rptr=rhead;
   temp=rptr;
   while(rptr->link!=NULL)
   {
      while(temp->link!=NULL)
      {
         if(rptr->exp==(temp->link)->exp)
         {
            rptr->coeff=rptr->coeff+(temp->link)->coeff;
            temp1=temp->link;
            temp->link=temp1->link;
            free(temp1);
         }
         temp=temp->link;
      }
      rptr=rptr->link;
      temp=rptr;
   }
   return(rhead);
}
    
void traversal(struct node *head)
{
   temp=head;
   while(temp!=NULL)
   {
       printf("%dx^%d ",temp->coeff,temp->exp);
       temp=temp->link;
       if(temp!=NULL)
         printf("+");

    }
   printf("\n");
}
                

