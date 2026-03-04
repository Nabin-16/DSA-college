#include <stdio.h>
#define max 5
struct Queue
{
    int front;
    int rear;
    int data[max];

};
struct Queue q={0,-1};
int enqueue(struct Queue *q, int element)
{
    if(q->rear==max-1)
    printf("Queue is Full");
    else
    {
        q->rear=q->rear+1;
        q->data[q->rear]=element;
    printf("Enqueued: %d\n", element);
    }
}
int dnqueue(struct Queue *q)
{
    if(q->front>q->rear)
    {
    printf("Queue is empty");
    return -1;
    }
    else
    {
        int element=q->data[q->front];
        q->front=q->front+1;
        return element;
    }
}

int main()
{
    int element,choice;
    while(1)
    {

    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        printf("Enter an element");
        scanf("%d",&element);
        enqueue(&q,element);
        break;
        case 2:
        element = dnqueue(&q);
        if (element != -1)
        printf("Dequeued element is %d\n", element);
        break;
        case 3:
        return 0;

    }
}
}
