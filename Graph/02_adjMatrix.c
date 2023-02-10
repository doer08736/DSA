# include <stdio.h>

unsigned short int main(){
  
    unsigned short int adjMatrix[][5] = {
      0, 1, 0, 1, 0,
      1, 0, 1, 1, 0,
      0, 1, 0, 1, 1,
      1, 1, 1, 0, 1,
      0, 0, 1, 1, 0
    };
    
    for(register unsigned short int i=0; i<5; ++i){
        for(register unsigned short int j=0; j<5; ++j)
            printf("%d ", *(*(adjMatrix+i)+j));
        printf("\n");
    }

    return 0;
    
}

/*
      2 --- 3
    / |   / |
  1   |  /  |
    \ | /   |
      4 --- 5
*/