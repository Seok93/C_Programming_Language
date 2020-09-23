#include <stdio.h>
#include "CircularQueue.h"

int NextPosIdx(int pos)
{
    if (pos == QUE_LEN - 1)
        return 0;
    else
        return pos + 1;
}

void QueueInit(Queue *pq)
{ // 텅 빈 경우 front와 rear은 동일한 위치를 가리킨다.
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue *pq)
{
    if (pq->front == pq->rear) // 큐가 텅 비었다면,
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue *pq, Data data)
{
    if (NextPosIdx(pq->rear) == pq->front)
    { // 큐가 꽉 찼다면,
        printf("Queue Memory Error!");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear); // rear을 한 칸 이동
    pq->queArr[pq->rear] = data;     // rear이 가리키는 곳에 데이터 저장
}

Data Dequeue(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front); // front를 한 칸 이동
    return pq->queArr[pq->front];      // front가 가리키는 데이터 반환
}

Data QPeek(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    return pq->queArr[NextPosIdx(pq->front)];
}