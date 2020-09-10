#include <stdio.h>
#include <math.h>

/*
* 예제 코드 설명: 구조체의 멤버변수 중 포인터 변수 선언하기 예제
*
* 1. 구조체의 멤버변수로 배열, 포인터, 구조체 모두 가능하다.
*/
struct point {
	int xpos;
	int ypos;
};
struct circle {
	double radius;
	struct point* center;
};

int main(void) {
	struct point cen = {2, 7};
	double rad = 5.5;

	struct circle ring = { rad, &cen};
	printf("원의 반지름 : %g \n", ring.radius);
	printf("원의 중심 : [%d, %d] \n", (ring.center)->xpos, (*ring.center).ypos ); // 멤버변수의 포인터 접근형태 자세히 보기

	return 0;
}
