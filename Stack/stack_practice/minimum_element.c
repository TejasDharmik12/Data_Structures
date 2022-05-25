#include <stdio.h>
#include <stdlib.h>

struct s1
{
    int *arr1;
    int top1;
    int size1;
};
struct s2
{
    int *arr2;
    int top2;
    int size2;
};
int isfull(struct s1 *ptr1, struct s2 *ptr2)
{
    if (ptr1->top1 == ptr1->size1 - 1 || ptr2->top2 == ptr2->size2 - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct s1 *ptr1, struct s2 *ptr2)
{
    if (ptr1->top1 == -1 || ptr2->top2 == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct s1 *ptr1, struct s2 *ptr2, int val)
{
    if (isfull(ptr1, ptr2))
    {
        printf("Stack overflow! Cannot push %d in stack", val);
    }
    else
    {
        ptr1->top1++;
        ptr1->arr1[ptr1->top1] = val;
        if (val < ptr2->arr2[ptr2->top2])
        {
            ptr2->top2++;
            ptr2->arr2[ptr2->top2] = val;
        }
    }
}

int pop(struct s1 *ptr1, struct s2 *ptr2)
{
    if (isEmpty(ptr1, ptr2))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        if (ptr1->arr1[ptr1->top1] == ptr2->arr2[ptr2->top2])
        {
            int val1 = ptr1->arr1[ptr1->top1];
            ptr1->top1--;

            int val2 = ptr2->arr2[ptr2->top2];
            ptr2->top2--;
            return val1, val2;
        }
        else
        {
            int val = ptr1->arr1[ptr1->top1];
            ptr1->top1--;
            return val;
        }
    }
}

int getmin(struct s1 *ptr1, struct s2 *ptr2)
{
    if (isEmpty(ptr1, ptr2))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }

    int min = ptr2->arr2[ptr2->top2];
    printf("\nMinimum element from the stack is %d", min);
}

int main()
{
    struct s1 *sp1 = (struct s1 *)malloc(sizeof(struct s1));
    struct s2 *sp2 = (struct s2 *)malloc(sizeof(struct s2));
    sp1->size1 = 10;
    sp1->top1 = -1;
    sp1->arr1 = (int *)malloc(sp1->size1 * sizeof(int));
    sp2->size2 = 10;
    sp2->top2 = -1;
    sp2->arr2 = (int *)malloc(sp2->size2 * sizeof(int));
    printf("Stack has been created successfully");
    push(sp1, sp2, 18);
    push(sp1, sp2, 14);
    push(sp1, sp2, 29);
    push(sp1, sp2, 15);
    pop(sp1, sp2);

    getmin(sp1, sp2);
}