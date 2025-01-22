#include<stdio.h>
#include<stdlib.h>
int top=-1;
int push(int);
int pop(int);
int display(int);
int stack[30];
int main()
{

int n,maxsize;
printf("Basic Operation of Stack\n");
printf("Enter the size of stack\n=>");
scanf("%d",&maxsize);
while(1)
{

printf("\nEnter your choice\n 1 for push\n 2 for pop\n 3 for display\n 4 for exit\n\n=>");
scanf("%d",&n);
switch(n)
{
	case 1: 
    push(maxsize);
    printf("pushed\n");
	break;
	case 2: 
    pop(maxsize);
    printf("pop\n");
	break;
	case 3: printf("\ndisplay\n");
    display(maxsize);
	break;
	default:
		exit(0);
}
}

}
int push(int max)
{
	int a;

	if (top==max-1)
	printf("stack is full\n");
	else
		printf("enter the value to be push\n=>");
	scanf("%d",&a) ;
	top=top+1;
	stack[top]=a;
}
int pop(int max)
{
    if(top == -1){
        printf("Stack is underflow\n");
    }
    else{
        top= top-1;
        //stack[top] = 0;
    }
}
int display(int max){
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else{
        printf("\nHere are the entered value:\n");
        for(int i = 0; i < (top+1); i++)
        {
          /*  if(stack[i]==0){
                continue;
            }*/
           printf("=>%d\n",stack[i]);
        }
    }
        
}
