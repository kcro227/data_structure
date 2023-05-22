#include "stdio.h"
#include "stdlib.h"
#define MAX_SIZE 20

typedef struct SeqList
{
    int *data;
    int listsize;
    int length;
} SeqList;

int IniList(SeqList *List)
{
    List->data = (int *)malloc(MAX_SIZE * sizeof(int));
    List->length = 0;
    List->listsize = MAX_SIZE;
    return 0;
}

int ListInsert(SeqList *List, int i, int e)
{
    int j;
    if (i < 1 || i > List->length + 1)
        return 1;
    if (List->length == List->listsize)
        return 2;
    for (j = List->length - 1; j >= i - 1; j--)

        List->data[j + 1] = List->data[j];

    List->data[i - 1] = e;
    List->length++;
    return 0;
}

int DataTran(SeqList *List)
{
    int i, j, temp;
    for (i = 0, j = List->length-1; i<(List->length / 2), j>(List->length / 2)-1; i++, j--)
    {

        temp = List->data[i];
        List->data[i] = List->data[j];
        List->data[j] = temp;
    }
    return 0;
}

void DataPrint(SeqList *List)
{
    for (int i = 0; i < List->length; i++)
    {
        printf("Data%i = %d \n", i, List->data[i]);
    }
}
int main()
{
    char flag;
    int code;
    int tempdata, i = 1;
    SeqList DataList;
    IniList(&DataList);
    printf("please input data:\n");
    while (flag != '\n')
    {
        scanf("%d%c", &tempdata, &flag);
        ListInsert(&DataList, i, tempdata);
        i++;
    }
    printf("befor:\n");
    DataPrint(&DataList);
    DataTran(&DataList);
    printf("after:\n");
    DataPrint(&DataList);
    return 0;
}