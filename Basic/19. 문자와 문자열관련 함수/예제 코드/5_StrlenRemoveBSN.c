#include <stdio.h>
#include <string.h>

/*
* 예제 코드 설명: strlen 함수 예제
* 
* 1. 문자열의 길이를 반혼하는 함수이다.
* 2. fgets는 \n까지 포함해서 읽어오기 때문에 불필요할시 인위적으로 제외할 수 있다.
*/

void RemoveBSN(char str[]) {
    int len = strlen(str);
    str[len - 1] = 0;
}

int main(void) {
    char str[100];

    printf("문자열 입력: ");
    fgets(str, sizeof(str), stdin);
    printf("길이: %d, 내용: %s \n", strlen(str), str);

    RemoveBSN(str);
    printf("길이: %d, 내용: %s \n", strlen(str), str);

    return 0;
}