#include <stdio.h>
#include "SeqList.h"

void TestSeqList1()
{
    SeqList s;
    SeqListInit(&s);
    SeqListPushBack(&s , 2);
    SeqListPushBack(&s , 3);
    SeqListPushBack(&s , 4);
    SeqListPushBack(&s , 5);
    SeqListPushBack(&s , 6);
    SeqListInsert(&s , 1 , 10);
    SeqListShowData(&s);
    SeqListFind(&s , 4);
    SeqListDestroy(&s);
}

int main()
{
    TestSeqList1();
    return 0;
}
