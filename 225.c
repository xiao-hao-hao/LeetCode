#if 0

//225.用队列实现栈
#define _CRT_SECURE_NO_WARNINGS 1

typedef struct Queue
{
    int *base;
    int front;
    int tail;
}Queue;

void QueueInit(Queue *Q)
{
    int n = 1000;
    Q->base = (int*)malloc(sizeof(int) * n);
    Q->front = Q->tail = 0;
}

void QueuePush(Queue *Q, int x)
{
    Q->base[Q->tail++] = x;
}

void QueuePop(Queue *Q)
{
    ++(Q->front);
}

int QueueFront(Queue *Q)
{
    return Q->base[Q->front];
}

int QueueBack(Queue *Q)
{
    return Q->base[Q->tail-1];
}

bool QueueEmpty(Queue *Q)
{
    return Q->front == Q->tail;
}

///////////////////////////////////////////////

typedef struct
{
    Queue q1;
    Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate()
{
    MyStack *pst = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&(pst->q1));
    QueueInit(&(pst->q2));
    return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
    Queue *pnonempty = NULL;
    if(QueueEmpty(&(obj->q1)))
        pnonempty = &(obj->q2);
    else
        pnonempty = &(obj->q1);
    QueuePush(pnonempty, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
    int val;
    Queue *pnonempty = NULL;
    Queue *pempty = NULL;
    if(QueueEmpty(&(obj->q1)))
    {
        pempty = &(obj->q1);
        pnonempty = &(obj->q2);
    }
    else
    {
        pempty = &(obj->q2);
        pnonempty = &(obj->q1);
    }
    while(!QueueEmpty(pnonempty))
    {
        val = QueueFront(pnonempty);
        QueuePop(pnonempty);
        if(QueueEmpty(pnonempty))
            break;
        QueuePush(pempty, val);
    }
    return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
    if(QueueEmpty(&(obj->q1)))
        return QueueBack(&(obj->q2));
    else
        return QueueBack(&(obj->q1));
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
    if(QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2)))
        return true;
    return false;
}

void myStackFree(MyStack* obj)
{
    free((obj->q1).base);
    free((obj->q2).base);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
#endif