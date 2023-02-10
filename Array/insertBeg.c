# include <stdio.h>

void displayArray(int arr[], int size){
	for(int i=0; i<size; i++) printf("%d ", arr[i]);
	printf("\n");
}

void insertBeg(int arr[], int *size, int element){
	int i;
	for(i=*size; i!=0; i--){
		arr[i] = arr[i-1];
	}
	arr[i] = element;
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
	insertBeg(arr, &n, e);
	displayArray(arr, n);
}		
