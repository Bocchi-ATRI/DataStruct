#include <stdio.h>
#include "List.h"

SListNode* BuyListNode(SDataType x)
{
    SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
    if(tmp == NULL)
    {
        printf("malloc : %s\n" , strerror(errno));
        return NULL;
    }
    tmp -> data = x;
    tmp -> next = NULL;
    return tmp;
}

int GetListNum(SListNode* phead)
{
    if(phead == NULL)
        return 0;
    int count = 1;
    SListNode* cur = phead;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
        count ++;
    }
    return count;
}

void SListPushBack(SListNode** pphead , SDataType x)
{
    if(*pphead == NULL)
    {
        *pphead = BuyListNode(x);
    }
    else
    {
        SListNode* cur = *pphead;
        while(cur -> next != NULL)
        {
            cur = cur -> next;
        }
        SListNode* tmp = BuyListNode(x);
        cur -> next = tmp;
    }
}

void SListPopBack(SListNode** pphead)
{
    SListNode* p = NULL;
    if(*pphead == NULL)   //0个
        return;
    SListNode* cur = *pphead;
    if(cur -> next == NULL)         //1个
    {
        free(cur);
        cur = NULL;
        *pphead = NULL;
        return;
    }
    while(cur -> next != NULL)       //多个
    {
        if(cur -> next -> next == NULL)
            p = cur;
        cur = cur -> next;
    }
    free(cur);
    p -> next = NULL;
}

void SlistPushFront(SListNode** pphead , SDataType x)
{
    SListNode* cur = BuyListNode(x);
    cur -> next = *pphead;
    *pphead = cur;
}

void SListPopFront(SListNode** pphead)
{
    if(*pphead == NULL)
        return;
    SListNode* cur = (*pphead) -> next;
    free(*pphead);
    *pphead = cur;
}

void SListInsert(SListNode** pphead , int pos , SDataType x)
{
    int count = GetListNum(*pphead);
    if(count == 0)
    {
        assert(pos == 0);
        *pphead = BuyListNode(x);
        return;
    }
    assert(pos < count);
    SListNode* cur = *pphead;
    for(int i = 1 ; i < pos ; ++ i)
    {
        cur = cur -> next;
    }
    SListNode* after = cur -> next;
    cur -> next = BuyListNode(x);
    cur -> next -> next = after;
}

void SListErase(SListNode** pphead , int pos)
{
    assert(*pphead != NULL);
    int count = GetListNum(*pphead);
    assert(pos < count);
    if(count == 1)
    {
        free(*pphead);
        *pphead = NULL;
        return;
    }
    SListNode* cur = *pphead;
    for(int i = 1 ; i < pos ; ++ i)
    {
        cur = cur -> next;
    }
    SListNode* after = cur -> next -> next;
    free(cur -> next);
    cur -> next = after;
}

void SListPrint(SListNode* phead)
{
    SListNode* cur = phead;
    while(cur != NULL)
    {
        printf("%d\n" , cur -> data);
        cur = cur -> next;
    }
}

void SListDestroy(SListNode** pphead)
{
    if(*pphead == NULL)
        return;
    SListNode* cur = *pphead;
    SListNode* p = cur;
    while(cur -> next != NULL)
    {
        p = cur -> next;
        free(cur);
        cur = p;
    }
    free(cur);
    *pphead = cur = p = NULL;
}
