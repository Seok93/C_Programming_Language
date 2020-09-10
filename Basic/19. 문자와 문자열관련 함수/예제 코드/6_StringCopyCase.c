#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

/*
* 예제 코드 설명: strcpy함수와 strncpy함수 예제
* 
* 1. 문자열의 복사를 위한 함수이다.
* 2. strcpy함수의 주의점 : 복사할 문자열보다 입력받을 문자열의 배열의 길이가 작지 않도록 주의해야한다.
* 3. strncpy함수의 주의점 : 복사할 문자열보다 입력받을 문자열의 배열의 길이가 작으면, 입력 받을 수 있을만큼 입력 받지만, 마지막에 널문자를 삽입해주지 않기에 인위적으로 넣어줘야한다.
*/
int main(void) {
    char str1[20] = "1234567890";
    char str2[20];
    char str3[5];

    /**** case 1 ****/
    strcpy(str2, str1);
    puts(str2);

    /**** case 2 ****/
     //strcpy(str3, str1); // 복사할 문자열 str1보다 복사받을 문자열의 배열의 길이가 작으므로 에러가 발생한다.
     //puts(str3);

    /**** case 3 ****/
    strncpy(str3, str1, sizeof(str3));  // 복사할 문자열보다 입력받을 문자열의 배열의 길이가 작으면, 입력 받을 수 있을만큼 입력 받지만 마지막에 널문자가 없다.
    puts(str3);

    /**** case 4 ****/
    strncpy(str3, str1, sizeof(str3)-1);    // 널문자를 강제삽입하기 위한 처리1
    str3[sizeof(str3) - 1] = 0;             // 널문자를 강제삽입하기 위한 처리2
    puts(str3);
    return 0;
}