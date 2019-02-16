typedef int QDataType;
typedef struct QNode 
{
    QDataType _data;
    struct QNode *_next;
}QNode;

typedef struct Queue 
{
    QNode *_front;
    QNode *_rear;
}Queue;

void QueueInit(Queue *q);
void QueueDestroy(Queue *q);
static QNode *CreateNode(QDataType data);
void QueuePush(Queue *q, QDataType data);
void QueuePop(Queue *q);
QDataType QueueFront(Queue *q);
int QueueEmpty(const Queue *q);
int QueueSize(const Queue *q);
