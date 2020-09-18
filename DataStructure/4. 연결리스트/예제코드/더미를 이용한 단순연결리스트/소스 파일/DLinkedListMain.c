#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

/*
*  예제 설명: 더미를 이용한 단순 연결리스트이다.
* 
* 1. 단순 연결리스트란 연결의 형태가 한쪽 방향으로 전개되고, 시작과 끝이 분명히 존재하는 형태이며, 동적할당을 통해 구현한다.
* 2. 연결의 형태가 한쪽 방향으로 전개되고, 시작과 끝이 분명히 존재하는 형태를 말한다.
* 3. 연결리스트에선 head, tail. cur가 중요하다. (저장 방식에 따라 tail생략 가능)
*/
int WhoIsPrecede(int d1, int d2);

int main()
{
    List list;
    LData data;

    // 연결리스트 초기화
    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede);

    // 5개의 데이터 저장
    LIsert(&list, 11);
    LIsert(&list, 11);
    LIsert(&list, 22);
    LIsert(&list, 22);
    LIsert(&list, 33);

    // 저장된 데이터의 전체 출력
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    // 숫자 22을 검색하여 모두 삭제
    if (LFirst(&list, &data))
    {
        if (data == 22)
            LRemove(&list);

        while (LNext(&list, &data))
        {
            if (data == 22)
                LRemove(&list);
        }
    }

    // 저장된 데이터의 전체 출력
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    return 0;
}

int WhoIsPrecede(int d1, int d2)
{
    if (d1 < d2)
        return 0; // d1이 정렬 순서상 앞선다.
    else
        return -1; // d2가 정렬 순서가 앞서거나 같다
}