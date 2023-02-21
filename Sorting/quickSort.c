# include <stdio.h>


void display(int *arr, int n){
    for(register unsigned short int i=0; i<n; ++i)
        printf("%d ", *(arr+i));
    printf("\n");
}

void swap(int *a, int *b){
    if(*a==*b)
        return;
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

int partition(int *arr, int lb, int ub){
    int x = *(arr+ub), i = lb-1, j;
    for(j=lb; j<ub; ++j){
        // *(arr+j)>= x (if wanna sort in descending order)
        if(*(arr+j)<=x)
            swap(arr+(++i), arr+j);
    }
    swap(arr+(++i), arr+j);
    return i;
}

void quickSort(int *arr, int lb, int ub){
    if(lb>=ub)
        return;
    int pivot = partition(arr, lb, ub);
    quickSort(arr, lb, pivot-1);
    quickSort(arr, pivot+1, ub);
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(register unsigned short int i=0; i<n; ++i)
        scanf("%d", arr+i);

    printf("before sorting: ");
    display(arr, n);

    quickSort(arr, 0, n-1);

    printf("after sorting: ");
    display(arr, n);

    return 0;
}

/*
Time complexity:

(worst-case):
array: 10 20 30 40 50

T(n) = n + T(i) + T(n-i-1) {i=n-1}
T(n) = n + T(n-1) + T(n-(n-1)-1)
T(n) = n + T(n-1)
T(n) = O(n^2)

=> O(n^2)

(best-case):
array: 10 80 70 20 30 50 60 40
10 20 30 -40- 70 50 60 80

T(n) = n + T(i) + T(n-i-1) {i=n/2} 
T(n) = T(n/2)+T(n-n/2-1) + n
T(n) = 2T(n/2) + n
T(n) = O(n*logn)

=> O(n*logn)
*/


/*
Output:
9
7 8 0 -3 0 1 4 38 3
7 8 0 -3 0 1 4 38 3
-3 0 0 1 3 4 7 8 38
*/