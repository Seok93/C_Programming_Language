#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List *plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode; // head에 추가하냐 tail의 추가하냐 유일한 차이점, 즉 원형 연결리시트에서는 head와 tail의 구분이 의미가 없으며, 하나의 포인터 값만 있어도 어디든지 추가가 가능하다는 장점이 있다.
    }

    plist->numOfData++;
}

void LInsertFront(List *plist, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    plist->numOfData++;
}

int LFirst(List *plist, Data *pdata)
{
    if (plist->tail == NULL)
        return FALSE;

    plist->before = plist->tail;    // before가 tail을 가지게 한다.
    plist->cur = plist->tail->next; // cur가 head를 가지게 한다.

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, Data *pdata)
{ // 리스트의 끝을 검사하는 코드가 존재하지 않는다. 때문에 리스트의 마지막에 도달했을 때는 다시 첫 번째 노드를 가리키게 되며 무한으로 순환할 수 있게 되었다.
    if (plist->tail == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

Data LRemove(List *plist)
{
    Node *rpos = plist->cur;
    Node *rdata = plist->cur->data;

    if (rpos == plist->tail)
    {
        if (plist->tail == plist->tail->next)
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    plist->numOfData--;
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}