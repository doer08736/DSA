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
	}return 0;
}

int isOverflow(Node *node){
	if(node==NULL){
		printf("\nOut of memory space\n");
		return 1;
	}return 0;
}

void displayLL(){
	if(isEmpty()) return;
	Node *temp = head;
	printf("\nDisplaying linked list: ");
	while(temp!=NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}printf("END\n");
}

void displaySize(){
	if(isEmpty()) return;
	printf("\nSize of linked list: %d\n", size);
} 

void insertBeg(){
	Node *newnode = (Node*)malloc(sizeof(Node));
	if(isOverflow(newnode))
		return;
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	newnode->next = head;
	head = newnode;
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
	newnode->next = NULL;
	Node *temp = head;
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next = newnode;
	size++;
}

void insertAtPos(){
	int pos;
	printf("Enter the position: ");
	scanf("%d", &pos);
	if(pos==1){
		return insertBeg();
	}
	if(pos==size+1){
		return insertEnd();
	}
	Node *newnode = (Node*)malloc(sizeof(Node));
	if(isOverflow(newnode))
		return;
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	Node *temp = head;
	for(int i=1; i<pos-1; ++i)
		temp = temp->next;
	newnode->next = temp->next;
	temp->next = newnode;
	size++;	
}

void deleteBeg(){
	if(isEmpty()) return;
	Node *newnode;
	newnode = head;
	head = head->next;
	printf("The deleted element is: %d\n", newnode->data);
	free(newnode);
	size--;	
}

void deleteEnd(){
	if(isEmpty()) return;
	if(head->next==NULL) return deleteBeg();
	Node *newnode, *temp;
	newnode = head;
	while(newnode->next!=NULL){
		temp = newnode;
		newnode = newnode->next;
	}
	temp->next = NULL;
	printf("The deleted element is: %d\n", newnode->data);
	free(newnode);
	size--;
}

void deleteAtPos(){
	if(isEmpty()) return;
	int pos;
	printf("Enter the position to delete: ");
	scanf("%d", &pos);
	if(pos==1) return deleteBeg();
	if(pos==size) return deleteEnd();
	if(pos>size){
		printf("Linked list don't even have that much elements rn\n");
		return;
	}
	Node *newnode, *temp;
	for(int i=1; i<pos-1; i++){
		newnode = newnode->next;
	}
	temp = newnode->next;
	newnode->next = newnode->next->next;
	printf("The deleted element is: %d\n", temp->data);
	free(temp);
}

void main(){
	int choice;
	printf("Linked_List:\n");
	while(1){
		printf("\n1. Display linked list\n");
		printf("2. Insert at beginning\n");
		printf("3. Insert at end\n");
		printf("4. Insert at position\n");
		printf("5. Delete at beginning\n");
		printf("6. Delete at end\n");
		printf("7. Delete from position\n");
		printf("8. Display size of linked list\n");
		printf("9. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				displayLL();
				break;
			case 2:
				insertBeg();
				break;
			case 3:
				insertEnd();
				break;
			case 4:
				insertAtPos();
				break;
			case 5:
				deleteBeg();
				break;
			case 6:
				deleteEnd();
				break;
			case 7:
				deleteAtPos();
				break;
			case 8:
				displaySize();
				break;
			case 9:
				printf("\nBIE...\n\n");
				exit(0);
				break;
			default:
				printf("\nEnter a valid option pussy\n");
				break;
		}
	}
}
