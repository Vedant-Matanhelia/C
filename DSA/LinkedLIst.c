#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Display(Node *head)
{
    int i = 0;
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element%d: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

Node *InsertHead(Node *head, int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = value;
    ptr->next = head;
    return ptr;
}

Node *InsertAtIndex(Node *head, int index, int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *pt = head;
    int i = 0;
    while (i != index - 1)
    {
        pt = pt->next;
        i++;
    }
    ptr->data = value;
    ptr->next = pt->next;
    pt->next = ptr;
    return ptr;
}

Node *InsertAfterNode(Node *prevNode, int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = value;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return ptr;
}

Node *InsertTail(Node *head, int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = value;
    ptr->next = NULL;
    p->next = ptr;
    return ptr;
}

Node *DeleteHead(Node *head)
{
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node *DeleteTail(Node *head)
{
    Node *p = head;
    Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

Node *DeleteAtIndex(Node *head, int index)
{
    Node *p = head;
    Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

Node *DeleteValue(Node *head, int value)
{
    Node *p = head;
    Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data = value)
    {
        p->next = q->next;
        free(q);
        return head;
    }
    return head;
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *second = (Node *)malloc(sizeof(Node));
    Node *third = (Node *)malloc(sizeof(Node));
    Node *fourth = (Node *)malloc(sizeof(Node));
    Node *fifth = (Node *)malloc(sizeof(Node));
    Node *tail = (Node *)malloc(sizeof(Node));

    // Set the head;
    head->data = 10;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 13;
    third->next = tail;

    tail->data = 15;
    tail->next = NULL;

    Display(head);

    head = InsertHead(head, 9);
    fourth = InsertAtIndex(head, 4, 14);
    fifth = InsertAfterNode(fourth, 145);
    tail = InsertTail(head, 16);
    Display(head);
    return 0;
}
