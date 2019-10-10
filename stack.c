#include <stdio.h>
#define MAX 5
int top=-1;
void push(int a[])
{
   int i;
   if(top==MAX)
   {
      printf("impossible\n");
    }
   else
   {
      printf("enter the element to be inserted");
      top++;
      scanf("%d",&a[top]);
   }
}  
   
   
void pop(int a[])
{
   int i;
   if(top==-1)
   {
      printf("no elements to be deleted\n");
    }
   else
   {
      printf("the element deleted=%d\n",a[top]);
      top--;
    }
}
void display(int a[])
{   
   int i;
   if(top==-1)
   {
      printf("no elements");
    }
   else
   {  
      printf("the elements are\n");
      for(i=0;i<=top;i++)
      {
         printf("%d\n",a[i]);
       }
   }
}
void main()
{
   int a[MAX];
   int top=-1,i,n=1,c,d;
   while(n!=0)
   {
      printf("1.push 2.pop 3.display\n");
      scanf("%d",&n);
      if(n==1)
      {
         push(a);
         
       }
      else if(n==2)
      {
        pop(a);
         
      }
      else
      {
         display(a);
      }
  }

}

   
