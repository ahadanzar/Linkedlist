#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist{
    int data;
    struct linkedlist *link;
}node;

node* create();
node* push(node *top, int data);
node* pop(node *top);
void display(node *top);

int main(){
    node *top=NULL;
    int o=0;
    display(top);
    while(o!=3){
        printf("\n1)Push\n2)Pop\n3)Exit\nEnter operation : ");
        scanf("%d", &o);
        if(o==1){
            int data;
            printf("\nEnter value to be pushed : ");
            scanf("%d", &data);
            top = push(top, data);
            display(top);
        }
        else if(o==2){
            top = pop(top);
            display(top);
        }
        else if(o==3)
            continue;
    }
    return 0;
}

node* create(){
    node *x = (node*)malloc(sizeof(node));
    return x;
}

node* push(node *top, int data){
    int c;
    node* newnode = create();
    newnode->data = data;
    newnode->link = top;
    top = newnode;
    return top;
}

node* pop(node *top){
    if(top==NULL)
        printf("\nStack Underflow\n");
    else
        top=top->link;
    return top;
}

void display(node *top){
    node *i=top;
    printf("\nStack : ");
    if(top==NULL)
        printf(" \n");
    else{
        while(i->link!=NULL){
            printf("%d ", i->data);
            i=i->link;
        }
        printf("%d\n", i->data);
    }
}
