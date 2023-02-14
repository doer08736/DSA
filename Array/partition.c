# include <stdio.h>


void swap(int *a, int *b){
    if(*a==*b)
        return;
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

void display(int *arr, unsigned short int n){
    for(register unsigned short int i=0; i<n; ++i)
        printf("%d ", *(arr+i));
    printf("\n");
}

int partition(int *arr, int lb, int ub){
    int x = *(arr+ub), i = lb-1, j;
    for(j=lb; j<ub; ++j){
        if(*(arr+j)<=x)
            swap(arr+(++i), arr+j);
    }
    swap(arr+(++i), arr+j);
    return i;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(register unsigned short int i=0; i<n; ++i)
        scanf("%d", arr+i);
    
    display(arr, n);

    printf("original index: %d\n", partition(arr, 0, n-1));

    display(arr, n);

    return 0;
}