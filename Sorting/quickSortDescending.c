# include <stdio.h>

void display(int *arr, int size){
	for(register int i=0; i<size; i++)
		printf("%d ", *(arr+i));
	printf("\n");
}

void quicksort(int *arr, int low, int high){
	int pivot, i, j, temp;
	if(low<high){
		pivot = low;
		i = low;
		j = high;
		while(i<j){
			while(*(arr+i)>=*(arr+pivot) && i<=high)
				i++;
			while(*(arr+j)<*(arr+pivot) && j>=low)
				j--;
			if(i<j){
				temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
		temp = *(arr+pivot);
		*(arr+pivot) = *(arr+j);
		*(arr+j) = temp;
		quicksort(arr, low, j-1);
		quicksort(arr, j+1, high);
	}
}		

int main(){
	int arr[] = {0,2,0,8,1};
	int size = sizeof(arr)/sizeof(int);
	printf("Array before quicksort: ");
	display(arr, size);
	
	quicksort(arr, 0, size-1);
	
	printf("Array after quicksort: ");
	display(arr, size);
	return 0;
}	
