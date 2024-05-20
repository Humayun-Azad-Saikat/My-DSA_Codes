#include<stdio.h>

void printarr(int *arr,int n){

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

void bubble_sort(int *arr,int n){

    for(int i = 0; i <= n-1; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){

    int arr[] = {12,34,76,45,56};
    int n = 5;
    printarr(arr,n);
    bubble_sort(arr,n);
    printf("\n");
    printarr(arr,n);


    return 0;
}