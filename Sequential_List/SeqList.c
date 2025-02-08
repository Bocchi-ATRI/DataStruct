#include <stdio.h>
#include "SeqList.h"

void SeqListInit(SeqList* s)
{
    s->_s = (SeqDataType*)malloc(sizeof(SeqDataType) * N);
    if(s->_s == NULL)
    {
        printf("Malloc : %s\n" , strerror(errno));
        return;
    }
    s->size = 0;
    s->capacity = N;
}

void SeqListDestroy(SeqList* s)
{
    free(s);
    s = NULL;
}

void CheckCapacity(SeqList* s)
{
    if(s->size == s->capacity)
    {
        int newcapacity = s->capacity == 0 ? 2 : s->capacity * 2;
        SeqDataType* ps = (SeqDataType*)realloc(s->_s , sizeof(SeqDataType) * (newcapacity));
        if(!ps)
        {
            printf("Realloc : %s\n" , strerror(errno));
            return;
        }
        s->_s = ps;
        s->capacity = newcapacity;
    }
}

void SeqListPushBack(SeqList* s , SeqDataType x)
{
    assert(s);
    CheckCapacity(s);
    s->_s[s->size] = x;
    s->size ++;
    printf("Push Back Successfully\n");
}

void SeqListPopBack(SeqList* s)
{
    assert(s);
    s->size --;
}

void SeqListPushFront(SeqList* s , SeqDataType x)
{
    assert(s);
    CheckCapacity(s);
    for(int i = 0 ; i < s->size ; ++ i)
    {
        s->_s[s->size - i] = s->_s[s->size - i - 1];
    }
    s->_s[0] = x;
    s->size ++;
}

void SeqListPopFront(SeqList* s)
{
    assert(s);
    s->size --;
    for(int i = 0 ; i < s->size ; ++ i)
    {
        s->_s[i] = s->_s[i + 1];
    }
}

void SeqListInsert(SeqList* s , int pos , SeqDataType x)
{
    assert(s);
    assert(pos < s->size && pos >= 0);
    CheckCapacity(s);
    for(int i = 0 ; i < s->size - pos ; ++ i)
    {
        s->_s[s->size - i] = s->_s[s->size - i - 1];
    }
    s->_s[pos] = x;
    s->size ++;
}

void SeqListErase(SeqList* s , int pos)
{
    assert(s);
    assert(pos < s->size && pos >= 0);
    for(int i = 0 ; i < s->size - pos - 1 ; ++ i)
    {
        s->_s[pos + i] = s->_s[pos + i + 1];
    }
    s->size --;
}

void SeqListShowData(SeqList* s)
{
    assert(s);
    for(int i = 0 ; i < s->size ; ++ i)
    {
        printf("%d\t" , s->_s[i]);
        if((i + 1) % 8 == 0 && i != 0 && i != s->size - 1)
        {
            printf("\n");
        }
    }
    printf("\n");
}

void SeqListFind(SeqList* s , SeqDataType x)
{
    assert(s);
    int flag = 0;
    for(int i = 0 ; i < s->size ; ++ i)
    {
        if(s->_s[i] == x)
        {
            printf("%d\t" , i);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("\n");
    }
}
