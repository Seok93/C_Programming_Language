#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

/*
* 큐는 운영체제나 네트워크와 관련된 SW구현에 있어서 중요한 역할을 하거나, 특정 현상을 시뮬레이션할 때 주로 사용한다.
* 아래는 햄버거 가게를 시뮬레이션하는 예제이다.
* 
* CircularQuereㅇ에서 QUE_LEN은 햄버거를 받기 위해 대기하는 사람들이고,
* 점심 시간 1시간당 모든 사람들이 대기하면서 햄버거를 받기 위해서는 대기석이 몇개가 필요한지 시뮬레이션 해보는 간단한 코드이다. 
*/

#define CUS_COME_TERM 15 // 고객의 주문 간격: 초단위

#define CHE_BUR 0 // 치즈버거 상수
#define BUL_BUR 1 // 불고기버거 상수
#define DUB_BUR 2 // 더블 버거 상수

#define CHE_TERM 12 // 치즈버거 제작시간: 초단위
#define BUL_TERM 12 // 불고기버거 제작시간: 초단위
#define DUB_TERM 12 // 더블버거 제작시간: 초단위

int main()
{
    int makeProc = 0; // 햄버거 제작 진행 상황
    int cheOrder = 0, bulOrder = 0, dubOrder = 0;
    int sec;

    Queue que;

    QueueInit(&que);
    srand(time(NULL));

    // 아래 for문의 1회 회전은 1초의 시간 흐름을 의미함
    for (sec = 0; sec < 3600; sec++)
    {
        if (sec % CUS_COME_TERM == 0)
        {
            switch (rand() % 3)
            {
            case CHE_BUR:
                Enqueue(&que, CHE_TERM);
                cheOrder += 1;
                break;

            case BUL_BUR:
                Enqueue(&que, BUL_BUR);
                bulOrder += 1;
                break;

            case DUB_BUR:
                Enqueue(&que, DUB_BUR);
                dubOrder += 1;
                break;
            }
        }

        if (makeProc <= 0 && !QIsEmpty(&que))
            makeProc = Dequeue(&que);

        makeProc--;
    }

    printf("Simulation Report! \n");
    printf(" - Cheese buger: %d \n", cheOrder);
    printf(" - Bulgogi burger: %d \n", bulOrder);
    printf(" - Double burger: %d \n", dubOrder);
    printf(" - Waiting room size: %d \n", QUE_LEN);

    return 0;
}