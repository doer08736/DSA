# include <stdio.h>

void displayArray(int arr[], int n){
	for(int i=0; i<n; ++i){
		printf("%d ", arr[i]);
	}printf("\n");
}

void bubbleSort(int arr[], int n){
	for(int i=0; i<n-1; ++i){
		for(int j=0; j<n-i-1; ++j){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
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
	bubbleSort(arr, n);
	displayArray(arr, n);
}

/*
Time complexity:
=> O(n^2)
*/
