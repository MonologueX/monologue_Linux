#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct ListNode
{
    DataType _data;
    struct ListNode *_next;
}ListNode;

// 初始化
void ListNodeInit(ListNode **ppFirst)
{
    assert(ppFirst != NULL);
    *ppFirst = NULL;
}

// 销毁
void ListNodeDestory(ListNode **ppFirst)
{
    *ppFirst = NULL;
}

// 头部插入
void ListNodePushFront(ListNode **ppFirst, DataType data)
{
    assert(ppFirst != NULL);
    // 申请空间
    ListNode *NewNode = (ListNode *) malloc(sizeof(ListNode));
    NewNode->_data = data;
    NewNode->_next = *ppFirst;
    *ppFirst = NewNode;
}

// 尾部插入
void ListNodePushBack(ListNode **ppFirst, DataType data)
{
    assert(ppFirst != NULL);
    ListNode *NewNode = (ListNode *)malloc(sizeof(ListNode));
    assert(NewNode);
    NewNode->_data = data;
    NewNode->_next = NULL;
    if (*ppFirst == NULL)
    {
        *ppFirst = NewNode;
        return;
    }

    ListNode *cur = *ppFirst;
    while (cur->_next != NULL)
    {
        cur = cur->_next;
    }
    cur->_next = NewNode;
}

// 中间插入
void ListNodeInsert(ListNode **ppFirst, size_t pos, DataType data)
{
    if (1 == pos)
    {
        ListNodePushFront(&(*ppFirst), data);
        return;
    }
    ListNode *cur = *ppFirst;
    while (pos > 2)
    {
        cur = cur->_next;
        pos--;
    }
    ListNode *NewNode = (ListNode *)malloc(sizeof(ListNode));
    assert(NewNode);
    NewNode->_data = data;
    NewNode->_next = cur->_next;
    cur->_next = NewNode;
}

// 头部删除
void ListNodePopFront(ListNode **ppFirst)
{
    assert(ppFirst != NULL);
    assert(*ppFirst != NULL);

    ListNode *del = *ppFirst;
    *ppFirst = del->_next;
    free(del);
    del = NULL;
}

// 尾部删除
void ListNodePopBack(ListNode **ppFirst)
{
    assert(ppFirst != NULL);
    assert(*ppFirst != NULL);

    if ((*ppFirst)->_next == NULL)
    {
        free(*ppFirst);
        *ppFirst = NULL;
        return;
    }

    ListNode *cur = *ppFirst;
    while (cur->_next->_next != NULL)
    {
        cur = cur->_next;
    }
    ListNode *del = cur->_next;
    cur->_next = NULL;
    free(del);
    del = NULL;
}

// 中间删除
void ListNodePop(ListNode **ppFirst, size_t pos)
{
    assert(ppFirst != NULL);
    assert(*ppFirst != NULL);

    if (1 == pos)
    {
        ListNodePopFront(&(*ppFirst));
        return;
    }
    ListNode *cur = *ppFirst;
    while (pos > 2)
    {
        cur = cur->_next;
        pos--;
    }
    ListNode *del = cur->_next;
    cur->_next = del->_next;
    free(del);
    del = NULL;
}

// 查找
ListNode *Find(ListNode *first, DataType data)
{
    for (ListNode *cur = first; cur != NULL; cur = cur->_next)
    {
        if (data == cur->_data)
        {
            return cur;
        }
    }
    return NULL;
}
/////////////////////////////// 
// 测试
void Print(ListNode *pFirst)
{
    if (pFirst == NULL)
    {
        return;
    }
    else 
    {
        while(pFirst)
        {
            printf("%d->", pFirst->_data);
            pFirst = pFirst->_next;
        }
        printf("NULL\n");
    }
}

void Test()
{
    ListNode *first;
    ListNodeInit(&first);

    ListNodePushBack(&first, 1);
    ListNodePushBack(&first, 2);
    ListNodePushBack(&first, 3);
    ListNodePushBack(&first, 5);
    ListNodePushBack(&first, 6);
    Print(first);
    ListNodeInsert(&first, 4, 4);
    Print(first);
    ListNode *cur = Find(first, 4);
    printf("%d\n", cur->_data);
}

int main()
{
    Test();
    return 0;
}
