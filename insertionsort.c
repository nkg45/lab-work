#include<stdio.h>




int inssort(int arr[], int n)
{

int i,j,temp;
for(i=1;i<n;i++){
for(j=i;j>0;j--){
if (arr[j]<arr[j-1]){
temp=arr[j-1];
arr[j-1]=arr[j];
arr[j]=temp;
}
}
}

printf("\n");

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
	
	inssort(arr,n);

}









