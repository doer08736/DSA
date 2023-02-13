# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

Node *head = NULL;
int size = 0;

int isEmpty(){
	if(head==NULL){
		printf("\nLinked list is empty\n");
		return 1;
	}
	return 0;
}

int isOverflow(Node *node){
	if(node==NULL){
		printf("\nOut of memory space\n");
		return 1;
	}
	return 0;
}

void displayLL(){
	if(isEmpty())
		return;
	Node *temp = head;
	do{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}while(temp!=head);
	printf("END\n");
}

void displaySize(){
	if(isEmpty())
		return;
	printf("\nSize of linked list is: %d\n", size);
}

void insertBeg(){
	Node *newnode = (Node*)malloc(sizeof(Node));
	if(isOverflow(newnode))
		return;
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	if(head==NULL){
		newnode->next = newnode;
		head = newnode;
		return;
	}
	newnode->next = head->next;
	head->next = newnode;
	size++;
}

void insertEnd(){
	if(head==NULL)
		return insertBeg();
	Node *newnode = (Node*)malloc(sizeof(Node));
	if(isOverflow(newnode))
		return;
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	
