#include <stdio.h>
#include "SimpleHeap.h"

/**
* 예제 코드 설명: 우선순위를 직접 설정해준 우선순위 큐 예제
* 
* 1. 원래는 우선순위의 판단 기준을 힙이 설정할 수 있도록 설정해야 하지만, 일단은 우선순위 큐의 원리에 집중하여 구현
* 2. 우선순위 큐는 FIFO 특성을 가진 큐와는 다르게 우선순위가 빠른 데이터부터 출력해준다.
* 3. 우선순위 큐는 힙으로 구현하는 것이 성능 평가상 좋고, 힙은 배열로 구현하는 것이 좋다.
*/
int main()
{
    Heap heap;
    HeapInit(&heap);

    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("%c \n", HDelete(&heap));

    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("%c \n", HDelete(&heap));

    while (!HIsEmpty(&heap))
    {
        printf("%c \n", HDelete(&heap));
    }
}