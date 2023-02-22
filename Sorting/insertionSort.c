# include <stdio.h>

void displayArray(int arr[], int n){
	for(int i=0; i<n; ++i){
		printf("%d ", arr[i]);
	}printf("\n");
}

void insertionSort(int arr[], int n){
	int selected, prev;
	for(int i=1; i<n; ++i){
		for(selected=arr[i], prev=i-1; prev>=0 && selected<arr[prev]; --prev)
			arr[prev+1] = arr[prev];
		arr[prev+1] = selected;
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
	insertionSort(arr, n);
	displayArray(arr, n);
}

/*
Time complexity:
=> O(n^2)
*/