#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

// function to check that queue is empty or not.
int isempty(struct queue * ptr){
    if(ptr->r == ptr->f){
        return 1;
    }
    return 0;
}
// function to check that queue is full or not.
int isfull(struct queue * ptr){
    if((ptr->r+1)%ptr->size == ptr->f){
        return 1;
    }
    return 0;
}

// function for insertion of elemnts in circular queue
void enq(struct queue * ptr,int val){
    if(isfull(ptr)){
        printf("overflow\n");
    }
    else{
        ptr->r = (ptr->r +1)%ptr->size;
        ptr->arr[ptr->r] = val;
        printf("enqued element is %d\n",val);
    }
}

// function for deletion of elemnts in circular queue
int deq(struct queue * ptr){
    int a = -1;
    if(isempty(ptr)){
        printf("q is empty\n");
    }
    else{
        ptr->f = (ptr->f + 1)%ptr->size;
        a = ptr->arr[ptr->f];
    }
    return a;
}
    int main(){
        // Allocating dyanmic memory to  circular queue
        struct queue* q = (struct queue *)malloc(sizeof(struct queue));
        q->f = q->r = 0;
        q->size = 4;
        q->arr = (int*)malloc(q->size * sizeof(int));
        printf("circular queue has been craeated succesfully\n");
        
        enq(q,67);
        enq(q,45);
        enq(q,57);
        printf("----\n");
        printf("element %d is removed from circular queue\n",deq(q));
        printf("element %d is removed from circular queue\n",deq(q));
        printf("element %d is removed from circular queue\n",deq(q));
        printf("----\n");
        enq(q,36);
        enq(q,00);
        enq(q,367);
       
        
    
    return 0;
}