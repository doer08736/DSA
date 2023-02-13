# include <stdio.h>

void displayArray(int arr[], int n){
	for(int i=0; i<n; ++i){
		printf("%d ", arr[i]);
	}printf("\n");
}

void selectionSort(int arr[], int size){
	int p;
	for(int i=0; i<size-1; i++){
		p = i;
		for(int j=i+1; j<size; j++){
			if(arr[p]>arr[j]) p = j;
		}
		if(p!=i){
			int temp = arr[i];
			arr[i] = arr[p];
			arr[p] = temp;
		}
	}
}

void main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; ++i){
		scanf("%d", &arr[i]);
	}
	displayArray(arr, n);
	selectionSort(arr, n);
	displayArray(arr, n);
}

/*
Time complexity:
=> O(n^2)
*/