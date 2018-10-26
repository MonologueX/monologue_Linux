#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct ListNode
{
  DataType _data;
  struct ListNode* _next;
}ListNode;

ListNode* BuyNode(DataType data)
{
  ListNode* node = (ListNode*)malloc(sizeof(ListNode));
  assert(node);
  node->_data = data;
  node->_next = NULL;
}

void ListNodeInit(ListNode** ppFirst)
{
  assert(NULL != *ppFirst);
  ppFirst = NULL;
}

void ListNodeInsert(ListNode** ppFirst, DataType _data)
{

}

int main()
{
  
  return 0;
}
