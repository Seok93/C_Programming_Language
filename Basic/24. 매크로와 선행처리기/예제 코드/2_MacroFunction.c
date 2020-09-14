#include <stdio.h>

/*
* 예제 코드 설명: #define을 이용한 매크로함수 예제
*
* 1. #define을 통해 함수와 유사하게 작동하도록 만들 수 있다. 그것을 매크로함수라고 한다.
* 2. 정의된 매크로 함수도 결국엔 매크로 몸체로 치환되는 것이기 때문에, 매크로함수의 전달 인자로 연산을 넣어두면 잘못된 결과를 출력할수도 있다.
*/

#define SQUARE(X)  X*X // 매크로함수

int main(void) {
	int num = 20;
	
	// 정상적인 결과 출력
	printf("Square of num: %d \n", SQUARE(num));
	printf("Square of -5: %d \n", SQUARE(-5));
	printf("Square of 2.5: %d \n", SQUARE(2.5));
	
	// 비정상적 결과 출력
	printf("Square of 3+2: %d \n", SQUARE(3 + 2));
	// 3+2를 연산한 후 연산한 결과를 가지고 함수를 호출해주는 것은 컴파일러이지, 선행처리가가 하는 역할이 아니다.
	// 위의 문장은 선핸처리기를 거친 후 아래와 같이 변경된다. (즉 단순 치환이다.)
	// printf("Square of 3+2: %d \n", 3 + 2 * 3 + 2);

	return 0;
}
