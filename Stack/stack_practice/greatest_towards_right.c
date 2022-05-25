#include <stdio.h>
#include <stdlib.h>

struct GTR
{
    int *arr;
    int top;
    int size;
};

int isEmpty(struct GTR *ptr)
{
    if (ptr->top == -1)
    {
        printf("EMpty stack");
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct GTR *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
