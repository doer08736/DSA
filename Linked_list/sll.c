# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node *head=NULL;
node *tail=NULL;
int size = 0;

// check if linked list is empty
int check(){
	if(head==NULL){
		printf("The linked list is empty stupid!\n");
		return 1;
	}return 0;
}

// check if memory space is available
int checkSpace(node *ptr){
	if(ptr==NULL){
		printf("Out of memory space\n");
		return 0;
	}
	return 1;
}

// insert element at the beginning
void insertBeg(int val){
	node *newnode = (node*)malloc(sizeof(*newnode));
	if(checkSpace(newnode)==0) return;
	newnode->data = val;
	newnode->next = head;
	head=newnode;
	if(tail==NULL) tail=head;
	size++;
}

// insert element at the end
void insertEnd(int val){
	if(tail==NULL) return insertBeg(val);
	node *newnode = (node*)malloc(sizeof(*newnode));
	if(checkSpace(newnode)==0) return;
	newnode->data = val;
	tail->next = newnode;
	tail = newnode;
	size++;
}

// insert element at given index
void insertAtIndex(int val, int index){
	if(index==0) return insertBeg(val);
	if(index==size) return insertEnd(val);
	if(index>size-1){
		printf("Idiot the linked list don't even have that much element!\n");
		return;
	}
	node *newnode = (node*)malloc(sizeof(*newnode));
	if(checkSpace(newnode)==0) return;
	int i=1;
	while(i!=index){
		head = head->next;
		i++;
	}
	newnode->data = val;
	newnode->next = head->next;
	head->next = newnode;
	size++;
}

// delete element from the beginning
void deleteBeg(){
	if(check()) return;
	node *temp = head;
	head = head->next;
	printf("The deleted element is %d\n", temp->data);
	free(temp);
	if(head==NULL) tail==NULL;
	size--;
}

// return the given index node
node *getSecondLast(int index){
	node *temp = head;
	for(int i=0; i<index; ++i){
		temp = temp->next;
	}return temp;
}

// delete element from the end
void deleteEnd(){
	if(size<=1) return deleteBeg();
	node *secondlast = getSecondLast(size-2);
	tail = secondlast;
	node *temp = tail->next;
	tail->next = NULL;
	printf("The deleted element is %d\n", temp->data);
	free(temp);
	size--;
}

// delete element from the given index
void deleteAtIndex(int index){
	if(index==0) return deleteBeg();
	if(index==size-1) return deleteEnd();
	if(index>size-1){
		printf("Idiot the linked list don't even have that much element!\n");
		return;
	}
	node *prev = getSecondLast(index-1);
	node *temp = prev->next;
	prev->next = prev->next->next;
	printf("The deleted element is %d\n", temp->data);
	free(temp);
	size--;
}

// display the linked list
void displayLL(){
	if(check()) return;
	node *temp = head;
	while(temp!=NULL){
		printf("%d -> ", temp->data);
		temp=temp->next;
	}printf("END\n");
}		

void main(){
	insertBeg(5);
	insertBeg(6);
	insertBeg(7);
	deleteAtIndex(1);
	displayLL();
}
