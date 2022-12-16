# include <stdio.h>

void displayArray(int arr[], int size){
	for(int i=0; i<size; i++) printf("%d ", arr[i]);
	printf("\n");
}

void deletePos(int arr[], int *size){
	printf("Enter the position to delete: ");
	int pos;
	scanf("%d", &pos);
	for(int i=pos-1; i<*size-1; i++) arr[i] = arr[i+1];
	*size -= 1;
}

void main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	deletePos(arr, &n);
	displayArray(arr, n);
}		
