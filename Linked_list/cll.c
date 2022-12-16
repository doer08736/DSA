# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node *head = NULL;
node *tail = NULL;
int size = 0;

void displayLL(){
	node *temp = head;
	if(temp!=NULL){
		do{
			printf("%d -> ", temp->data);
			temp = temp->next;
		}while(temp!=head);
	}printf("END\n");
}

node *getNode(int index){
	node *temp = head;
	for(int i=0; i<index; ++i){
		temp = temp->next;
	}return temp;
}

void insertBeg(int val){
	node *newnode = (node*)malloc(sizeof(*newnode));
	newnode->data = val;
	if(head==NULL){
		head = newnode;
		tail = newnode;
		return;
	}
	tail->next = newnode;
	newnode->next = head;
	head = newnode;
	size++;
}

void insertEnd(int val){
	node *newnode = (node*)malloc(sizeof(*newnode));
	newnode->data = val;
	if(head==NULL){
		head = newnode;
		tail = newnode;
		return;
	}
	tail->next = newnode;
	newnode->next = head;
	tail = newnode;
	size++;
}

void deleteBeg(){
	if(head==NULL){
		printf("No stuffs in linked list\n");
		return;
	}
	head = head->next;
	tail->next = head;
	size--;
}

void deleteEnd(){
	if(head==NULL){
		printf("No stuffs in linked list\n");
		return;
	}
	node *prevnode = getNode(size-2);
	tail = prevnode;
	prevnode->next = head;
	size--;
}

void deleteAtIndex(int index){
	if(head==NULL){
		printf("No stuffs in linked list\n");
		return;
	}
	if(index==0) return deleteBeg();
	if(index==size-1) return deleteEnd();
	node *prevnode = getNode(index-1);
	prevnode->next = prevnode->next->next;
	size--;
}

void main(){
	insertBeg(5);
	insertEnd(4);
	insertEnd(5);
	deleteAtIndex(1);
	displayLL();
}
