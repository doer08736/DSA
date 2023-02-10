# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

Node *head = NULL;

void displayLL(){
	Node *temp = head;
	while(temp!=NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("END\n");
}

void reverseLL(){
	Node *current, *next, *prev;
	current = head;
	prev = NULL;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void insert(){
	Node *newnode = (Node*)malloc(sizeof(Node));
	if(newnode==NULL){
		printf("Out of memory space\n");
		return;
	}
	printf("Enter the element: ");
	scanf("%d", &newnode->data);
	if(head==NULL){
		newnode->next = head;
		head = newnode;
		return;
	}
	Node *temp = head;
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next = newnode;
}	

int main(){
	insert();
	insert();
	insert();
	insert();
	insert();
	displayLL();
	reverseLL();
	displayLL();
	return 0;
}
