#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist)
{
    plist->head = (Node *)malloc(sizeof(Node)); // 더미 노드 생성
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void FInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // 새 노드 생성
    newNode->data = data;                         // 새 노드에 데이터 저장

    newNode->next = plist->head->next; // 새 노드가 다른 노드를 가리키게 함
    plist->head->next = newNode;       // 더미 노드가 새 노드를 가리키게 함

    plist->numOfData++; // 저장된 노드의 수를 하나 증가시킴
}

void SInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // 새 노드 생성
    Node *pred = plist->head;                     // 더미 노드를 가리킴
    newNode->data = data;                         // 새 노드에 데이터 저장

    // 새 노드가 들어갈 자리를 찾기 위한 반복문
    while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
        pred = pred->next;

    newNode->next = pred->next; // 새 노드의 오른쪽을 연결
    pred->next = newNode;       // 새 노드의 왼쪽을 연결

    plist->numOfData++; // 저장된 데이터의 수 하나 증가
}

void LIsert(List *plist, LData data)
{
    if (plist->comp == NULL)  // 정렬 기준이 마련되지 않았다면
        FInsert(plist, data); // 머리에 노드 추가
    else                      // 정렬 기준이 마련되어 있다면
        SInsert(plist, data); // 정렬기준에 근거하여 노드 추가
}

int LFirst(List *plist, LData *pdata)
{
    if (plist->head->next == NULL) // 더미 노드가 NULL을 가리킨다면,
        return FALSE;              // 더이상 반환할 데이터가 없음

    plist->before = plist->head;    // before는 더미 노드를 가리키게 함
    plist->cur = plist->head->next; // cur은 첫 번째 노드를 가리키게 함

    *pdata = plist->cur->data; // 첫 번째 노드의 데이터를 전달
    return TRUE;
}

int LNext(List *plist, LData *pdata)
{
    if (plist->cur->next == NULL) // 현재 노드의 다음 노드가 NULL이라면
        return FALSE;             // 더이상 반환할 데이터가 없음

    plist->before = plist->cur;    // cur이 가리키던 것을 before가 가리킴
    plist->cur = plist->cur->next; // cur은 그 다음 노드를 가리킴

    *pdata = plist->cur->data; // cur이 가리키는 노드의 데이터 전달
    return TRUE;               // 데이터 반환 성공
}

LData LRemove(List *plist)
{
    Node *rpos = plist->cur;  // 소멸 대상 노드의 주소값을 저장
    LData rdata = rpos->data; // 소멸 대상 노드의 데이터를 저장

    plist->before->next = plist->cur->next; // 소멸 대상을 리스트의 연결에서 제거
    plist->cur = plist->before;             // cur이 가리키는 위치를 재조정

    free(rpos);         // 리스트에서 제거된 노드 소멸
    plist->numOfData--; // 저장된 데이터의 수 하나 감소
    return rdata;       // 제거된 노드의 데이터 반환
}

int LCount(List *plist)
{
    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}