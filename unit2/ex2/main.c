#include "stdio.h"
#include "stdlib.h"
typedef struct Node
{
    int data;
    struct Node *Next;
} Node;
Node *head = NULL;
Node *prev = NULL;
int LinkListInit(Node *L)
{
    L = (Node *)malloc(sizeof(Node));
    L ->Next = prev;
}
int LinkListInsert(Node *L, int data)
{
    Node *current;
    
    current = (Node *)malloc(sizeof(Node));
    if (L == NULL)
    {
        L = (Node *)malloc(sizeof(Node));
        L->Next = current;
        printf("1\n");
    }
    else
    {
        current->data = data;
        prev = current;
        printf("2\n");
    }
    current->Next = NULL;
    prev = current;
}
int main()
{

    // int tempdata, i = 0;
    int tempdata;
    char flag;
    printf("please input data:\n");
    while (flag != '\n')
    {
        scanf("%d%c", &tempdata, &flag);
        LinkListInsert(head, tempdata);
        // i++;
    }
    Node *current = head;

    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->Next;
    }
    return 0;
}