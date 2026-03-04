#include <stdio.h>
#define MAX 5
struct circularQueue {
    int front;
    int rear;
    int data[MAX];
};
struct circularQueue cq = {-1, -1};

void enqueue(struct circularQueue *cq, int element) {
    if ((cq->rear + 1) % MAX == cq->front) {
        printf("Queue is Full\n");
    }
    if (cq->front == -1)//if empty
        cq->front = cq->rear = 0;
    else 
        cq->rear = (cq->rear + 1) % MAX;
    cq->data[cq->rear] = element;
}

int dequeue(struct circularQueue *cq) {
    if (cq->front == -1) {
        printf("Queue is Empty\n");
        return -1;
    }
    int element = cq->data[cq->front];
    if (cq->front == cq->rear) { //if only one is present
        cq->front = cq->rear = -1;
    } else 
    {
        cq->front = (cq->front + 1) % MAX;
    }
    return element;
}

int main() {
    int element, choice;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter an element: ");
                scanf("%d", &element);
                enqueue(&cq, element);
                break;
            case 2:
                element = dequeue(&cq);
                if (element != -1)
                printf("Dequeued element is %d\n", element);
                break;
            case 3:
                return 0;
        }
    }
}