#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree *left, *right;
}node;

node* insert(node* root, int data);
int search(node* root, int key);
void inorder(node* root);

int main(){
    node *root = NULL;
    int o=0, key=0;
    while(o!=5){
        printf("\n1)Insert\n2)Search\n3)Traverse\n4)Exit\nEnter Operation : ");
        scanf("%d", &o);
        if(o==1){
            printf("\nEnter value to insert : ");
            scanf("%d", &key);
            if(!root)
                root=insert(root, key);
            else
                insert(root, key);
            printf("\nBinary Tree : ");
            inorder(root);
        }
        else if(o==2){
            int found;
            printf("\nEnter number to search : ");
            scanf("%d", &key);
            found = search(root, key);
            printf("%d", found);
        }
        else if(o==3){
            
        }
        else if(o==4){
            continue;
        }
    }
    return 0;
}

node* create(int data){
    node *x = (node*)malloc(sizeof(node));
    x->data=data;
    x->left=NULL, x->right=NULL;
    return x;
}

node* insert(node* root, int data){
    if(root==NULL) 
        return create(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int search(node* root, int key){
    if(root == NULL) 
        return NULL;
    if(key == root->data) 
        return root->data;
    if(key < root->data) 
        return search(root->left, key);
    if(key > root->data) 
        return search(root->right, key);
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}