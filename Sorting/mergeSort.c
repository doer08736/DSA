# include <stdio.h>
# define MAX 100


void display(int *arr, unsigned short int n){
    for(register unsigned short int i=0; i<n; ++i)
        printf("%d ", *(arr+i));
    printf("\n");
}

void mergeTwoSortedArray(int *arr, unsigned short int lb, unsigned short int ub){
    int arrX[MAX];
    unsigned short int mid = (lb+ub)/2, i=lb, j=mid+1, k=lb;
    while(i<=mid && j<=ub)
        *(arrX+k++) = (*(arr+i)>*(arr+j)) ? *(arr+j++) : *(arr+i++);
    if(i>mid){
        while(j<=ub)
            *(arrX+k++) = *(arr+j++);
    }
    if(j>ub){
        while(i<=mid)
            *(arrX+k++) = *(arr+i++);
    }
    for(register unsigned short int i=0; i<=ub; ++i)
        *(arr+i) = *(arrX+i);
}

void mergeSort(int *arr, unsigned short int lb, unsigned short int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        mergeTwoSortedArray(arr, lb, ub);
    }
}

unsigned short int main(){

    int n;
    scanf("%d", &n);
    int arr[n];
    for(register unsigned short int i=0; i<n; ++i)
        scanf("%d", arr+i);

    printf("array before merge sort: ");
    display(arr, n);

    mergeSort(arr, 0, n-1);

    printf("array after merge sort: ");
    display(arr, n);

    return 0;
}

/*
Output:
10
5 7 0 -4 84 9 39 27 1 0
array before merge sort: 5 7 0 -4 84 9 39 27 1 0 
array after merge sort: -4 0 0 1 5 7 9 27 39 84
*/