# include <stdio.h>

void binarySearch(int arr[], int size, int n){
	int low = 0;
	int high = size-1;
	int mid;
	while(low<=high){
		mid = (low+high)/2;
		if(arr[mid]==n){
			printf("Element found at index %d\n", mid);
			return;
		}
		else if(arr[mid]>n){
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	printf("Element not found\n");
}

void main(){
	int arr[] = {1, 5, 6, 22, 53};
	int size = sizeof(arr)/sizeof(int);
	int n;
	scanf("%d", &n);
	binarySearch(arr, size, n);
}
