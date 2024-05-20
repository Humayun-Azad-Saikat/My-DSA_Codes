#include<stdio.h>
#include<stdbool.h>

void display(int *arr,int size){

for(int i = 0; i < size; i++){
  printf("%d ",arr[i]);
}
printf("\n");
}


bool inset(int *arr,int size,int element,int capacity,int index){

if (size >= capacity){
     return false;
}

for (int i = size-1; i >= index ; i--){

arr[i+1] = arr[i];

}
arr[index] = element;
return true;

}


int main(){

int arr[100] = {1,2,3,4},size = 4;

display(arr,size);
inset(arr,size,7,100,3);
size += 1;
display(arr,size);



    return 0;
}