#include<stdio.h>
#include<stdlib.h>

struct myArray{

int total_size;
int used_size;
int *ptr;

};

void createArray(struct myArray *a,int tsize,int usize){

a->total_size = tsize;
a->used_size = usize;
a->ptr = (int*)malloc(tsize*sizeof(int));

}

void setelement(struct myArray *a){
    int i;
    for ( i = 0; i < a->used_size; i++){

      scanf("%d",&(a->ptr)[i]);

    }
    
}

void getelement(struct myArray *a){

int i;
for ( i = 0; i < a->used_size; i++){
    
printf("%d\n",a->ptr[i]);

}


}


int main(){

struct myArray arr;

createArray(&arr,10,2);
setelement(&arr);
printf("getting element\n");
getelement(&arr);

    return 0;
}