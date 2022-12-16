# include <stdio.h>

void displayArray(int arr[], int size){
	for(int i=0; i<size; i++) printf("%d ", arr[i]);
	printf("\n");
}

void insertEnd(int arr[], int *size, int element){
	arr[*size] = element;
	*size += 1;
}

void main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	printf("Enter the element to be inserted: ");
	int e;
	scanf("%d", &e);
	insertEnd(arr, &n, e);
	displayArray(arr, n);
}		
