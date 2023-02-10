# include <stdio.h>
# define MAX 100


void display(int *arr, unsigned short int n){
    for(register unsigned short int i=0; i<n; ++i)
        printf("%d ", *(arr+i));
    printf("\n");
}

void takeInput(int *arr, unsigned short int n, unsigned short int k){
    printf("enter elements of array1: ");
    for(register unsigned short int i=0; i<n; ++i){
        if(i==k)
            printf("enter elements of array2: ");
        scanf("%d", arr+i);
    }
}

void mergeTwoSortedArray(int *arr, unsigned short int mid, unsigned short int lb, unsigned short int ub){
    int arrX[MAX];
    unsigned short int i=lb, j=mid+1, k=lb;
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

unsigned short main(){
    
    int arr[MAX];
    unsigned short int n, m;

    printf("enter the size of array1: ");
    scanf("%d", &n);

    printf("enter the size of array2: ");
    scanf("%d", &m);
    
    unsigned short int size = m+n;

    takeInput(arr, size, n);

    printf("before merging: ");
    display(arr, size);

    mergeTwoSortedArray(arr, n-1, 0, size-1);

    printf("after merging: ");
    display(arr, size);

    return 0;
}

/*
Output:
enter the size of array1: 4
enter the size of array2: 6
enter elements of array1: 2 3 56 87
enter elements of array2: 0 4 8 4 13 14
before merging: 2 3 56 87 0 4 8 4 13 14 
*/