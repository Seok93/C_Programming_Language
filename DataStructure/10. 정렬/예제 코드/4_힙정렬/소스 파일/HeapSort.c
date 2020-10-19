#include <stdio.h>
#include "UsefulHeap.h"

/**
* 예제 코드 설명: 힙 정렬(Heap Sort)  예제
* 
* 1. 힙 정렬은 힙 자료구조를 이용하여 정렬하는 알고리즘이다.
* 2. 힙 정렬의 알고리즘 전략
*    ① 정렬 대상인 데이터들을 힙에 넣어준다. (힙의 루트노드에 저장된 값이 가장 크다 or 앞선다 라는 특성을 이용)
*    ② 힙에 저장한 데이터를 하나씩 삭제하며 출력하여 배열에 순차적으로 저장해주면, 정렬이 완료된다.
* 
* 3. 힙 정렬의 시간 복잡도
*    ① 비교연산에 의한 시간복잡도- 최선의 경우: O(0) 최악의 경우: O(logN)
*    ② 데이터 이동연산에 의한 시간복잡도- 최선의 경우: O(0) 최악의 경우: O(N * logN)
*/
int PriComp(int n1, int n2)
{
    return n2 - n1; // 오름차순 정렬을 위한 문장
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    int i;

    HeapInit(&heap, pc);

    // 정렬 대상을 힙으로 구성
    for (i = 0; i < n; i++)
        HInsert(&heap, arr[i]);

    for (i = 0; i < n; i++)
        arr[i] = HDelete(&heap);
}

int main()
{
    int arr[4] = {3, 2, 4, 1};
    int i;

    HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

    for (i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}