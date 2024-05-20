#include<stdio.h>

void printarr(int *arr,int n){

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

void insertion_sort(int *arr,int n){

    int i,j;
    int key;
    for(i = 1; i < n; i++){
        
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

    }
}

int main(){

    int arr[] = {12,34,76,45,56};
    int n = 5;

    printarr(arr,n);
    insertion_sort(arr,n);
    printf("\n");
    printarr(arr,n);


    return 0;
}