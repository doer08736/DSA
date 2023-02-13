# include <stdio.h>


void binarySearch(int *arr, int lb, int ub, int key){
	if(lb>ub){
		printf("element not found\n");
		return;
	}
	int mid = (lb+ub)/2;
	if(key>*(arr+mid))
		binarySearch(arr, mid+1, ub, key);
	else if(key<*(arr+mid))
		binarySearch(arr, lb, mid-1, key);
	else{
		printf("element found at position: %d\n", mid+1);
		return;
	}
}

int main(){
	int arr[] = {4, 6, 12, 32, 54, 67, 99};
	int n = sizeof(arr)/sizeof(int);
	int key;
	scanf("%d", &key);

	binarySearch(arr, 0, n-1, key);

	return 0;
}

/*
Time complexity:
T(n) = T(n/2) + 1
T(n) = O(logn)

=> O(logn)
*/

/*
Output:
99
element found at position: 7

0
element not found
*/
