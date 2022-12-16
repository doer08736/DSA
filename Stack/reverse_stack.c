# include <stdio.h>
# define MAX 6

int stack[6];
int top = 0;


void display(){
	for(int i=0; i<top; i++)
		printf("%d ", stack[i]);
	printf("\n");
}

void push(int element){
	if(top==MAX){
		printf("Stack overflow\n");
		return;
	}
	stack[top++] = element;
	printf("%d added to stack\n", element);
}

void pop(){
	if(top==0){
		printf("Stack underflow\n");
		return;
	}
	printf("%d removed from stack\n", stack[--top]);
}

void insertBottom(int item){
	if(top==0){
		stack[top++] = item;
		return;
	}
	int etop = stack[--top];
	insertBottom(item);
	stack[top++] = etop;
}

void reverseStack(){
	if(top!=0){
		int etop = stack[--top];
		reverseStack();
		insertBottom(etop);
	}
}

int main(){
	push(5);
	push(4);
	push(7);
	push(10);
	display();
	reverseStack();
	display();	
	return 0;
}
