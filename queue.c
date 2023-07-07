#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front;
    int rear;
    int *array;
    int size;
}*queue_ptr;

void initialize(int n){
    queue_ptr=(struct queue*)malloc(sizeof(struct queue));
    queue_ptr->size=n;
    queue_ptr->front=-1;
    queue_ptr->rear=-1;
    queue_ptr->array=(int *)malloc(n*sizeof(int));
}

void is_empty(){
    if(queue_ptr->front==queue_ptr->rear){
        printf("stack empty\n");
    }
    else{
        printf("stack is not empty\n");
    }
}

int push(int value){
        if(queue_ptr->rear==queue_ptr->size-1){
            printf("queue overflow\n");
        }
        else{
            queue_ptr->rear++;
            queue_ptr->array[queue_ptr->rear]=value;
        }
}

void pop(){
    if(queue_ptr->front==queue_ptr->rear){
        printf("queue underflow\n");
    }
    else{
        queue_ptr->front++;
    }
}

int main(){
    int n=0;
    printf("enter size: ");
    scanf("%d",&n);
    initialize(n);
    push(5);
    push(7);
    push(10);
    push(12);
    pop();
    pop();
    pop();
    is_empty();
    pop();
    return 0;
}
