#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int size;
    int *arr;
} Stack;

int isEmpty(Stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int isFull(Stack *st)
{
    if (st->top == st->size)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void push(Stack *st, int data)
{
    if (isFull(st) == 1)
    {
        printf("Cannot push. Stack Overflow\n");
        return;
    }
    st->top++;
    st->arr[st->top] = data;
}

void pop(Stack *st)
{
    if (isEmpty(st) == 1)
    {
        printf("Cannot pop. Stack Underflow\n");
        return;
    }
    st->arr[st->top] = 0;
    st->top--;
}

int peek(Stack *st, int index)
{
    int i = st->top - index + 1;

    if (i < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }

    return st->arr[i];
}

int stackTop(Stack *st)
{
    return st->arr[st->top];
}

int stackBottom(Stack *st)
{
    return st->arr[0];
}

int main()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    int i;
    st->top = -1;
    st->size = 10;
    st->arr = (int *)malloc(st->size * sizeof(int));
    i = isEmpty(st);
    if (i == 1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }
    return 0;
}