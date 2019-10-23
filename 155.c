#if 0
//155.×îÐ¡Õ»
#define _CRT_SECURE_NO_WARNINGS 1

typedef struct Stack
{
    int *base;
    int capacity;
    int top;
}Stack;

void StackInit(Stack *pst)
{
    int n = 8000;
    pst->base = (int*)malloc(sizeof(int) * n);
    pst->top = pst->capacity = 0;
}

bool StackFull(Stack *pst)
{
    return pst->top >= pst->capacity;
}

bool StackEmpty(Stack *pst)
{
    return pst->top == 0;
}

void StackFree(Stack *pst)
{
    free(pst->base);
    pst->base = NULL;
    pst->top = pst->capacity = 0;
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

typedef struct
{
    Stack st;
    Stack min_st;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate()
{
    MinStack *pst = (MinStack*)malloc(sizeof(MinStack));
    StackInit(&(pst->st));
    StackInit(&(pst->min_st));
    return pst;
}

void minStackPush(MinStack* obj, int x)
{
    if(StackEmpty(&(obj->min_st)))
        StackPush(&(obj->min_st), x);
    else
    {
        if(StackTop(&(obj->min_st)) >= x)
            StackPush(&(obj->min_st), x);
    }
    StackPush(&(obj->st), x);
}

void minStackPop(MinStack* obj)
{
    if(StackTop(&(obj->min_st)) == StackTop(&(obj->st)))
        StackPop(&(obj->min_st));
    StackPop(&(obj->st));
}

int minStackTop(MinStack* obj)
{
    return StackTop(&(obj->st));
}

int minStackGetMin(MinStack* obj)
{
    return StackTop(&(obj->min_st));
}

void minStackFree(MinStack* obj)
{
    StackFree(&(obj->st));
    StackFree(&(obj->min_st));
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
#endif