#include <stdio.h>

/*
* 예제 코드 설명: 문자 단위 입출력 함수 소개와 EOF의 이해 예제
* 
* 1. 문자 출력 함수 : putchar, fputc : 함수호출 성공시 쓰여진 문자정보가, 실패시 EOF 반환
*   1) putchar 함수는 표준 출력스트림으로 문자 하나를 전달한다. (only stdout)
*   2) fputc 함수는 지정한 출력 스트림으로 문자 하나를 전달한다. (stdout, file etc)
* 2. 문자 입력 함수 : getchar, fgetc
*   1) getchar 함수는 표준 입력 스트림에서 문자열 하나를 읽어들인다. (only stdin)
*   2) fgetc 함수는 지정한 입력 스트림에서 문자열 하나를 읽어들인다. (stdin, file)
* 3. EOF는 End Of File의 약자로 파일의 끝을 표현하기 위해 정의해 놓은 상수(-1)이다.
* 4. 엔터키는 아스키코드값이 10('\n')인 문자이다.
*/
int main(void) {
    int ch1, ch2; // 문자를 int에 받는 이유는 EOF가 반환될 수 있기 때문이다.

    ch1 = getchar();    // 표준 입력 스트림으로부터 문자 하나 입력
    ch2 = fgetc(stdin); // 지정한 입력 스트림으로부터 문자 하나 입력

    printf("ch1의 문자 : ");
    putchar(ch1);       // 표준 출력 스트림으로 문자 하나 출력
    printf("\n");

    printf("ch2의 문자 : ");
    fputc(ch2, stdout); // 지정한 출력 스트림으로 문자 하나 출력
    printf("\n");

    return 0;
}