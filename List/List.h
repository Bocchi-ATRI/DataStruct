#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#ifndef __LIST_H
#define __LIST_H

typedef int SDataType;
typedef struct SListNode SListNode;

struct SListNode
{
    SDataType data;
    SListNode* next;
};

SListNode* BuyListNode(SDataType x);

void SListPushBack(SListNode** pphead , SDataType x);

void SListPopBack(SListNode** pphead);

void SlistPushFront(SListNode** pphead , SDataType x);

void SListPopFront(SListNode** pphead);

int GetListNum(SListNode* phead);

void SListInsert(SListNode** pphead , int pos , SDataType x);

void SListErase(SListNode** pphead , int pos);

void SListPrint(SListNode* phead);

void SListDestroy(SListNode** pphead);

#endif
