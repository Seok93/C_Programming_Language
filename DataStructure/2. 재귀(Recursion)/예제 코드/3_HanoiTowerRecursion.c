#include <stdio.h>

/*
* 예제 코드 설명: 하노이 타워 예제
* 
*/
void HanoiTowerMove(int num, char from, char by, char to)
{
    if (num == 1)
    {
        printf("원반1을 %c에서 %c로 이동 \n", from, to);
    }
    else
    {
        HanoiTowerMove(num - 1, from, to, by);
        printf("원반%d을(를) %c에서 %c로 이동 \n", num, from, to);
        HanoiTowerMove(num - 1, by, from, to); // A막대와 B막대를 바꿔 원반이 쌓여있는 막대를 기준 A로 만든다.
    }
}

int main()
{
    // 막대 A의 원반 3개를 막대 B를 경유하여 막대C로 옮기기
    HanoiTowerMove(3, 'A', 'B', 'C');

    return 0;
}