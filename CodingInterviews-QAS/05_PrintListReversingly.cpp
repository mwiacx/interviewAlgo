/*
 * \brief 从尾到头打印链表
 * \author mwiacx
 * \date 2018-7-27
 */

/*
 * 关键点：
 * 1. 是否能够改变链表结构，一般来讲，打印是一个只读操作，倾向于不能修改链表本身
 * 2. 注意链表的基本操作
 */
#include <stdio.h>
#include <stack>

// 链表定义
typedef struct ListNode_T{
    int val;
    struct ListNode_T *next;
}ListNode;

/*
 * Stack
 */
void PrintListReversingly_Iteratively(ListNode *pHead)
{
    std::stack<int> nodes;
    int vals;

    if(pHead == NULL)
        return;

    ListNode *pNode = pHead;
    while(pNode != NULL)
    {
        // 遍历数组，并将值压栈
        nodes.push(pNode->val);
        pNode = pNode->next;
    }
    // 打印
    while(!nodes.empty())
    {
        vals = nodes.top();
        printf("%d\t", vals);
        nodes.pop();
    }
    /* TODO */
    printf("\n");

    return;
}

/*
 * Recursive: 缺点是如果链表特长，容易调用栈爆炸
 */
void PrintListReversingly_Recursively(ListNode *pHead)
{
    // 终止条件
    if(pHead == NULL)
        return;

    // 先打印后续链表
    PrintListReversingly_Recursively(pHead->next);
    // 打印自身
    printf("%d\t", pHead->val);

    return;

}

ListNode *CreateLinkList(int nums[], int length)
{
    ListNode *head, *p, *r = NULL;

    for(int i = 0; i < length; i++)
    {
        p = new ListNode();
        p->val = nums[i];
        p->next = NULL;

        if (head == NULL)
            head = p;
        else
            r->next = p;

        r = p;
    }
    return head;
}

// 测试
int main(void)
{
    int nums[10] = {3, 5, 7, 10, 3, 9};
    int length = 6;

    ListNode *pHead = CreateLinkList(nums, length);
    if (pHead == NULL)
    {
        printf("Create Link List Failed!\n");
        return -1;
    }

    // Test stack method
    PrintListReversingly_Iteratively(pHead);
    // Test Recursive method
    PrintListReversingly_Recursively(pHead);
    /* TODO */
    printf("\n");
    /* TODO: FREE */
    return 0;
}
