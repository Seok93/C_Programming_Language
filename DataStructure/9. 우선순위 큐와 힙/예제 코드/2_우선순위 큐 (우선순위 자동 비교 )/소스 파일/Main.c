#include <stdio.h>
#include "UsefulHeap.h"

/**
* 예제 코드 설명: 우선순위를 자동으로 비교해주는 우선순위 큐  예제
* 
* 1. 우선순위를 판별하는 함수를 함수포인터로 넘겨주고, 데이터를 집어넣을 때 알아서 조정하도록 만듬
*/
int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
    // return ch1-ch2;
}

int main()
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf("%c \n", HDelete(&heap));

    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf("%c \n", HDelete(&heap));

    while (!HIsEmpty(&heap))
    {
        printf("%c \n", HDelete(&heap));
    }
}