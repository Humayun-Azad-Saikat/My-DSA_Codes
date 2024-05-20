#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    //malloc

    int *ptr;
    int i;

    ptr=(int*)malloc(3*sizeof(int));
    
    for ( i = 0; i < 3; i++)
    {
        scanf("%d",&ptr[i]);
    }

    printf("values:\n");

    for ( i = 0; i < 3; i++)
    {
        printf("%d\n",ptr[i]);
    }
    
    




    return 0;
}
