#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int data;
    struct SLL *Prev;
    struct SLL *Next;
};
struct SLL *first, *last = NULL;
void insertAtBeg(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->Next = NULL;
    NewNode->Prev = NULL;
    NewNode->data = element;
    if(first == NULL) // List is Empty
        first = last = NewNode;
    else
    {
        first->Prev = NewNode;
        NewNode->Next = first;
        first = NewNode;
    }
    printf("%d WAS INSERTED AT THE BEGINNING\n", first->data);
}
void insertAtEnd(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->Next = NULL;
    NewNode->Prev = NULL;
    NewNode->data = element;
    if(first == NULL) // List is Empty
        first = last = NewNode;
    else
    {
        last->Next = NewNode;
        NewNode->Prev = last;
        last = NewNode;
    }
    printf("%d WAS INSERTED AT THE END\n", last->data);
}
void insertatPosition(int pos, int element)
{
    struct SLL *NewNode, *temp;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->Next = NULL;
    NewNode->Prev = NULL;
    NewNode->data = element;
    int i;
    if(first == NULL || pos <= 0)// List is Empty
       first = last = NewNode;
    else
    {
        temp = first;
        for(i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->Next;
        NewNode->Next = temp->Next;
        if(temp->Next != NULL)
            temp->Next->Prev = NewNode;
        temp->Next = NewNode;
        NewNode->Prev = temp;
        
    }
}
void deletionFromBeg()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else
    {
        temp = first;
        first = first->Next;
        if(first != NULL)
            first->Prev = NULL;
        else
            last = NULL; // List becomes empty
        printf("%d IS GOING TO BE DELETED\n", temp->data);
        free(temp);
    }
}
void deletionFromEnd()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else if(first->Next == NULL)
    {
        temp = first;
        printf("%d IS GOING TO BE DELETED\n", temp->data);
        first = last = NULL; // List becomes empty
        free(temp);
    }
    else
    {
        temp = last;
        last = last->Prev;
        last->Next = NULL;
        printf("%d IS GOING TO BE DELETED\n", temp->data);
        free(temp);
    }
}
void deletionFromPosition(int pos)
{
    struct SLL *temp, *tempp;
    int i;
    if(first == NULL || pos <= 0)
        printf("INVALID DELETION!\n");
    else if(first->Next == NULL || pos == 1)
    {
        deletionFromBeg();
    }
    else
    {
        temp = first;
        for(i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->Next;
        if(temp == NULL || temp->Next == NULL)
            printf("INVALID POSITION!\n");
        else
        {
            tempp = temp->Next;
            temp->Next = tempp->Next;
            if(tempp->Next != NULL)
                tempp->Next->Prev = temp;
            else
                last = temp; // If deleted node was the last node
            printf("%d IS GOING TO BE DELETED\n", tempp->data);
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
            printf("%d <-> ", temp->data);
            temp = temp->Next;
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
                printf("Element %d Found!\n", key);
                flag = 1;
                break; // Exit loop once found
            }
            temp = temp->Next;
        }
        if(flag == 0)
            printf("SEARCH UNSUCCESSFUL! Element %d not found.\n", key);
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
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}