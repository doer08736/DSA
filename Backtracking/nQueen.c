# include <stdio.h>
# include <stdlib.h>


void display(int *arr, int n){
	for(int i=0; i<n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int place(int *arr, int k, int i){
	for(int j=0; j<k; ++j){
		if(arr[j]==i || abs(arr[j]-i)==abs(j-k))
			return 0;
	}
	return 1;
}

void nQueen(int *arr, int k, int n){
	for(int i=0; i<n; ++i){
		if(place(arr, k, i)){
			arr[k] = i;
			if(k==n-1)
				display(arr, n);
			else
				nQueen(arr, k+1, n);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; ++i)
		arr[i] = -1;
	nQueen(arr, 0, n);

	return 0;
}

/* Time Complexity: O(n!) (O(2^n)) */

