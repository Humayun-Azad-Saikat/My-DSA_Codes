#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void printarr(int *arr,int n){

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

int maximum(int *arr,int n){

    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int *arr,int n){

    int i,j;
    int max = maximum(arr,n);

    int *count = (int*)malloc((max+1) * sizeof(int));//dynamically allocating max+1 size array

    //setting the count array elements to 0
    for(i = 0; i < max+1; i++){
        count[i] = 0;
    }

    //incrementing the corrosponding index in count array
    for(i = 0; i < n; i++){
        count[arr[i]] = count[arr[i]]+1;
    }

    i = 0;//for count array traverse
    j = 0;//for arr array

    while(i <= max){
        
        if(count[i]>0){
            arr[j] = i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
        
    }
}

int main(){

    int arr[] = {12,34,76,45,56};
    int n = 5;

    printarr(arr,n);
    count_sort(arr,n);
    printf("\n");
    printarr(arr,n);


    return 0;
}