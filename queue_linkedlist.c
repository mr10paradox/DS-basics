#include <stdio.h>
#include <stdlib.h>

// creating a node
struct node
{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;

// implementing a function to traverse the array
void traversal(struct node *ptr)
{
    printf("elemnts of the linked list\n");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}

// creating a utility function to insert the element in queue
void enq(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("queue is full\n");
    }
    else
    {
        n->data = data;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
// creating a utility function to delete the element in queue
int deq(){
    int val = -1;
    struct node * ptr = f;
    if(f == NULL){
        printf("q is emp\n");
    }
    f = f->next;
    val = ptr->data;
    free(ptr);
    return val;
}

int main()
{

    traversal(f);

    // inserting the values into queue
    enq(5);
    enq(3);
    enq(4);
    enq(6);

    // deleting values from queue
    printf("dequueing elemnt %d\n",deq());
    traversal(f);

    return 0;
}