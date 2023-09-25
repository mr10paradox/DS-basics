#include<stdio.h>

// implemnting function to traverse the array..
void display(int arr[],int n)
{
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

// implemnting function for deletion of elements in array. 
void deletion(int arr[],int size,int index)
{
    for(int i = index;i < size-1;i++){
        arr[i] = arr[i+1];
    }
}

    int main(){
        // initializing array
        int arr[100] = {7,8,12,27,88};
        int size = 5,index = 2;
        
        printf("Array before deltion\n");
        display(arr,size);

        deletion(arr,size,index);
        size -=1;

        printf("Array after deltion\n");
        display(arr,size);

    
    return 0;
}