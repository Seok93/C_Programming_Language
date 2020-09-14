#include <stdio.h>

/*
* 예제 코드 설명: #ifdef...#endif 지시자를 통한 조건부 코드삽입 예제
*
* 1. #ifdef ...#endif 지시자를 통해 조건부 코드삽입이 가능하다. 
* 2. #ifdef ...#endif 지시자는 매크로가 정의되었는가 되어있지 않은가를 기준으로 동작한다.
*/

//#define ADD 1
#define MIN 0

int main(void) {
	int num1, num2;
	fputs("두 개의 정수 입력: ", stdout);
	scanf("%d %d", &num1, &num2);

#ifdef ADD	// 매크로 ADD가 정의 되었다면 실행
	printf("%d + %d = %d \n", num1, num2, num1+num2);
#endif

#ifdef MIN	// 매크로 MIN이 정의 되었다면 실행
	printf("%d - %d = %d \n", num1, num2, num1-num2);
#endif


	return 0;
}
