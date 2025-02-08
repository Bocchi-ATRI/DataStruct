#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#ifndef __LIST_H
#define __LIST_H

typedef struct ListNode ListNode;
typedef int SLDataType;

struct ListNode
{
    ListNode* prev;
    ListNode* next;
    SLDataType data;
};

ListNode* BuyNode(SLDataType x);

ListNode* CreateFirstNode(SLDataType x);

void ListPrint(ListNode* phead);

ListNode* ListPushBack(ListNode* phead , SLDataType x);

ListNode* ListPopBack(ListNode** pphead);

ListNode* ListPushFront(ListNode** pphead , SLDataType x);

ListNode* ListPopFront(ListNode** pphead);

ListNode* ListFind(ListNode* phead , SLDataType x);

ListNode* ListInsert(ListNode* pos , SLDataType x);

void ListErase(ListNode* pos);

#endif