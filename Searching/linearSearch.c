# include <stdio.h>

void linearSearch(int arr[], int size){
	int element;
	scanf("%d", &element);
	for(int i=0; i<size; ++i){
		if(element==arr[i]){
			printf("Element found at index %d\n", i);
			return;
		}
	}
	printf("Element not found\n");
}

void main(){
	int arr[] = {1, 5, 6, 7, 4};
	int size = sizeof(arr)/sizeof(int);
	linearSearch(arr, size);
}
