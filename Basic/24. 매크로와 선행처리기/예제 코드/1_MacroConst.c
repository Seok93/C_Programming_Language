#include <stdio.h>

/*
* 예제 코드 설명: #define을 이용한 매크로상수 예제
*
* 1. 선행처리 명령문은 세부분으로 구성된다. (지시자, 매크로, 매크로몸체)
* 2. 코딩을 할 때엔 매크로를 통해 명시하여 사용하지만, 선행처리기를 거칠 때에는 매크로 부분이 매크로 몸체 부분으로 치환된다.
* 3. 매크로의 이름은 대문자로 정의하는 것이 일반적이며 복수의 단어로 이루어질 경우 _를 통해 표현한다.
* 4. 매크로 몸체에는 함수의 연산이 들어가도 된다.
*/

#define NAME "홍길동"	
#define AGE 24
#define PRINT_ADDR puts("주소: 경기도 용인시\n");

int main(void) {
	printf("이름: %s \n", NAME); // NAME이라는 부분을 "홍길동"으로 치환해준다.
	printf("나이: %d \n", AGE);
	PRINT_ADDR;

	return 0;
}
