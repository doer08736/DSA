# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

Node *front = NULL;
Node *rear = NULL;

void display(){
	if(front==NULL){
		printf("\nQueue is empty\n\n");
		return;
	}
	Node *temp = front;
	printf("\nDisplaying queue: ");
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void push(){
	Node *newnode = (Node*)malloc(sizeof(Node));
	int element;
	printf("Enter the element: ");
	scanf("%d", &element);
	newnode->data = element;
	newnode->next = NULL;
	printf("\nElement %d queue\n", element);
	if(front==NULL){
		front=rear=newnode;
		return;
	}
	rear->next = newnode;
	rear = newnode;
}

void pop(){
	if(front==NULL){
		printf("\nQueue is empty\n\n");
		return;
	}
	Node *temp = front;
	front = front->next;
	printf("\nDeleted %d from queue\n", temp->data);
	free(temp);
}

int main(){
	int choice, val;
	while(1){
		printf("Queue using linked list: \n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
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
	}
	return 0;
}
