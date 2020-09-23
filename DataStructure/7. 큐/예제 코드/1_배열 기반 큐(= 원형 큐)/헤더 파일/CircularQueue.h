#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0
#define QUE_LEN 100

typedef int Data;

typedef struct _CQueue
{
    int front; // Queue의 머리 부분
    int rear;  // Queue의 꼬리 부분
    Data queArr[QUE_LEN];
} CQueue;
typedef CQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data); // 데이터 삽입
Data Dequeue(Queue *pq);            // 데이터 출력
Data QPeek(Queue *pq);              // 데이터 열람

#endif
