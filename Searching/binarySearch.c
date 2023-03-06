# include <stdio.h>


void binarySearch(int arr[], int n, int key){
	int low = 0;
	int high = n-1;
	int mid;
	while(low<=high){
		mid = (low+high)/2;
		if(arr[mid]==key){
			printf("Element found at index %d\n", mid);
			return;
		}
		else if(arr[mid]>key)
			high = mid-1;
		else
			low = mid+1;
	}
	printf("Element not found\n");
}

void main(){

	int n, key;
	printf("enter size: ");
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; ++i)
		scanf("%d", arr+i); // or &arr[i]

	printf("enter key: ");
	scanf("%d", &key);
	binarySearch(arr, n, key);
}

/*
Time complexity:
=> O(logn)
*/