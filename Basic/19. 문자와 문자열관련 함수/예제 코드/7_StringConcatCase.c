#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

/*
* 예제 코드 설명: strcat함수와 strncat함수 예제
* 
* 1. 문자열을 덧붙이기 위한 함수이다.
* 2. strcat함수, strncat함수의 주의점 : 배열크기가 충분히 할당 되지 않을 경우 널문자를 포함하지 않게 되어 컴파일 시 에러를 발생시킬 수 있다.
* 3. strcat함수, strncat함수의 차이 : strcat는 원문 그대로 덧붙이지만, strncat는 원하는 글자수만큼 가져다 붙일 수 있다.
* 4. strncat의 주의점: 8문자를 덧붙인다고 하면 실제로는 9문자가 덧붙여진다. 왜냐하면 널문자가 추가로 삽입되기 때문이다.
*/
int main(void) {
    char str1[20] = "First~";
    char str2[20] = "Second";

    char str3[20] = "Simple num: ";
    char str4[20] = "1234567890";

    strcat(str1, str2);
    puts(str1);

	strncat(str3, str4, 7); // 만약 8로 바꾸면 수용크기를 넘어가 널문자가 삽입되지 않아서 컴파일 실행시 오류가 발생한다.
    puts(str3);

    return 0;
}