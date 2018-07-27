/*
 * Code For CI_04
 * author: mwiacx
 * date: 2018-7-27
 * 关键点：修改后的字符串长度已知。
 */
#include <stdio.h>

int ReplaceBlank(char string[], int sSize)
{
    int i = 0, len = 0, blankCount = 0;
    /* TODO */
    if (string == NULL || sSize < 0)
        return -1;
    //遍历字符串，求解字符串长度
    while(i < sSize && string[i] != '\0')
    {
        if (string[i] == ' ')
            blankCount++;
        i++;
    }
    if(i == sSize)
        return -1;
    else
        len = i;
    //从后往前遍历字符串，利用p1,p2插入Blank
    int p1 = len;
    int p2 = len + 2 * blankCount;
    /* TODO */
    if (p2 > sSize)
        return -1;
    while(p1 != p2 && p1 >= 0 && p2 >= 0)
    {
        if (string[p1] != ' ')
        {
            // 复制p1->val 到 p2->val
            string[p2] = string[p1];
            p1--;
            p2--;
        }
        else
        {
            // 填充"%20"
            string[p2--] = '0';
            string[p2--] = '2';
            string[p2--] = '%';
            p1--;
        }
    }

    return 0;
}

void testString(char str[], int sSize)
{
    if(ReplaceBlank(str, sSize) == -1)
    {
        printf("Error in ReplaceBlank.\n");
        return;
    }
    // output
    printf("%s\n", str);

    return;
}

int main(void)
{
    int sSize = 50;
    char str1[50] = "";
    char str2[50] = "we are   happy.";
    char str3[50] = " we fly ";
    char str4[50] = " ";
    char str5[50] = "    ";

    testString(str1, sSize);
    testString(str2, sSize);
    testString(str3, sSize);
    testString(str4, sSize);
    testString(str5, sSize);
    testString(NULL, sSize);

    return 0;
}
