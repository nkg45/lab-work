#include<stdio.h>


int selsort(int arr[], int n){

int min,pos,i,j,temp;

for(i=0;i<n;i++){
min=arr[i];
pos=i;

for(j=i;j<n;j++){
if(arr[j+1]<=min){
min=arr[j+1];
pos=j+1;
}

}

temp=arr[i];
arr[i]=arr[pos];
arr[pos]=temp;
}


printf("\n");

for(i=0;i<n;i++){
 printf("%d\n",arr[i]);
}

}

int main(){

int arr[100];
	int i,n;


	printf("\nHow many elements:\t");
	scanf("%d",&n);
	printf("\n");	

	printf("Enter elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		} 
	
	selsort(arr,n);

}
