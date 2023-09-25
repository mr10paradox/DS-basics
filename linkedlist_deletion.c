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

// function to delete the node at first in linkedlist
struct node* atfirst(struct node* head){
    struct node*ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// function to delete the node from between in linkedlist
struct node * inbetween(struct node* head,int index){
    
    struct node * p = head;
    struct node* q = head->next;
    int i = 0;
    while(i != index-1){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
    
}

// function to delete the node at end in linkedlist
struct node * atend(struct node *head){
    struct node * p = head;
    struct node * q = head->next;

    while(q->next != NULL){
        p = p->next; 
        q = q->next; 
    }
    p->next = NULL;
    free(q);
    return head;
}

    int main(){
        // creating some nodes
        struct node * head;
        struct node * second;
        struct node * third;

        // allocating memeory dynamically to the nodes
        head = (struct node *)malloc(sizeof(struct node));
        second = (struct node *)malloc(sizeof(struct node));
        third = (struct node *)malloc(sizeof(struct node));

        head->data = 9;
        head->next = second;

        second->data = 11;
        second->next = third;

        third->data = 16;
        third->next = NULL;

        traversal(head);
        printf("\n");

        // deleting the nodes
        
        // head = atfirst(head);
        // head = inbetween(head,1);
        head = atend(head);
        
        traversal(head);

    
    return 0;
}