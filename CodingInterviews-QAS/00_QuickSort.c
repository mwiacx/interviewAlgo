/*
 * \brief Quick Sort
 * \author mwaicx
 * \date 2018-8-5
 */

/*
 * 划分的两种方法：
 * 1. 用一个指针遍历，另外一个指令维护分界
 * 2. 用两个指针遍历，----><------
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

static int Partition(int data[], int length, int start, int end)
{
    /*
    // Not Used
    if (data == NULL || length <= 0 || start < 0 || end >= length || start > end)
    {
        printf("Error in Partition: Invalid Parameters!\n");
        return 0;
    }
    */

    int small = start - 1;
    int tmp = 0;
    for (int i = start; i < end; i++)
    {
        // 遍历数组，将其与data[end]比较
        if (data[i] < data[end])
        {
            // 比data[end]小，将其small分界之前
            small++;
            if (small != i)
            {
                tmp = data[small];
                data[small] = data[i];
                data[i] = tmp;
            }
        }
    }
    // 将data[end]移到中间位置(small+1)
    small++;
    tmp = data[small];
    data[small] = data[end];
    data[end] = tmp;

    // 返回中间元素位置
    return small;
}

void QuickSort(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length || start > end)
    {
        printf("Error in QuickSort: Invalid Parameters(0x%08x, %d, %d, %d)\n", data, length, start, end);
        return;
    }
    if (start == end)
        return;

    // 递归
    int midIndex = Partition(data, length, start, end);
    // left
    /* TODO: 注意条件：midIndex > start
     * s * * * e
     * |
     * m
     */
    if (midIndex > start)
        QuickSort(data, length, start, midIndex-1);
    // right
    /* TODO: 同上 */
    if (midIndex < end)
        QuickSort(data, length, midIndex+1, end);
}

// Test Main
int
main(void)
{
    int data[MAXLEN] = {7, 10, 79, -1, 9, 0, 28};
    int length = 7;

    QuickSort(data, length, 0, length-1);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
