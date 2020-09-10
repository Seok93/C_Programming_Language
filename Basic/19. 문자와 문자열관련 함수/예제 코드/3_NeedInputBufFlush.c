#include <stdio.h>

/*
* 예제 코드 설명: fgets의 문제점과 입력버퍼 flush의 필요성 예제
* 
* 1. fgets은 엔터키(\n)까지 문자를 읽어드리는데, 입력버퍼에 \n이 남아있다면 바로 종료되는 문제가 있다. 때문에 입력 버퍼를 강제로 비워줄 필요가 있다.
*/
int main(void) {
    char perID[7];
    char name[10];

    fputs("주민 번호 앞 6자리 입력: ", stdout);
    fgets(perID, sizeof(perID), stdin);

    fputs("이름 입력: ", stdout);
    fgets(name, sizeof(name), stdin);

    printf("주민번호: %s \n", perID);
    printf("이름: %s \n", name);

    return 0;
}