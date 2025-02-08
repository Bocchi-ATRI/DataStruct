#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef __SEQLIST_H
#define __SEQLIST_H

#define N 2
typedef int SeqDataType;

typedef struct SeqList
{
    SeqDataType* _s;
    int size;
    int capacity;
}SeqList;

void SeqListInit(SeqList* s);

void SeqListDestroy(SeqList* s);

void CheckCapacity(SeqList* s);

void SeqListPushBack(SeqList* s , SeqDataType x);

void SeqListPopBack(SeqList* s);

void SeqListPushFront(SeqList* s , SeqDataType x);

void SeqListPopFront(SeqList* s);

void SeqListInsert(SeqList* s , int pos , SeqDataType x);

void SeqListErase(SeqList* s , int pos);

void SeqListShowData(SeqList* s);

void SeqListFind(SeqList* s , SeqDataType x);

#endif
