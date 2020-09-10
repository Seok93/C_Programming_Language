#include <stdio.h>
#include <math.h>

/*
* 예제 코드 설명: 구조체 배열 선언과 초기화 방법 예제 
* 
* 1. 구조체의 배열의 선언과 초기화도 일반 자료형의 배열의 선언과 초기화 방법이 유사하다.
* 
*/
struct person {
    char name[20];
    char phoneNum[20];
    int age;
};

int main(void) {
    int i;
    struct person arr[3] = {
        { "이승기", "010-1234-1234", 19 },
        { "정지영", "010-4321-7234", 19 },
        { "한지수", "010-0844-1354", 30 }
    };

    for (i = 0; i < sizeof(arr)/sizeof(struct person); i++) {
        printf("%s %s %d \n", arr[i].name, arr[i].phoneNum, arr[i].age);
    }

    return 0;
}
