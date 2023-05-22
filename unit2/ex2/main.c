#include "stdio.h"
#include "stdlib.h"
typedef struct Node
{
    int data;
    struct Node *Next;
} Node;
Node *head = NULL;
Node *prev = NULL;
/**
 * @brief 从链表尾部插入数据
 *
 * @param data 数据
 * @return 执行状态
 */
int LinkListInsert(int data)
{
    /*创建新节点*/
    Node *current;
    current = (Node *)malloc(sizeof(Node));
    current->data = data;
    current->Next = NULL;

    if (head == NULL)
    {
        head = current;
    }
    else
    {
        prev->Next = current;
    }
    prev = current;
    // printf("creat list\n");
    return 0;
}

/**
 * @brief 获取链表最大数据
 * @param listpos 用于保存最大数据节点位置
 * @return 执行状态
 */
int GetListDataMax(int *listpos)
{
    int num = 0;
    int max = 0;
    int pos = 0;
    Node *nowlist;
    Node *nowmax;
    nowlist = head;
    while (nowlist != NULL)
    {
        num = nowlist->data;

        if (num > max)
        {
            max = num;
            *listpos = pos;
        }

        nowlist = nowlist->Next;
        pos++;
    }
    return 0;
}
/**
 * @brief 删除指定位置的节点
 * 
 * @param pos 位置
 * @return 运行状态
 */
int DelListDataMax(int pos)
{
    Node *p, *r;
    int i = 0;
    p = head;
    while (p->Next != NULL && i < pos-1)
    {
        p = p->Next;
        i++;
    }
    if (i != pos-1)
        return 1;
    r = p->Next;
    p->Next = p->Next->Next;
    free(r);
    return 0;
}
int main()
{

    int tempdata;
    char flag;
    printf("please input data:\n");
    while (flag != '\n')
    {
        scanf("%d%c", &tempdata, &flag);
        LinkListInsert(tempdata);
    }
    Node *current = head;

    while (current != NULL)
    {
        printf("before data=%d\n", current->data);
        current = current->Next;
    }

    int maxlist;
    GetListDataMax(&maxlist);
    int code = DelListDataMax(maxlist);
    current = head;
    while (current != NULL)
    {
        printf("now data=%d\n", current->data);
        current = current->Next;
    }
    return code;
}