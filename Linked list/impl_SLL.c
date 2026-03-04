#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
};
struct SLL *first, *last = NULL;
void insertAtBeg(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;
    if(first == NULL)// List is Empty
        first = last = NewNode;
    else
    {
        NewNode->next = first;
        first = NewNode;
    }
    printf("%d WAS INSERTED AT THE BEGINNING\n",first->data);
}
void insertAtEnd(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;
    if(first == NULL)// List is Empty
        first = last = NewNode;
    else
    {
        last->next = NewNode;
        last = NewNode;
    }
    printf("%d WAS INSERTED AT THE END\n",last->data);
}
void insertatPosition(int pos, int element)
{
    struct SLL *NewNode, *temp;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;
    int i;
    if(first == NULL || pos<=0)
         first = last = NewNode;
    else
    {
        temp = first;
        for(i=1;i<pos-1;i++)
            temp = temp->next;
        NewNode->next = temp->next;
        temp->next = NewNode;

        
    }

}

void deletionFromBeg()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else if(first->next == NULL)
    {
        temp = first;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        free(temp);
    }
}

void deletionFromEnd()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else if(first->next == NULL)
    {
        temp = first;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        free(temp);
        last->next = NULL;
    }
}
void deletionFromPosition(int pos)
{
    struct SLL *temp, *tempp;
    int i;
    if(first == NULL || pos<=0)
        printf("INVALID DELETION!\n");
    else if(first->next ==  NULL || pos == 1)
    {
        deletionFromBeg();
    }
    else
    {
        temp = first;
        for(i=1;i<pos-1;i++)
            temp = temp->next;
        if(temp->next == last)
            deletionFromEnd();
        else
        {
            tempp = temp->next;
            temp->next = tempp->next;
            printf("%d IS GOING TO BE DELETED\n",tempp->data);
            free(tempp);
        }
    }

}

void display()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else
    {
        temp = first;
        while(temp != NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void search(int key)
{
    struct SLL *temp;
    int flag = 0;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else
    {
        temp = first;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                printf("Element Found!\n");
                flag = 1;
            }
            temp = temp->next;
        }
        if(flag == 0)
            printf("SEARCH UNSUCCESSFUL!\n");
    }
}
int main()
{
    int choice, element, pos;
    while(1)
    {
        printf("1.INSERT AT BEGINNING\n");
        printf("2.INSERT AT END\n");
        printf("3.INSERT AT POSITION\n");
        printf("4.DELETION FROM BEGINNING\n");
        printf("5.DELETION FROM END\n");
        printf("6.DELETION FROM POSITION\n");
        printf("7.DISPLAY\n");
        printf("8.SEARCH\n");
        printf("9.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &element);
                insertAtBeg(element);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &element);
                insertAtEnd(element);
                break;
            case 3:
                printf("Enter position and element to insert: ");
                scanf("%d %d", &pos, &element);
                insertatPosition(pos, element);
                break;
            case 4:
                deletionFromBeg();
                break;
            case 5:
                deletionFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletionFromPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &element);
                search(element);
                break;
            case 9:
                exit(0);
        }
    }
    return 0;
}