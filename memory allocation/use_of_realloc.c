#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int *ptr;
    int i;

    //calloc

    ptr=(int*)calloc(5,sizeof(int));

    for(i = 0;i < 5;i++){
        scanf("%d",&ptr[i]);
    }

    printf("values:\n");

    for ( i = 0; i < 5; i++)
    {
        printf("%d\n",ptr[i]);
    }
    
    //realloc

    int n;
    printf("Enter n:");
    scanf("%d",&n);

    ptr = (int*)realloc(ptr,n*sizeof(int));

    
    for(i = 0;i < n;i++){
        scanf("%d",&ptr[i]);
    }

    printf("new values are:\n");

     for ( i = 0; i < n; i++)
    {
        printf("%d\n",ptr[i]);
    }



    return 0;
}
