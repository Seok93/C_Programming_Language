#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next;
} Node;

typedef struct _lQuere
{
    Node *front;
    Node *rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data); // 데이터 삽입
Data Dequeue(Queue *pq);            // 데이터 출력
Data QPeek(Queue *pq);              // 데이터 열람

#endif