#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

// function to check that stack is empty or not
int isempty(struct node * top){
    if(top == NULL){
        return 1;
    }
    return 0;
}

// function to check that stack is full or not
int isfull(struct node * top){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
    }
    return 0;
}
// declaring the first node globally not in main..
struct node * top = NULL;

// function to check the elements in the stack
void traversal(struct node* ptr){

    while(ptr != NULL){
        printf(" %d",ptr->data);
        ptr = ptr->next;
    }   
}

// function to push the element in the stack
struct node* push(struct node * top,int x){
    if(isfull(top)){
        printf("stack overflow!!\n");
    }
    else{
        struct node*n = (struct node*)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

// function to pop the element from the stack
int pop(struct node*  tp){
    if(isempty(tp)){
        printf("stack underflow!!\n");
    }
    else{
        struct node*n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}


    int main(){
        
        // pushing values into stack.
        top = push(top,7);
        top = push(top,6);
        top = push(top,5);
        traversal(top);
        printf("\n");

        // popping values from stack.
        int element = pop(top);
        printf("popped element is %d\n",element);
        traversal(top);

    return 0;
}