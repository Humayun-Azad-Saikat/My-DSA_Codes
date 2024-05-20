#include<stdio.h>
#include<stdbool.h>

void displayArr(int *arr,int size){

for(int i = 0; i < size; i++){
    printf("%d ",arr[i]);
}
printf("\n");
}



void deletion(int *arr,int size,int index){

for(int i = index; i < size-1; i++){
   arr[i] = arr[i+1];   
}

}


int main(){

int arr[100] = {1,2,3,4};
int index = 2,size = 4;
displayArr(arr,size);
deletion(arr,size,index);
size -= 1;
displayArr(arr,size);


    return 0;
}