#if 0
//622.设计循环队列
#define _CRT_SECURE_NO_WARNINGS 1
typedef struct
{
    int *base;
    int capacity;
    int front;
    int tail;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue *p = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    p->capacity = k + 1;
    p->base = (int*)malloc(sizeof(int) * (p->capacity));
    p->front = p->tail = 0;
    return p;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    if(myCircularQueueIsFull(obj))
        return false;
    obj->base[obj->tail] = value;
    obj->tail = (obj->tail+1) % (obj->capacity);
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if(myCircularQueueIsEmpty(obj))
        return false;
    obj->front = (obj->front+1) % (obj->capacity);
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj)
{
    if(myCircularQueueIsEmpty(obj))
        return -1;
    return (obj->base)[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj)
{
    if(myCircularQueueIsEmpty(obj))
        return -1;
    return (obj->base)[(obj->tail-1+obj->capacity)%(obj->capacity)];//注意这里
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->front == obj->tail;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->tail+1) % (obj->capacity) == obj->front;
}
//Empty
void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->base);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/

#endif