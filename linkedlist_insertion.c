#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

// function to traverse the linkedlist
void traversal(struct node * ptr){
    while(ptr != NULL){
        printf(" %d ",ptr->data);
        ptr = ptr->next;
    }

}

// function to insert the node at first in linkedlist
struct node* atfirst(struct node* head,int data){
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// function to insert the node in between in the linkedlist
struct node * inbetween(struct node* head,int data,int index){
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
    return ptr;
}

// function to insert the node at end in linkedlist
struct node * atend(struct node *head,int data){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    struct node * p = head;
    while(p->next != NULL){
        p = p->next; 
    }
    
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

    int main(){
        // creating the nodes
        struct node * head;
        struct node * second;
        struct node * third;

        // allocating memeory dynamically to the nodes
        head = (struct node *)malloc(sizeof(struct node));
        second = (struct node *)malloc(sizeof(struct node));
        third = (struct node *)malloc(sizeof(struct node));

        // setting the values in nodes
        head->data = 9;
        head->next = second;

        second->data = 11;
        second->next = third;

        third->data = 16;
        third->next = NULL;

        traversal(head);
        printf("\n");

        // inserting new nodes
        
        // head = atfirst(head,66);
        // head = inbetween(head,58,1);
        head = atend(head,58);
        traversal(head);

    
    return 0;
}