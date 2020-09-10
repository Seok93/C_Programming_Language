#include <stdio.h>
#include <math.h>

/*
* 예제 코드 설명: 구조체 선언 동시에 초기화 예제 
* 
* 1. 구조체를 선언과 동시에 초기화 하는 방법은, 배열의 초기화와 유사하다. 
*/

struct point {
    int xpos;
    int ypos;
};

struct person {
    char name[20];
    char phoneNum[20];
    int age;
};

int main(void) {
    struct point pos = { 10, 20 }; // 중괄호를 사용하며, 구조체 멤버변수 순으로 초기화
    struct person man = { "이승기", "010-1234-1234", 19 };

    printf("%d %d \n", pos.xpos, pos.ypos);
    printf("%s %s %d \n", man.name, man.phoneNum, man.age);

    return 0;
}
