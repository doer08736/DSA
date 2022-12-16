# include <stdio.h>
# include <stdlib.h>
# define max 5

int stack[5], top=0;

void push();
void pop();
void display();

int main(){
	int ch;
	do{
		printf("Stack using array: \n");
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

void push(){
	if(top==max){
		printf("\nStack Overflow\n\n");
		return;
	}
	int element;
	printf("Enter the element to add: ");
	scanf("%d", &element);
	stack[top++] = element;
	printf("\nElement %d added to stack\n\n", element);
}

void pop(){
	if(top==0){
		printf("\nStack Underflow\n\n");
		return;
	}
	printf("\nElement %d removed from stack\n\n", stack[--top]);
}

void display(){
	if(top==0){
		printf("\nStack is empty\n\n");
		return;
	}
	printf("\n");
	for(int i=0; i<top; i++)
		printf("%d\t", stack[i]);
	printf("\n\n");
}
	
