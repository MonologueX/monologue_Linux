#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct ListNode
{
    DataType _data;
    struct ListNode *_next;
}ListNode;

void ListNodeInit(ListNode **ppFirst)
{
    assert(ppFirst != NULL);
    *ppFirst = NULL;
}

void ListNodeDestory(ListNode **ppFirst)
{
    *ppFirst = NULL;
}

/*
 * 函数功能:插入
*/
void ListNodePushFront(ListNode **ppFirst, DataType data)
{
    assert(ppFirst != NULL);
    // 申请空间
    ListNode *NewNode = (ListNode *) malloc(sizeof(ListNode));
    NewNode->_data = data;
    NewNode->_next = *ppFirst;
    *ppFirst = NewNode;
}

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

void ListNodePopFront(ListNode **ppFirst)
{
    assert(ppFirst != NULL);
    assert(*ppFirst != NULL);

    ListNode *del = *ppFirst;
    *ppFirst = del->_next;
    free(del);
    del = NULL;
}

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

void TestPopFront()
{
    ListNode *first;
    ListNodeInit(&first);

    ListNodePushFront(&first, 1);
    ListNodePushFront(&first, 2);
    ListNodePushFront(&first, 3);
    ListNodePushFront(&first, 4);
    ListNodePushFront(&first, 5);
    ListNodePushFront(&first, 6);
    Print(first);

    ListNodePopFront(&first);
    Print(first);
    ListNodePopFront(&first);
    Print(first);
}

void TestPushFront()
{
    ListNode *first;
    ListNodeInit(&first);

    ListNodePushFront(&first, 1);
    ListNodePushFront(&first, 2);
    ListNodePushFront(&first, 3);
    ListNodePushFront(&first, 4);
    ListNodePushFront(&first, 5);
    ListNodePushFront(&first, 6);
    Print(first);
}

void TestPushBack()
{
    ListNode *first;
    ListNodeInit(&first);

    ListNodePushBack(&first, 1);
    ListNodePushBack(&first, 2);
    ListNodePushBack(&first, 3);
    ListNodePushBack(&first, 4);
    ListNodePushBack(&first, 5);
    ListNodePushBack(&first, 6);
    Print(first);
}
void TestPopBack()
{
    ListNode *first;
    ListNodeInit(&first);

    ListNodePushBack(&first, 1);
    ListNodePushBack(&first, 2);
    ListNodePushBack(&first, 3);
    ListNodePushBack(&first, 4);
    ListNodePushBack(&first, 5);
    ListNodePushBack(&first, 6);
    Print(first);
    ListNodePopBack(&first);
    Print(first);
    ListNodePopBack(&first);
    Print(first);
}


void TestInsert()
{
    ListNode *first;
    ListNodeInit(&first);

    ListNodeInsert(&first, 1, 1);
    ListNodePushBack(&first, 3);
    Print(first);
    ListNodeInsert(&first, 2, 2);
    Print(first);
    ListNodePushBack(&first, 5);
    ListNodePushBack(&first, 6);
    Print(first);
    ListNodeInsert(&first, 4, 4);
    ListNodeInsert(&first, 7, 7);
    Print(first);
}
int main()
{
    // TestPushFront();
    // TestPushBack();
    // TestPopFront();
    // TestPopBack();
    TestInsert();
    return 0;
}
