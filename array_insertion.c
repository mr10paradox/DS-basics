#include<stdio.h>

// implemnting function to traverse the array..
void display(int arr[],int n)
{
    for(int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
}

// implemnting function for inseriont of elements in array. 
int insertion(int arr[],int size,int element,int capacity,int index)
{
    // checking the array is full or not.
    if(size>= capacity){
        return -1;
    }
    for(int i=size-1;i >= index;i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return index;
}

    int main(){
        // initalizing array 
        int arr[100] = {7,8,12,27,88};
        int size = 5,element = 45,index=3,capacity = 100;
        
        printf("Array before insertion\n");
        display(arr,size);

        insertion(arr,size,element,capacity,index);
        size +=1;

        printf("Array after insertion\n");
        display(arr,size);
    
    return 0;
}