#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
int isFull(struct Queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *q,int val){
    if(isFull(q)){
        printf("This Queue is Full");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
    }
    
}

int dequeue(struct Queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is Empty");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
    
}

void display(struct Queue *q)
{
    int i;
    if(isEmpty(q)){
        printf("Queue is empty");
    }
    else{
        for(i=q->f+1;i<=q->r;i++)
        {
            printf("Display elements of queue",q->arr[i]);
        }
    }
}
int main()
{
    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    // Enqueue
    enqueue(&q,12);
    enqueue(&q,15);
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    display(&q);
    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full");
    }
    return 0;
}