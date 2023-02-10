/*
BFS (breadth-first-search): algorithm used to traverse graph
(uses queue data structure)
*/

# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    unsigned short int data;
    struct node *next;
}Node;


Node *front = NULL;
Node *rear = NULL;


unsigned short int isEmpty(){
    if(front==NULL)
        return 1;
    return 0;
}

void enqueue(unsigned short int element){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = element;
    newnode->next = NULL;
    if(front==NULL){
        front=rear=newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}

unsigned short int deque(){
    if(isEmpty())
        return 0;
    Node *temp = front;
    unsigned short int element = front->data;
    front = front->next;
    free(temp);
    return element;
}

void BFS(unsigned short int (*arr)[5], int n){
    unsigned short int i = 0, node;
    static unsigned short int visited[5];
    printf("%d ", i+1);
    *(visited+i) = 1;
    enqueue(i);

    while(!isEmpty()){
        node = deque();
        for(register unsigned short int j=1; j<n; ++j){
            if(*(*(arr+node)+j)==1 && !*(visited+j)){
                printf("%d ", j+1);
                *(visited+j) = 1;
                enqueue(j);
            }
        }
    }
    printf("\n");
}

unsigned short int main(){
    
    unsigned short int adjMatrix[][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    BFS(adjMatrix, 5);

    return 0;
}

/*
      2 --- 3
    / |   / |
  1   |  /  |
    \ | /   |
      4 --- 5
*/

/*
Ouput:
1 2 4 3 5
*/