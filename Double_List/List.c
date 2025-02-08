#include "List.h"

ListNode* BuyNode(SLDataType x)
{
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    if(tmp == NULL)
    {
        printf("malloc : %s\n" , strerror(errno));
        return NULL;
    }
    tmp -> data = x;
    tmp ->next = NULL;
    tmp ->prev = NULL;
    return tmp;
}

void ListPrint(ListNode* phead)
{
    if(phead == NULL)
    {
        printf("no data , can not print\n");
        return;
    }
    ListNode* cur = phead -> next;
    printf("%d\n" , phead ->data);
    while(cur != phead)
    {
        printf("%d\n" , cur ->data);
        cur = cur ->next;
    }
}

ListNode* CreateFirstNode(SLDataType x)
{
    ListNode* tmp = BuyNode(x);
    tmp ->next = tmp;
    tmp ->prev = tmp;
    return tmp;
}

ListNode* ListPushBack(ListNode* phead , SLDataType x)
{
    assert(phead);
    ListNode* tail = phead ->prev;
    ListNode* tmp = BuyNode(x);
    tail ->next = tmp;
    tmp ->prev = tail;
    tmp ->next = phead;
    phead ->prev = tmp;
    return phead;
}

ListNode* ListPopBack(ListNode** pphead)
{
    assert(*pphead);
    if((*pphead) ->next == (*pphead))
    {
        free(*pphead);
        *pphead = NULL;
        return NULL;
    }
    ListNode* tail = (*pphead) ->prev;
    (*pphead) ->prev = tail ->prev;
    tail ->prev ->next = (*pphead);
    free(tail);
    return *pphead;
}

ListNode* ListPushFront(ListNode** pphead , SLDataType x)
{
    assert(*pphead);
    ListNode* newNode = BuyNode(x);
    newNode ->next = *pphead;
    newNode ->prev = (*pphead) ->prev;
    (*pphead) ->prev ->next = newNode;
    (*pphead) ->prev = newNode;
    *pphead = newNode;
    return *pphead;
}

ListNode* ListPopFront(ListNode** pphead)
{
    assert(*pphead);
    if((*pphead) ->prev == (*pphead))
    {
        free(*pphead);
        *pphead = NULL;
        return NULL;
    }
    ListNode* first = (*pphead) -> next;
    ListNode* tail = (*pphead) ->prev;
    first ->prev = tail;
    tail ->next = first;
    free(*pphead);
    *pphead = first;
    return *pphead;
}

ListNode* ListFind(ListNode* phead , SLDataType x)
{
    assert(phead);
    ListNode* cur = phead;
    while(cur ->data != x)
    {
        cur = cur ->next;
        if(cur == phead)
            return NULL;
    }
    return cur;
}

ListNode* ListInsert(ListNode* pos , SLDataType x)  //在pos前插入x
{
    assert(pos);
    ListNode* posprev = pos ->prev;
    ListNode* newnode = BuyNode(x);
    posprev ->next = newnode;
    newnode ->next = pos;
    pos ->prev = newnode;
    newnode ->prev = posprev;
}

void ListErase(ListNode* pos)
{
    assert(pos);
    if(pos ->next == pos)
    {
        free(pos);
        return;
    }
    ListNode* posprev = pos ->prev;
    ListNode* posnext = pos ->next;
    free(pos);
    posprev ->next = posnext;
    posnext ->prev = posprev;
}
