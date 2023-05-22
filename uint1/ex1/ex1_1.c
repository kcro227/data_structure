#include "stdio.h"
/**
 * 定义小数存储的结构体
 * 
 */
typedef struct
{
    int arr_len;
    float arr[];
} flaot_num;

flaot_num arr;

/**
 * @brief 数据扫描函数，用于获取用户的输入数据
 * 
 * @param array 为float_num类型的结构体指针
 */
void dat_scan(flaot_num *array)
{
    char flag;
    printf("请输入一串小数，并用空格分开,以回车结束：\n");
    /**
     * @brief 当用户输入的字符类型为回车时，跳出while循环，并且结束数据个数累加
     * 
     */
    while (flag != '\n')
    {
        scanf("%f%c", &(array->arr[(array->arr_len)]), &flag);
        (array->arr_len)++;
    }
     
}
/**
 * @brief 小数的加法运算，从flaot_num类型的结构体中获取数据。
 * 
 * @param flaot_num_t
 * @return float 类型的求和结果
 */
float add_arr(flaot_num *flaot_num_t)
{
    float num = 0;
    int i = 0;
    int len = flaot_num_t->arr_len;
    while (i < len)
    {
        num += (flaot_num_t->arr[i]);
        i++;
    }
    return num;
}

/**
 * @brief 简单的连续扫描函数
 * 
 * @param arr 
 */
void continue_scan(flaot_num *arr)
{
    int flag = 0, exflag = 0;
    char exit;
    while (!exflag)
    {
        switch (flag)
        {
        case 0:
        {
            dat_scan(arr);
            flag = 1;
            printf("结果为: %.2f\n", add_arr(arr));
            break;
        }
        case 1:
        {
            printf("是否继续计算？(Y/N)");
            scanf("%c", &exit);
            if (exit == 'Y')
                flag = 0;
            else
                exflag = 1;
            break;
        }
        }
    }
}
int main()
{
    continue_scan(&arr);  
    return 0;
}