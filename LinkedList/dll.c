# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
}node;

node *head = NULL;
node *tail = NULL;
int size = 0;

node *getNode(int index){
	node *temp = head;
	for(int i=0; i<index; ++i){
		temp = temp->next;
	}return temp;
}

void displayLL(){
	node *temp = head;
	while(temp!=NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}printf("END\n");
}

void displayLLRev(){
	node *temp = tail;
	while(temp!=NULL){
		printf("%d -> ", temp->data);
		temp = temp->prev;
	}printf("END\n");
}

void insertBeg(int val){
	node *newnode = (node*)malloc(sizeof(*newnode));
	newnode->data = val;
	newnode->next = head;
	newnode->prev = NULL;
	if(head!=NULL) head->prev = newnode;
	head = newnode;
	if(tail==NULL) tail = head;
	size++;
}		

void insertEnd(int val){
	if(tail==NULL){
		return insertBeg(val);
		
	}
	node *newnode = (node*)malloc(sizeof(*newnode));
	newnode->data = val;
	tail->next = newnode;
	newnode->prev = tail;
	tail = newnode;
	size++;
}

void insertAtIndex(int index, int val){
	if(index==0) return insertBeg(val);
	if(index==size) return insertEnd(val);
	if(index>size){
		printf("Idiot the linked list don't even have that much element rn\n");
		return;
	}
	node *newnode = (node*)malloc(sizeof(*newnode));
	newnode->data = val;
	node *prevnode = getNode(index-1);
	newnode->next = prevnode->next;
	prevnode->next = newnode;
	newnode->prev = prevnode;
	if(newnode->next!=NULL) newnode->next->prev = newnode;
	size++;
}

void deleteBeg(){
	head = head->next;
	if(head==NULL) tail = NULL;
	else head->prev = NULL;
	size--;
}

void deleteEnd(){
	if(size<=1) return deleteBeg();
	node *prevnode = getNode(size-2);
	tail = prevnode;
	tail->next = NULL;
	size--;
}

void deleteAtIndex(int index){
	if(index==0) return deleteBeg();
	if(index==size-1) return deleteEnd();
	if(index>=size) printf("Idiot the linked list don't even have that much element rn\n");
	node *prevnode = getNode(index-1);
	prevnode->next = prevnode->next->next;
	prevnode->next->prev = prevnode;
	size--;
}

void main(){
	insertBeg(9);
	insertBeg(4);
	insertBeg(2);
	insertBeg(6);
	deleteAtIndex(2);
	displayLL();
}
