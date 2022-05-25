#include <stdio.h>
int stack[100], choice, n, top, x, i;
void push(void);
void pop(void);
void display(void);
int main()
{
    top = -1;
    printf("\n                     IMPLEMENTATION OF STACK    \n");
    printf("\nEnter the size of the stack : ");
    scanf("%d", &n);
    printf("\nChoose any option\n");
 printf("1.Insertion or Push in stack\n2.Deletion or pop from stack\n3.Display the stack\n4.Exit");
 do
 {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("\nEXIT");
            break;
        }
        default:
        {
            printf("\nEnter a Valid Choice(1/2/3/4)");
        }
        }
 }
 while(choice!=4);
 return 0;
}
void push()
{
    if (top >= n - 1)
    {
        printf("\n\tSTACK is over flow");
    }
    else
    {
        printf(" Enter a value to be pushed or insert:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top <= -1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\nThe popped elements is %d", stack[top]);
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        printf("\n The elements in STACK");
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
       // printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
