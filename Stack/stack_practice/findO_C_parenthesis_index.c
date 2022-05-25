#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int test(struct stack *ptr, char expression[], int index, int size)
{
    int i;

    if (expression[i] != '[')
    {
        printf("%s , %d : -1", expression, index);
    }
    for (i = index; i < size; i++)
    {
        if (expression[i] == '[')
        {
            ptr->top++;
            ptr->arr[ptr->top] = expression[i];
        }
        else if (expression[i] == ']')
        {
            int val = ptr->arr[ptr->top];
            ptr->top--;
            if (isEmpty(ptr))
            {
                printf("Stack Underflow! Cannot pop from the stack\n");
                return -1;
            }
        }
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("Stack has been created successfully");
    char str[5];
    int size = 5, index;
    printf("ENter size of the Expression");
    scanf("%d", &size);
    // printf("ENter the Expression");
    // scanf("%[^n]c", &str);
    printf("ENter index of the Expression");
    scanf("%d", &index);
    test(sp, '[ABC]', index, size);

    // push(sp,55);
    // push(sp,54);
    // push(sp,50);
    // push(sp,15);
    return 0;
}
