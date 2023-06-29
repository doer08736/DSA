# include <stdio.h>


void slidingWindowSum(int *arr, int n, int k){
	int i, sum = 0;
	for(i=0; i<k; ++i)
		sum += *(arr+i);
	for(i=1; i<n-k+1; ++i){
		sum = sum-arr[i-1]+arr[i+k-1];
		printf("%d ", sum);
	}
	printf("\n");
}

int main(){
	int n, k;
	printf("enter array & window size: ");
	scanf("%d%d", &n, &k);
	int arr[n];
	printf("enter array elements: ");
	for(int i=0; i<n; ++i)
		scanf("%d", arr+i);
	slidingWindowSum(arr, n, k);

	return 0;
}
/*
Time Complexity: O(n)

Input:
enter array & window size: 6 3
enter array elements: 1 2 3 4 5 6

Output:
9 12 15 
*/
