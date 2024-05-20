#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    //use of calloc

    int *ptr;
    int i;

    ptr = (int*)calloc(5,sizeof(int));

    for ( i = 0; i < 5; i++)
    {
        scanf("%d",&ptr[i]);
    }

    printf("values:\n");

    for ( i = 0; i < 5; i++)
    {
       printf("%d\n",ptr[i]);
    }
    


    return 0;
}
