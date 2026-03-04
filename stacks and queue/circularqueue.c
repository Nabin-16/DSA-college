#include <stdio.h>
#define MAX 5

struct circularQueue {
    int front;
    int rear;
    int size;
    int data[MAX];
};
struct circularQueue cq = {0, -1, 0};
void enqueue(struct circularQueue *cq, int element) {
    if (cq->size == MAX) {
        printf("Queue is Full\n");
    }
    else{
        cq->rear = (cq->rear + 1) % MAX;
        cq->data[cq->rear] = element;
        cq->size++;
    }
}

int dequeue(struct circularQueue *cq) {
    if (cq->size == 0) {
        printf("Queue is Empty\n");
    }
    else{
    int element = cq->data[cq->front];
    cq->front = (cq->front + 1) % MAX;
    cq->size--;
    return element;
    }
}

int main() {
    int element, choice;

    while (1) {
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Exit\n");
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
        }
    }
}