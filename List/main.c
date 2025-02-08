#include <stdio.h>
#include "List.h"

int main()
{
    SListNode* p = NULL;
    SListPushBack(&p , 2);
    SListPushBack(&p , 3);
    SListPushBack(&p , 4);
    SlistPushFront(&p , 5);
    SListInsert(&p , 2 , 4);
    SListPrint(p);
    SListDestroy(&p);
    return 0;
}
