#include<stdio.h>



int bubblesort(int arr[], int n){

	int t,i,j;
	 for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if (arr[j]>arr[j+1]){
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	printf("Sorted array is:\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}

}

int main()
{
	int arr[100];
	int i,n,k,x;


	printf("\nHow many elements:\t");
	scanf("%d",&n);
	printf("\n");	

	printf("Enter elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		} 
	
	bubblesort(arr,n);

}


