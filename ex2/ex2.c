#include "stdio.h"

int arr_dat[3] = {0};
int rmod = 0;
void data_scan(int *arr)
{
    printf("请输入需要排序的3个数据，空格隔开：\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("递增排序输入1，递减输入0\n");
    scanf("%d",&rmod);
}
void arr_rank(int *arr, int mode) // mode = 1 递增，0 递减
{
    int temp = 0;
    switch (mode)
    {
    case 0:
    {

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3-i-1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            // printf("rank debug : arr[%d]=%d\n",i,arr[i]);
        }
        break;
    }
    case 1:
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3-i-1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            // printf("rank debug : arr[%d]=%d\n",i,arr[i]);
        }
        break;
    }
    }
}

int main()
{
    data_scan(arr_dat);
    arr_rank(arr_dat,rmod );
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr_dat[i]);
    }
    return 0;
}