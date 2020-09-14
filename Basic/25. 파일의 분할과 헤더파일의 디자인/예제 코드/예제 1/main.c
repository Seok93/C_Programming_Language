#include <stdio.h>
#include "basicArith.h"
#include "areaArith.h"
#include "roundArith.h"

/*
* 예제 코드 설명: 헤더파일과 소스파일 분리 예제
*/
int main(void) {
	printf("삼각형 넓이(밑변 4, 높이 2): %g \n", TriangleArea(4, 2));
	printf("원 넓이(반지름3): %g \n", CircleArea(3));

	printf("직사각형 둘레(밑변 2.5, 높이 5.2): %g \n", RectangleRound(2.5, 5.2));
	printf("정사각형 둘레(변의 길이 3): %g \n", SquareRound(3));
	return 0;
}
