#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//20. ÓÐÐ§µÄÀ¨ºÅ

bool CapacityInc(char **arr, int *pcapacity, int top);

bool CapacityInc(char **arr, int *pcapacity, int top)
{
    char *p = NULL;
    if(top < *pcapacity)
        return false;
    p = (char*)realloc(*arr, sizeof(char) * (*pcapacity+8));
    if(p == NULL)
        return false;
    *arr = p;
    *pcapacity += 8;
    return true;
}

bool isValid(char * s){
    char *arr = NULL;
    int top = 0;
    int capacity = 8;
    arr = (char*)malloc(sizeof(char) * 8);
    while(*s != '\0')
    {
        if(*s=='(' || *s=='[' || *s=='{')
        {
            CapacityInc(&arr, &capacity, top);
            arr[top++] = *s;
            ++s;
        }
        else if(top > 0)
        {
            if((*s==')'&&arr[top-1]!='(') || 
               (*s==']'&&arr[top-1]!='[') || 
               (*s=='}'&&arr[top-1]!='{'))
            {
                free(arr);
                arr = NULL;
                return false;               
            }
            else
            {
                --top;
                ++s;
            }      
        }
        else
        {
            free(arr);
            arr = NULL;
            return false;
        }
    }
    if(top == 0)
    {
        free(arr);
        arr = NULL;
        return true;
    }
    free(arr);
    arr = NULL;
    return false;
}
#endif