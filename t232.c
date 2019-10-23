#if 0

//232. 用栈实现队列
#define _CRT_SECURE_NO_WARNINGS 1

typedef struct Stack
{
    int *base;
    int top;
    int capacity;
}Stack;

bool StackFull(Stack *pst)
{
    return pst->top >= pst->capacity;
}

bool StackEmpty(Stack *pst)
{
    return pst->top == 0;
}

void StackInit(Stack *pst)
{
    pst->capacity = 1000;
    pst->base = (int*)malloc(sizeof(int) * pst->capacity);
    pst->top = 0;
}

void StackPush(Stack *pst, int x)
{
    pst->base[pst->top++] = x;
}

void StackPop(Stack *pst)
{
    --(pst->top);
}

int StackTop(Stack *pst)
{
    return pst->base[pst->top-1];
}
//////////////////////////////////////////////////////////
typedef struct
{
    Stack stack1;
    Stack stack2;
    int front;
    int tail;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
    MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&(queue->stack1));
    StackInit(&(queue->stack2));
    queue->front = queue->tail;
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
    StackPush(&(obj->stack1), x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
    int val = 0;
    if(StackEmpty(&(obj->stack2)))
    {
        while(!StackEmpty(&(obj->stack1)))
        {
            StackPush(&(obj->stack2), StackTop(&(obj->stack1)));
            StackPop(&(obj->stack1));
        }
    }
    val = StackTop(&(obj->stack2));
    StackPop(&(obj->stack2));
    return val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
    if(StackEmpty(&(obj->stack2)))
    {
        while(!StackEmpty(&(obj->stack1)))
        {
            StackPush(&(obj->stack2), StackTop(&(obj->stack1)));
            StackPop(&(obj->stack1));
        }
    }
    return StackTop(&(obj->stack2));
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
    return StackEmpty(&(obj->stack1)) && StackEmpty(&(obj->stack2));
}

void myQueueFree(MyQueue* obj)
{
    free((obj->stack1).base);
    free((obj->stack2).base);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
#endif