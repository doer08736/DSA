/*
DFS (depth-first-search): algorithm used to traverse a graph
*/

# include <stdio.h>


void DFS(unsigned short int (*arr)[7], unsigned short int start, unsigned short int n){
    static unsigned short int visited[7];
    if(*(visited+start)==0){
        printf("%d ", start);
        *(visited+start) = 1;
        for(register unsigned short int j=0; j<n; ++j)
            DFS(arr, j, n);
    }
}

unsigned short int main(){
    
    unsigned short int adjMatrix[][7] = {
		{0, 1, 0, 1, 0, 0, 0},
		{1, 0, 1, 1, 0, 1, 1},
		{0, 1, 0, 1, 1, 1, 0},
		{1, 1, 1, 0, 1, 0, 0},
		{0, 0, 1, 1, 0, 0, 1},
		{0, 1, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 0, 0}
	};

    DFS(adjMatrix, 0, 7);
    printf("\n");

    return 0;
}

/*
0 ----- 1       
|     / | \ \ 
|   /   |  \ 5
| /     |  /\   
3 ----- 2    \
 \     /      \
   \ /         \
    4 --------- 6
*/

/*
Output
0 1 2 3 4 5 6
*/