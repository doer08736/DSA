# include <stdio.h>

// display the array
void display(int *arr, int size){
	for(int i=0; i<size; i++)
		printf("%d ", *(arr+i));
	printf("\n");
}

// swapping without creating temp variable
void swap(int *a, int *b){
	if(a==b)
		return;
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

// quicksort algorithm
void quicksort(int *arr, int low, int high){
	int pivot, i, j;
	if(low<high){
		i = low;
		pivot = i;
		j = high;
		while(i<j){
			while(*(arr+i)<=*(arr+pivot))
				i++;
			while(*(arr+j)>*(arr+pivot))
				j--;
			if(i<j)
				swap(arr+i, arr+j);
		}
		swap(arr+pivot, arr+j);
		quicksort(arr, low, j-1);
		quicksort(arr, j+1, high);
	}
}		

int main(){
	int arr[] = {1, 8, 0, 2, 0};
	int size = sizeof(arr)/sizeof(int);
	printf("Array before quicksort: ");
	display(arr, size);
	
	quicksort(arr, 0, size-1);
	
	printf("Array after quicksort: ");
	display(arr, size);
	return 0;
}	
