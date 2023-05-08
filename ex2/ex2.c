#include "stdio.h"

int arr_dat[3] = {0};
int rmod = 0;
/**
 * @brief 数据扫描
 * 
 * @param arr 
 */
void data_scan(int *arr)
{
    printf("请输入需要排序的3个数据，空格隔开：\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);
    }
}
/**
 * @brief 使用冒泡法对数据进行排序
 * 
 * @param arr 数组名
 */
void arr_rank(int *arr)
{
    int temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    data_scan(arr_dat); // 数据扫描
    arr_rank(arr_dat); // 排序
    // 输出
    printf("数据由大到小排序：\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr_dat[i]);
    }
    return 0;
}