#define MAXSIZE 10
typedef int DataType;
typedef struct Stack
{
    DataType _array[MAXSIZE];
    int _top;
}Stack;

void StackInit(Stack *ps);
void StackPush(Stack *ps, DataType data);
void StackPop(Stack *ps);
DataType StackTop(Stack *ps);
int StackSize(Stack *ps);
int StackEmpty(Stack *ps);
