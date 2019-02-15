#include "Stack.cpp"

typedef enum
{
    ADD,
    SUB, 
    MUL, 
    DIV, 
    DATA
}OPERATOR;

typedef struct Cell
{
    OPERATOR _op;
    int _data;
    int _next;
}Cell;

int calcRPN(Cell *RPN, int size)
{
    Stack s;
    StackInit(&s);
    for (int i = 0; i < size; ++i)
    {
        if (DATA == RPN[i]._op)
        {
            StackPush(&s, RPN[i]._data);
        }
        else 
        {
            int left = 0;
            int right = 0;
            right = StackTop(&s);
            StackPop(&s);
            left = StackTop(&s);
            StackPop(&s);
            switch (RPN[i]._op)
            {
                case ADD:
                    StackPush(&s, left + right);
                    break;
                case SUB:
                    StackPush(&s, left - right);
                    break;
                case MUL:
                    StackPush(&s, left * right);
                    break;
                case DIV:
                    if (0 == right)
                    {
                        printf("除数为0，非法\n");
                        return 0;
                    }
                    StackPush(&s, left / right);
                    break;
            }
        }
    }
    return StackTop(&s);
}
