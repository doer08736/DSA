# include <stdio.h>
# include <stdlib.h>


void swap(int *x, int *y){
    if(*x==*y)
        return;
    *x = *x+*y;
    *y = *x-*y;
    *x = *x-*y;
}

void display(int *arr, int i, int n){
    if(i==n){
        printf("\n");
        return;
    }
    printf("%d ", *(arr+i));
    display(arr, ++i, n);
}

void minHeapify(int *arr, int i, int n){
    int smallest = i, left = 2*i+1, right = 2*i+2;
    if(left<n && *(arr+left)<*(arr+smallest))
        smallest = left;
    if(right<n && *(arr+right)<*(arr+smallest))
        smallest = right;
    if(smallest!=i){
        swap(arr+i, arr+smallest);
        minHeapify(arr, smallest, n);
    }
}

void buildMinHeap(int *arr, int n){
    for(register int i=n/2-1; i>=0; --i)
        minHeapify(arr, i, n);
}

int main(){
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(register unsigned short int i=0; i<n; ++i)
        scanf("%d", arr+i);
    
    buildMinHeap(arr, n);
    display(arr, 0, n);

    return 0;
}