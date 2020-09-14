#include <stdio.h>

/*
* 예제 코드 설명: #elif, #else를 통한 분기 실행 예제
*
* 1. #if, #ifdef, #ifndef 지시자는 #elif, #else를 이용하여 조건 분기실행이 가능하다.
*/

#define HIT_NUM 7

int main(void) {
#if HIT_NUM==5
	printf("매크로 상수 HIT_NUM은 현재 5입니다.");
#elif HIT_NUM==6
	printf("매크로 상수 HIT_NUM은 현재 6입니다.");
#elif HIT_NUM==7
	printf("매크로 상수 HIT_NUM은 현재 7입니다.");
#else
	printf("매크로 상수 HIT_NUM은 5, 6, 7은 확실히 아닙니다.");
#endif


	return 0;
}
