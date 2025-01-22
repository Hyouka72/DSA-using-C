#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
    int size,i,additional,newsize;                      //Initialize the variable 
    int *ptr;
    printf("Enter the size you want to enter=>");       //set size
    scanf("%d",&size);
    ptr = (int*)malloc(size*sizeof(int));
    if(ptr == NULL){                                    //NULL checking
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Here are the data while using malloc\n=>"); //Displaying garbage value of malloc
        for (i = 0; i < size; i++)
    {
        printf("%d\t",*(ptr+i));
    }
    ptr = (int*)calloc(size,sizeof(int));
    printf("\nHere are the while using calloc\n=>");    //Displaying garbage value of calloc
        for (i = 0; i < size; i++)
    {
        printf("%d\t",*(ptr+i));
    }
    printf("\nEnter the value below:\n");               //Entering value
    for (i = 0; i < size; i++)
    {
        printf("=>");
        scanf("%d",(ptr+i));
    }
    printf("Here are the entered data\n=>");            //Displaung entered value
        for (i = 0; i < size; i++)
    {
        printf("%d\t",*(ptr+i));
    }
    printf("\nEnter the additional size:\n=>");         //Setting additional value
    scanf("%d",&additional);
    newsize = size + additional;
    ptr = (int*)realloc(ptr,newsize*sizeof(int));
    printf("Enter the value below:\n");                 //Value of addiational size
    for(i=size; i < newsize; i++){
        printf("=>");
        scanf("%d",(ptr+i));
    }
    printf("\nHere are the all entered value\n");       //Display all the value
    for ( i = 0; i < newsize; i++)
    {
        printf("=>%d\n",*(ptr+i));
    }
    
    getch();
    free(ptr);
    
    return 0;
}