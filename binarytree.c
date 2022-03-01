#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree *left, *right;
}node;

node* insert(node* root, int data);
int search(node* root, int key);
void inorder(node* root);
void postorder(node* root);
void preorder(node* root);

int main(){
    node *root = NULL;
    int o=0, key=0;
    while(o!=4){
        printf("\n1)Insert\n2)Delete\n3)Traverse\n4)Exit\nEnter Operation : ");
        scanf("%d", &o);
        if(o==1){
            printf("\nEnter value to insert : ");
            scanf("%d", &key);
            if(!root){
                root=insert(NULL, key);}
            else
                insert(root, key);
            printf("\nBinary Tree : ");
            inorder(root);
        }
        else if(o==2){
            printf("\n1)Inorder Traversal\n2)Preorder Traversal\n3)Postorder Traversal\nEnter Option : ");
            scanf("%d", &key);
            printf("\nBinary Tree : ");
            if(key==1)
                inorder(root);
            else if(key==2)
                preorder(root);
            else if(key==3)
                postorder(root);
            else
                printf("Invalid Selection");
        }
        else if(o==3){
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
    char dir='f';
    node *temp;
    while(root!=NULL){ 
        fflush(stdin);
        printf("\nleft(l) or right(r)\nEnter : ");
        scanf("%c", &dir);
        temp = root;
        if(dir=='l')
            root=root->left;
        else if(dir=='r')
            root=root->right;
    }
    node *n = create(data);
    if(dir=='l')
        temp->left=n;
    else if(dir=='r')
        temp->right=n;
    return n;
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void postorder(node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(node* root){
    if(root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}