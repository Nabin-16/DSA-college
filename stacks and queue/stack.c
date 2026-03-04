#include<stdio.h>
#define max 5

struct Stack
{
    int TOS;
    int data[max];

};
struct  Stack s={-1};
int IsFull(struct Stack *s)
{
    if(s->TOS==max-1)
    {
        printf("Stack is Full\n");
        return 1;
    }
    return 0;
}
int IsEmpty(struct Stack *s)
{
    if(s->TOS==-1)
    {
        printf("Stack is Empty\n");
        return 1;
    }
    return 0;
}
void PUSH(struct Stack *s, int element)
{
    if(IsFull(s)==1)
    printf("Cannot push %d\n", element);
    else
    {
    s->TOS=s->TOS+1;
    s->data[s->TOS]=element;
    }
}
int POP(struct Stack *s)
{
    if(IsEmpty(s)==1)
    printf("Cannot pop\n");
    else
    {
        int element=s->data[s->TOS];
        s->TOS=s->TOS-1;
        return element;
    }
}

int main()
{
    int element,choice;
    while(1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter an element: ");
                scanf("%d",&element);
                PUSH(&s,element);
                break;
            case 2:
                element = POP(&s);
                printf("Popped element is %d\n", element);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}