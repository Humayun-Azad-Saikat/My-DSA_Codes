#include<stdio.h>

void printarr(int *arr,int n){

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

void selection_sort(int *arr,int n){

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){

    int arr[] = {12,34,76,45,56};
    int n = 5;

    printarr(arr,n);
    selection_sort(arr,n);
    printf("\n");
    printarr(arr,n);

    return 0;
}