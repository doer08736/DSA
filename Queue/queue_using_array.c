# include <stdio.h>
# include <stdlib.h>
# define MAX 5

int queue[MAX], front=0, rear=0;

void push(){
	if(rear==MAX){
		printf("\nQueue is full\n\n");
		return;
	}
	int val;
	printf("Enter the element: ");
	scanf("%d", &val);
	queue[rear++] = val;
	printf("\nElement %d queue\n\n", val);
}

void pop(){
	if(front==rear){
		printf("\nThe queue is empty\n\n");
		return;
	}
	printf("\nDeleted element is: %d\n\n", queue[front++]);
	if(front==rear)
		front = rear = 0;
}

void display(){
	if(rear==0){
		printf("\nQueue is empty\n\n");
		return;
	}
	for(int i=front; i<rear; i++)
		printf("%d ", queue[i]);
	printf("\n");
}

int main(){
	int ch, val;
	do{
		printf("Queue using array: \n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("\nEnter a valid choice\n\n");
		}
	}while(1);
	return 0;
}
