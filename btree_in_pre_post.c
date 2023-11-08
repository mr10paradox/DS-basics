#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

// function to create a node 
struct node* createnode(int data){
    struct node * n = (struct node*)malloc(sizeof(struct node));
        n->data = data;
        n->left = NULL;
        n->right = NULL;
        return n;
}

void preorder(struct node* root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

    int main(){
      
        struct node * p = createnode(4);
        struct node * p1= createnode(1);
        struct node * p2 = createnode(6);
        struct node * p3 = createnode(5);
        struct node * p4 = createnode(2);

        // linking root node  eith left and right children

        p->left = p1;
        p->right = p2;

        p1->left = p3;
        p1->right = p4;

        // preorder(p);
        // postorder(p);
        inorder(p);
    
    return 0;
}