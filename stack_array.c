#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

// function to check that stack is empty or not
int isempty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// function to check that stack is full or not
int isfull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

// function to push the element in the stack
int push(struct stack *ptr,int value){
    if(isfull(ptr)){
        printf("stack overflow!!\n");
    }
    else{

        ptr->top++;
        ptr->arr[ptr->top] = value;
        return value;
    }
}

// function to pop the element from the stack
int pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("stack underflow!!\n");
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

// function to check the elemnts in the stack
int peek(struct stack * ptr,int i){
    int indarray = ptr->top-i+1;
    if(indarray<0){
        printf("not a valid position for stack\n");
    }
    else{
        return ptr->arr[indarray];
    }
}

    int main(){
        // Allocating memory dynamically to the stack
        struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
        sp->size = 10;
        sp->top = -1;
        sp->arr = (int *)malloc(sp->size*sizeof(int));      
        printf("stack has been created succesfully \n");

        printf("the value %d is pushed into the stack\n",push(sp,68));
        printf("the value %d is pushed into the stack\n",push(sp,89));
        printf("the value %d is pushed into the stack\n",push(sp,78));
        printf("the value %d is pushed into the stack\n",push(sp,56));
       
        printf("the value %d is popped from stack\n",pop(sp));
        
        for(int j=1;j<=sp->top+1;j++){
            printf("the value at position %d is %d\n",j,peek(sp,j));
        }
    return 0;
}