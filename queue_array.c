#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

// function to check that queue is full or not.
int isfull(struct queue * ptr){
    if (ptr->r == ptr->size-1){
        return 1;
    }
    return 0;
}

// function to check that queue is empty or not.
int isempty(struct queue * ptr){
    if(ptr->f == ptr->r){
        return 1;
    }
    return 0;
}

// function for insertion of elemnts in queue
void enqueue(struct queue * ptr,int value){
    if(isfull(ptr)){
        printf("queue is full\n");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r] = value;
        printf("enqued elemnt is %d\n",value);
    }
}
// function for deletion of elemnts in queue
int dequeue(struct queue * ptr){
    if(isempty(ptr)){
        printf("queue is empty\n");
    }
    else{
        int a = -1;
        ptr->f++;
        a = ptr->arr[ptr->f];
        return a;
    }
}
    int main(){
        // Allocating dyanmic memory to queue
        struct queue* sq = (struct queue *)malloc(sizeof(struct queue));
        sq->size = 10;
        sq->f = sq->r = -1;
        sq->arr = (int*)malloc(sq->size * sizeof(int));
        printf("queue has been created succesfully\n");

        // inseting the values
        enqueue(sq,56);
        enqueue(sq,78);
        enqueue(sq,67);

        // deleting the values
        printf("element %d is popped from queue\n",dequeue(sq));
        printf("element %d is popped from queue\n",dequeue(sq));
        
    
    return 0;
}