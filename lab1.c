#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define max 5

struct Stack
{
    int TOS;
    float data[max];

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
void PUSH(struct Stack *s, float element)
{
    if(IsFull(s)==1)
    printf("Cannot push %d\n", element);
    else
    {
    s->TOS=s->TOS+1;
    s->data[s->TOS]=element;
    }
}
float POP(struct Stack *s)
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
    char postfix[50];
    float op1,op2;
    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    char* token = strtok(postfix, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {

            float value = atoi(token);
            PUSH(&s, value);
        } else
        {
            op1 = POP(&s);
            op2 = POP(&s); 
            switch (token[0]) {
                case '^':
                    PUSH(&s, pow(op2, op1));
                    break;
                case '+':
                    PUSH(&s, op2 + op1);
                    break;
                case '-':
                    PUSH(&s, op2 - op1);
                    break;
                case '*':
                    PUSH(&s, op2 * op1);
                    break;
                case '/':
                    if (op1 == 0) {
                        printf("Division by zero error\n");
                        return -1;
                    }
                    PUSH(&s, op2 / op1);
                    break;
            }
        }
        token = strtok(NULL, " ");
   
    }
printf("The result is %f", s.data[s.TOS]);
return 0;
}

