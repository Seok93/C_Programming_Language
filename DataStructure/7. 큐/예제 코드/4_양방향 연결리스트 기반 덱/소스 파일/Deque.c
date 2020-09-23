#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque *pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
    if (pdeq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DQAddFirst(Deque *pdeq, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pdeq->head;
    if (DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
        pdeq->head->prev = newNode;

    newNode->prev = NULL;
    pdeq->head = newNode;
}

void DQAddLast(Deque *pdeq, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = pdeq->tail;

    if (DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;

    newNode->next = NULL;
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque *pdeq)
{
    Node *rNode;
    Data rData;

    if (DQIsEmpty(pdeq))
    { // 데이터가 없다면,
        printf("Deque Memory Error!");
        exit(-1);
    }

    // 삭제할 데이터 주소값과 값 임시 저장
    rNode = pdeq->head;
    rData = pdeq->head->data;

    // 데이터 삭제
    pdeq->head = pdeq->head->next;
    free(rNode);

    if (pdeq->head == NULL) // 데이터가 없다면,
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;

    return rData;
}

Data DQRemoveLast(Deque *pdeq)
{
    Node *rNode;
    Data rData;

    if (DQIsEmpty(pdeq))
    { // 데이터가 없다면,
        printf("Deque Memory Error!");
        exit(-1);
    }

    // 삭제할 데이터 주소값과 값 임시 저장
    rNode = pdeq->tail;
    rData = pdeq->tail->data;

    pdeq->tail = pdeq->tail->prev;
    free(rNode);

    if (pdeq->tail == NULL) // 데이터가 없다면,
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;

    return rData;
}

Data DQGetFirst(Deque *pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }
    return pdeq->head->data;
}

Data DQGetLast(Deque *pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }
    return pdeq->tail->data;
}