# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

Node *top = NULL;

void push(int);
void pop();
void display();

int main(){
	int choice, val;
	while(1){
		printf("Stack using linked list: \n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter the value to be insert: ");
				scanf("%d", &val);
				push(val);
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
}

void push(int element){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = element;
	newnode->next = top;
	top = newnode;
	printf("\nElement %d added to stack\n\n", element);
}

void pop(){
	if(top==NULL){
		printf("\nStack is empty\n\n");
		return;
	}
	Node *temp = top;
	printf("\nDeleted element: %d\n\n", temp->data);
	top = temp->next;
	free(temp);
}

void display(){
	if(top==NULL){
		printf("\nStack is emtpy\n\n");
		return;
	}
	Node *temp = top;
	printf("\n");
	while(temp!=NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("END\n\n");
}
