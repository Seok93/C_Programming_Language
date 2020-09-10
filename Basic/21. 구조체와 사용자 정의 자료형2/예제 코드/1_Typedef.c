#include <stdio.h>


/*
* 예제 코드 설명: typedef의 사용법과 의미 예제
*
* 1. typedef는 기존에 존재하는 자료형의 이름에 새이름을 부여하는 것을 목적으로한다. (별칭)
*/

typedef int INT;
typedef int* PTR_INT;

typedef unsigned int UINT;
typedef unsigned int* PTR_UINT;

typedef unsigned char UCHAR;
typedef unsigned char* PTR_UCHAR;

int main(void) {
	INT num1 = 120;
	PTR_INT pnum1 = &num1;

	UINT num2 = 190;
	PTR_UINT pnum2 = &num2;

	UCHAR ch = 'Z';
	PTR_UCHAR pch = &ch;

	printf("%d %u %c \n", *pnum1, *pnum2, *pch);

	return 0;
}
