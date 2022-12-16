# include <stdio.h>

void displayArray(int arr[], int size){
	for(int i=0; i<size; i++) printf("%d ", arr[i]);
	printf("\n");
}

void deleteBeg(int arr[], int *size){
	for(int i=0; i<*size-1; i++) arr[i] = arr[i+1];
	*size -= 1;
}

void main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	deleteBeg(arr, &n);
	displayArray(arr, n);
}		
