#include <stdio.h>

/*
* 예제 코드 설명: #if...#endif 지시자를 통한 조건부 코드삽입 예제
*
* 1. #if ...#endif 지시자를 통해 조건부 코드삽입이 가능하다. 
* 2. #if ...#endif 지시자는 조건이 참이면 코드가 실행되고, 아니면 생략한다.
*/

#define ADD 1
#define MIN 0

int main(void) {
	int num1, num2;
	fputs("두 개의 정수 입력: ", stdout);
	scanf("%d %d", &num1, &num2);

#if ADD
	printf("%d + %d = %d \n", num1, num2, num1+num2);
#endif

#if MIN
	printf("%d - %d = %d \n", num1, num2, num1-num2);
#endif


	return 0;
}
