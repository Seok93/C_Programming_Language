#include <stdio.h>

/*
* 예제 코드 설명: 입력버퍼 flush 구현 예제
* 
* 1. 출력버퍼는 fflush함수로 비워낼 수 있지만, 입력버퍼의 flush함수는 제공하고 있지 않기 때문에 따로 구현할 필요가 있다.
* 2. 상황에 따라 다르겠지만, 가급적 fgets함수가 끝날 때마다 넣어주는게 좋다.
*/
void ClearLineFromReadBuffer(void) {
    while (getchar() != '\n');  // 입력버퍼 비우기
}

int main(void) {
    char perID[7];
    char name[10];

    fputs("주민 번호 앞 6자리 입력: ", stdout);
    fgets(perID, sizeof(perID), stdin);
    ClearLineFromReadBuffer();

    fputs("이름 입력: ", stdout);
    fgets(name, sizeof(name), stdin);
    ClearLineFromReadBuffer();

    printf("주민번호: %s \n", perID);
    printf("이름: %s \n", name);

    return 0;
}