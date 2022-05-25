#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};
int isEmpty(struct stack*ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack*ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack * ptr , int val){
    if (isfull(ptr))
    {
        printf("Stack overflow! Cannot push %d in stack",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack * ptr){
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr-> arr[ptr->top];
        ptr->top--;
        return val;

    }
}

int peek(struct stack *sp,int i){
int arrayInd = sp->top - i +1;
if(arrayInd<0){
    printf("Not a valid position");
    return -1;
}
else{
    return sp->arr[arrayInd];
}
}




int main()
{
    struct stack * sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top= -1;
    sp->arr = (int*)malloc(sp->size*sizeof(int));
    printf("Stack has been created successfully");
    
    printf("%d\n",isfull(sp));
    printf("%d\n",isEmpty(sp));
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,567);
    push(sp,556);
    push(sp,5);
    push(sp,6);
    printf("After pushing ,Full :%d\n",isfull(sp));
    printf("After pushing ,Empty :%d\n",isEmpty(sp));
    
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    return 0;
}
