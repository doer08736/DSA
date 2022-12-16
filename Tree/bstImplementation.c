# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node *root = NULL;

Node *createNewnode(int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void preorder(Node *temp){
    if(temp==NULL)
        return;
    printf("%d -> ", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void inorder(Node *temp){
    if(temp==NULL)
        return;
    inorder(temp->left);
    printf("%d -> ", temp->data);
    inorder(temp->right);
}

void postorder(Node *temp){
    if(temp==NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    printf("%d -> ", temp->data);
}

Node *insert(Node *root, int val){
    if(root==NULL){
        root = createNewnode(val);
    }
    else if(val<=root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

int main(){
    root = insert(root, 32);
    root = insert(root, 21);
    root = insert(root, 76);
    root = insert(root, 29);
    root = insert(root, 56);
    root = insert(root, 81);
    root = insert(root, 0);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}
