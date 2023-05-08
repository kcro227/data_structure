#include "stdio.h"

typedef struct
{
    int arr_len;
    float arr[];
} flaot_num;

flaot_num arr;

void dat_scan(flaot_num *array)
{
    int i = 0;
    char flag;
    printf("请输入一串小数，并用空格分开,以回车结束：\n");
    while (flag != '\n')
    {
        scanf("%f%c", &(array->arr[i]), &flag);
        // printf("i = %d flag = %c arr%d = %.2f\n", i, flag, i, array->arr[i]);
        i++;
    }
    array->arr_len = i;
    // printf("i = %d\n", i);
}

float add_arr(flaot_num *a)
{
    float num = 0;
    int i = 0;
    int len = a->arr_len;
    printf("add_arr debug:\n");

    while (i < len)
    {
        num += (a->arr[i]);
        printf("a%d = %.2f,len = %d\n", i, (a->arr[i]), len);
        i++;
    }

    return num;
}
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
            // printf("exit = %c",exit);
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
    // printf("main debug:\n");
    
    return 0;
}