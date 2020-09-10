#include <stdio.h>
#include <math.h>

/*
* 예제 코드 설명: 구조체 포인터 변수의 사용법 예제 
* 
* 1. 구조체 포인터 변수의 선언 및 연산의 방법도 일반적인 포인터 변수의 선언 및 연산의 방법과 다르지 않다.
* 2. .연산자를 통해 접근하는 방법도 똑같으나, *연산과 .연산을 하나로 묶은 효과를 ->연산자 통해 낼 수 있다.
* 
*/
struct point {
    char xpos;
    char ypos;
};

int main(void) {
    struct point pos1 = { 1, 2 };
    struct point pos2 = {100, 200};
    struct point* pptr = &pos1;

    (*pptr).xpos += 4;
    (*pptr).ypos += 5;
    printf("[%d, %d] \n", pptr->xpos, pptr->ypos);

    pptr = &pos2;
    pptr->xpos += 50;
    pptr->ypos += 100;
    printf("[%d, %d] \n", (*pptr).xpos, (*pptr).ypos);

    return 0;
}
