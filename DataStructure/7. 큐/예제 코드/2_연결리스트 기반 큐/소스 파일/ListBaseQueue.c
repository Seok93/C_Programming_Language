#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue *pq)
{
    if (pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue *pq, Data data)
{
    Node *newData = (Node *)malloc(sizeof(Node));
    newData->data = data;
    newData->next = NULL;

    if (QIsEmpty(pq))
    {
        pq->front = newData;
        pq->rear = newData;
    }
    else
    {
        pq->rear->next = newData;
        pq->rear = newData;
    }
}

Data Dequeue(Queue *pq)
{
    Node *delNode;
    Data retData;

    if (QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    delNode = pq->front;
    retData = delNode->data;

    pq->front = pq->front->next;
    free(delNode);
    return retData;
}

Data QPeek(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    return pq->front->data;
}