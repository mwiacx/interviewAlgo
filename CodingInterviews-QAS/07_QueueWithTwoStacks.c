/*
 * \brief 用两个栈实现队列
 * \author mwiacx
 * \date 2018-8-3
 *
 * 关键点：
 * 1. 栈的基本操作
 * 2. 利用第二个栈完成对第一个栈的逆序
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSTACKLEN 100

typedef struct cQueue_t
{
    int stack1[MAXSTACKLEN];
    int top1;
    int stack2[MAXSTACKLEN];
    int top2;
} cQueue;

void CQueueAppendTail(cQueue *queue, int element)
{
    if (queue == NULL)
    {
        printf("Error in CQueueAppendTail: queue is NULL");
        return;
    }
    else if(queue->top1 == MAXSTACKLEN-1)
    {
        printf("Error in CQueueAppendTail: queue is full!\n");
        return;
    }

    queue->stack1[++queue->top1] = element;
}

int CQueueDeleteHead(cQueue *queue)
{
    if (queue == NULL)
    {
        printf("Error in CQueueDeleteHead: queue is NULL\n");
        return 0;
    }
    // 检查stack2是否为空，若不为空，返回栈顶
    if (queue->top2 != -1)
        /* TODO: 出栈是Index--，而不是--Index */
        return queue->stack2[queue->top2--];

    // 将stack1中元素压入stack2
    if (queue->top1 == -1){
        printf("Error in CQueueDeleteHead: queue is Empty!\n");
        return 0;
    }

    while(queue->top1 > -1)
    {
        int tmpElement = queue->stack1[queue->top1--];
        // stack2 一定为空, 并且不会满
        queue->stack2[++queue->top2] = tmpElement;
    }

    return queue->stack2[queue->top2--];
}

int main(void)
{
    // init
    cQueue myQueue;
    myQueue.top1 = -1;
    myQueue.top2 = -1;

    // Test
    CQueueAppendTail(&myQueue, 7);
    CQueueAppendTail(&myQueue, 5);
    CQueueAppendTail(&myQueue, 2);

    int res1 = CQueueDeleteHead(&myQueue);
    int res2 = CQueueDeleteHead(&myQueue);
    CQueueAppendTail(&myQueue, 4);
    int res3 = CQueueDeleteHead(&myQueue);
    int res4 = CQueueDeleteHead(&myQueue);

    printf("%d %d %d %d\n", res1, res2, res3, res4);

    /*
    TODO: 注意下面这句话的结果会是 2 5 7，原因是C语言调用栈压栈顺序为从右向左！
    printf("%d %d %d\n", CQueueDeleteHead(&myQueue), CQueueDeleteHead(&myQueue), CQueueDeleteHead(&myQueue));
    */

    return 0;
}
