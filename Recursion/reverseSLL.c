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

Node *reverseLL(Node *ptr){
	if(ptr==NULL || ptr->next==NULL)
		return ptr;
	Node *newnode = reverseLL(ptr->next);
	ptr->next->next = ptr;
	ptr->next = NULL;
	return newnode;	
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
	head = reverseLL(head);
	displayLL();
	return 0;
}
