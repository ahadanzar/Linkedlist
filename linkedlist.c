#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist{
    int data;
    struct linkedlist *link;
}node;

node* create();
node* insert(node *head);
node* delete(node *head);
void display(node *head);

int main(){
    node *head=NULL;
    int o=0;
    while(o!=4){
        printf("\n1)Insert\n2)Delete\n3)Display\n4)Exit\nEnter operation : ");
        scanf("%d", &o);
        if(o==1){
            head = insert(head);
            display(head);
        }
        else if(o==2){
            head = delete(head);
            display(head);
        }
        else if(o==3){
            display(head);
        }
        else if(o==4)
            continue;
    }
    return 0;
}

node* create(){
    node *x = (node*)malloc(sizeof(node));
    return x;
}

node* insert(node *head){
    int c, data;
    node* newnode = create();
    printf("\nEnter number to insert : ");
    scanf("%d", &data);
    newnode->data = data;
    printf("\nInsert at the \n1)Beginning\n2)Any place, i\n3)End\nEnter choice : ");
    scanf("%d", &c);
    if(c==1 || head==NULL){ 
        newnode->link = head;
        head = newnode;
    }
    else if(c==2){
        printf("\nEnter position : ");
        scanf("%d", &c);
        node *i = head;
        for(int j=0;j<c-2;j++){
            i=i->link;
        }
        newnode->link=i->link;
        i->link=newnode;
    }
    else if(c==3){
        node *i = head;
        while(i->link != NULL){
            i=i->link;
        }
        i->link=newnode;
        newnode->link=NULL;
    }
    else{
        printf("\nInvalid Choice");
    }
    return head;
}

node* delete(node *head){
    int c;
    printf("\nDelete from the \n1)Beginning\n2)Any place, i\n3)End\nEnter choice : ");
    scanf("%d", &c);
    if(c==1){ 
        head=head->link;
    }
    else if(c==2){
        node *i = head;
        printf("\nEnter position : ");
        scanf("%d", &c);
        for(int j=0;j<c-2;j++){
            i=i->link;
        }
        node *temp = i->link;
        i->link = temp->link;
    }
    else if(c==3){
        node *i = head, *temp;
        while(i->link != NULL){
            temp=i;
            i=i->link;
        }
        temp->link=NULL;
    }
    return head;
}

void display(node *head){
    node *i=head;
    printf("\nLinkedList : ");
    while(i->link!=NULL){
        printf("%d ", i->data);
        i=i->link;
    }
    printf("%d\n", i->data);
}
