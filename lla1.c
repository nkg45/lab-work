#include <stdio.h>
#include<stdlib.h>
struct node
{
   int coeff;
   int exp;
   struct node *link;
};
struct node *insertion(int n,struct node *head);
struct node *add(struct node *phead,struct node *qhead,struct node *rhead);
void traversal(struct node *head);
struct node *del(struct node *rhead);
struct node *newnode;
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
    rhead=add(phead,qhead,rhead);
    rhead=del(rhead);
    printf("\nSum of the polynomials is : \n");
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
struct node *add(struct node *phead,struct node *qhead,struct node *rhead)
{
   int count = 0;
   pptr=phead;
   qptr=qhead;
   
   while(pptr!=NULL && qptr!=NULL)
   {
     newnode=getNode();
     if(newnode==NULL)
     {
       printf("no space");
       break;
     }
     else
     {
        
         if((pptr->exp) > (qptr->exp))
         {
            newnode->coeff=pptr->coeff;
            newnode->exp=pptr->exp;
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
                pptr=pptr->link;
             
            
         }
         else if((qptr->exp) > (pptr->exp))
         {
            newnode->coeff=qptr->coeff;
            newnode->exp=qptr->exp;
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
         else if((pptr->exp) == (qptr->exp))
         {

            newnode->coeff = pptr->coeff + qptr->coeff;
            newnode->exp = pptr->exp;
            newnode->link = NULL;
            if(rhead==NULL)
            {
               rhead=newnode;
               rptr=rhead;
            }
            else
            {
               rptr->link = newnode;
               rptr = newnode;
             }
               pptr = pptr->link;
               qptr = qptr->link;
             
 
         }
       }
  }
  while(pptr != NULL)
  {    
     newnode=getNode();
     if(newnode==NULL)
     {
       printf("no space");
       break;
     }
     else
     {
       newnode->coeff=pptr->coeff;
       newnode->exp=pptr->exp;
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
          pptr=pptr->link;  
          
     }
  }
  while(qptr != NULL)
  {    
     newnode=getNode();
     if(newnode==NULL)
     {
       printf("No space");
       break;
     }
     else
     {
       newnode->coeff=qptr->coeff;
       newnode->exp=qptr->exp;
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
struct node *del(struct node *rhead)
{
   temp=rhead;
   while(temp!=NULL)
   {
       if(rhead->coeff==0)
       {    
           rhead=temp->link;
           free(temp);
           temp=rhead;
        }
       else
       {
         if(temp->coeff==0)
         {
           temp1=temp;
           temp=temp->link;
           free(temp1);
          }
         else
         {
            temp=temp->link;
          }
        }
    }
   return(rhead);
}
   
         

      
   
