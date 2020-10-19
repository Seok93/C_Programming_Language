
#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List *plist)
{
    // 더미데이터 생성
    plist->head = (Node *)malloc(sizeof(Node));
    plist->tail = (Node *)malloc(sizeof(Node));

    // Head의 더미 초기화
    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    // Tail의 더미 초기화
    plist->tail->next = NULL;
    plist->tail->prev = plist->head;

    // 리스트의 데이터 수 초기화
    plist->numOfData = 0;
}

void LInsert(List *plist, Data pdata)
{ // Tail에 Node 추가
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = pdata;

    // 왼쪽 노드 연결
    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;

    // 오른쪽 노드 연결
    newNode->next = plist->tail;
    plist->tail->prev = newNode;

    plist->numOfData++;
}

int LFirst(List *plist, Data *pdata)
{
    if (plist->head->next == plist->tail)
        return FALSE;

    plist->cur = plist->head->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List *plist, Data *pdata)
{
    if (plist->cur->next == plist->tail)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LPrevious(List *plist, Data *pdata)
{
    if (plist->cur->prev == plist->head)
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;
}

Data LRemove(List *plist)
{
    Node *rpos = plist->cur;
    Node *rdata = plist->cur->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;
    plist->cur = plist->cur->prev;

    free(rpos);
    plist->numOfData--;
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}