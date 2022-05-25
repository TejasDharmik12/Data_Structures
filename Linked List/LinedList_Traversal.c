#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *Third;
    struct Node *Fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    Third = (struct Node *)malloc(sizeof(struct Node));
    Fourth= (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    second->data = 8;
    second->next = Third;
    Third->data = 20;
    Third->next = Fourth;
    Fourth->data = 23;
    Fourth->next = NULL;
linkedlistTraversal(head);
return 0;
}