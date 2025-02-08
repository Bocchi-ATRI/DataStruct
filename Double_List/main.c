#include <stdio.h>
#include "List.h"

int main()
{
    ListNode* head = CreateFirstNode(0);
    ListPushFront(&head , -1);
    ListPushFront(&head , -2);
    ListPushBack(head , 1);
    ListPushBack(head , 2); // -2 -1 0 1 2
    ListNode* cur = ListFind(head , 0);
    printf("%d\n" , cur ->data);
    ListInsert(cur , -3);
    ListErase(cur);
    ListPrint(head);
    return 0;
}