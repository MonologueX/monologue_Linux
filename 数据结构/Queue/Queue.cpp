#include "Queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void QueueInit(Queue *q)
{
    q->_front = q->_rear = NULL;
}

void QueueDestroy(Queue *q)
{
    QNode *cur;
    QNode *next = NULL;
    for (cur = q->_front; cur != NULL; cur = next)
    {
        next = cur->_next;
        free(cur);
    }
    q->_front = q->_rear = NULL;
}

static QNode *CreateNode(QDataType data)
{
    QNode *node = (QNode *)malloc(sizeof(QNode));
    assert(node);
    node->_data = data;
    node->_next = NULL;
    return node;
}

void QueuePush(Queue *q, QDataType data)
{
    QNode *newNode = CreateNode(data);
    if (NULL == q->_front)
    {
        q->_front = q->_rear = newNode;
        return;
    }
    q->_rear->_next = newNode;
    q->_rear = newNode;
}

void QueuePop(Queue *q)
{
    assert(q != NULL);
    if (NULL == q->_front)
    {
        printf("队列为空!!!\n");
        return;
    }

    QNode *del = q->_front;
    q->_front = q->_front->_next;
    free(del);
    if (NULL == q->_front)
    {
        q->_rear = NULL;
    }
}

QDataType QueueFront(Queue *q)
{
    assert(q != NULL);
    if (NULL == q->_front)
    {
        printf("队列为空!!!\n");
        return -1;
    }
    return q->_front->_data;
}

int QueueEmpty(const Queue *q)
{
    return q->_front == NULL;
}

int QueueSize(const Queue *q)
{
    QNode *cur;
    int size = 0;
    for (cur = q->_front; cur != NULL; cur = cur->_next)
    {
        size++;
    }
    return size;
}
