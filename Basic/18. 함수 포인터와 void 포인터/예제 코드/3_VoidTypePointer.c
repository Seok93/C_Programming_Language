#include <stdio.h>

/*
* 예제 코드 설명: 함수의 매개변수에 함수포인터를 선언하여 유용하게 사용하기 예제
* 
* 1. void 포인터는 주소값이라면 어떠한 것이든 담을 수 있다. (어떠한 형 정보도 없기 때문에 형에 구애받지 않는다.)
* 2. 어떠한 형 정보도 없기 때문에 포인터연산, 값의변경, 값의 참조가 불가능하다. 
* 3. 일단 주소값에만 의미를 두고, 포인터형은 나중에 정할 때 사용한다. 후에 메모리 동적할당과 연관이 있다.
*/
int SoSimpleAdder(int n1, int n2) {
    return n1 + n2;
}

int main(void) {
    int num = 20;
    void* ptr;

    ptr = &num;
    printf("num의 주소값 : %p, ptr의 값: %p \n", &num, ptr);
    // *ptr = 20; // 값의 변경을 시도하면 에러 발생
    // ptr++;     // 포인터연산을 시도하면 에러 발생

    ptr = SoSimpleAdder;
    printf("함수이름의 주소값 : %p, ptr의 값: %p \n", SoSimpleAdder, ptr);
    // printf("void 포인터로 함수 호출(= 값의 참조)을 하려고 하면 에러가 발생한다. \n", ptr(1, 2));

    return 0;
}