#include <stdio.h>
#include <assert.h>
#include "Stack.h"

void StackInit(Stack *ps)
{
    assert(ps);
    ps->_top = 0;
}

void StackPush(Stack *ps, DataType data)
{
    assert(ps);
    ps->_array[ps->_top++] = data;
}

void StackPop(Stack *ps)
{
    assert(ps);
    if (StackEmpty(ps))
    {
        return;
    }
    ps->_top--;
}

DataType StackTop(Stack *ps)
{
    assert(ps);
    return ps->_array[ps->_top - 1];
}

int StackSize(Stack *ps)
{
    assert(ps);
    return ps->_top;
}

int StackEmpty(Stack *ps)
{
    assert(ps);
    return 0 == ps->_top;
}

int main()
{
    Stack s;
    StackInit(&s);
    StackPush(&s, 1);
    StackPush(&s, 2);
    StackPush(&s, 3);
    StackPush(&s, 4);
    StackPush(&s, 5);
    printf("size = %d\n", StackSize(&s));
    printf("top = %d\n", StackTop(&s));
    StackPop(&s);
    printf("size = %d\n", StackSize(&s));
    printf("top = %d\n", StackTop(&s));
    return 0;
}
