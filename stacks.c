#include<stdio.h>
#include<stdlib.h>

struct stacks{
    int top;
    int size;
    int *array;
}*stack=NULL;

void initialize(int size){
    stack = (struct stacks *)malloc(sizeof(struct stacks));
    stack->array=(int *)malloc(size*sizeof(int));
    stack->size=size;
    stack->top=-1;
}

void push(int n){
    if(stack->size-1==stack->top){
        printf("stack overflow\n");
    }
    else{
        stack->top++;
        stack->array[stack->top]=n;
    }
}

void pop(){
        if(stack->top==-1){
            printf("stack underflow\n");
        }
        else{
            stack->top--;
        }
}

void peek(){
        if(stack->top==-1){
            printf("empty stack\n");
        }
        else{
            printf("%d\n",stack->array[stack->top]);
        }
}

int main(){
    int n=0;
    printf("enter stack size: ");
    scanf("%d",&n);
    initialize(n);
    push(10);
    push(12);
    push(15);
    push(25);
    push(7);
    pop();
    peek();
    return 0;
}
