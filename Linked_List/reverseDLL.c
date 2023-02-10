# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
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

void reverseDLL(){
	 Node *current, *prev, *next;
	 current = head;
	 prev = NULL;
	 while(current!=NULL){
	 	next = current->next;
	 	current->next = prev;
	 	current->prev = next;
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
		newnode->prev = NULL;
		head = newnode;
		return;
	}
	Node *temp = head;
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next = newnode;
	newnode->prev = temp;
}	

int main(){
	insert();
	insert();
	insert();
	insert();
	insert();
	displayLL();
	reverseDLL();
	displayLL();
	return 0;
}
