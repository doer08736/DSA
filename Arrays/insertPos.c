# include <stdio.h>

void displayArray(int arr[], int size){
	for(int i=0; i<size; i++) printf("%d ", arr[i]);
	printf("\n");
}

void insertPos(int arr[], int *size){
	printf("Enter the position and element to insert: ");
	int pos, element;
	scanf("%d%d", &pos, &element);
	int i;
	for(i=*size; i!=pos-1; i--) arr[i] = arr[i-1];
	arr[i] = element;
	*size += 1;
}

void main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	insertPos(arr, &n);
	displayArray(arr, n);
}		
