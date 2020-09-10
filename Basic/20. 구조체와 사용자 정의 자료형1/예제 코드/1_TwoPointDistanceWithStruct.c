#include <stdio.h>
#include <math.h>

/*
* 예제 코드 설명: 구조체 선언과 구조체 안 멤버변수에 접근하는 방법 예제 
* 
* 1. 구조체 정의: 사용자 정의 자료형로 하나 이상의 변수를 묶어서 새로운 자료형을 만들 때 사용한다.
* 2. .연산자를 통해 구조체의 멤버변수에 접근한다.
*/

struct point { // 구조체 정의
    int xpos;
    int ypos;
};

int main(void) {
    struct point pos1, pos2; // 구조체를 이용한 변수 선언
    int xDif, yDif;
    double distance;

    fputs("point1 pos: ", stdout);
    scanf("%d %d", &pos1.xpos, &pos1.ypos); // 구조체의 멤버변수 접근

    fputs("point2 pos: ", stdout);
    scanf("%d %d", &pos2.xpos, &pos2.ypos);

    xDif = pos1.xpos - pos2.xpos;
    yDif = pos1.ypos - pos2.ypos;
    distance = sqrt((double)(xDif * xDif) + (yDif * yDif));

    printf("두 점의 거리는 %g입니다. \n", distance);

    return 0;
}
