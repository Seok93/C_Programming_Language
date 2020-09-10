#include <stdio.h>


/*
* 예제 코드 설명: 구조체의 중첩과 구조체의 유용성 예제
*
* 1. 구조체를 통해서 연관 있는 데이터를 하나로 묶을 수 있는 자료형을 정의하면, 데이터의 표현 및 관리가 용이해지고 그만큼 합리적인 코드를 작성할 수 있게 된다.
* 2. 구조체 안의 멤버변수로 구조체를 갖는 형태를 구조체의 중첩이라고 한다.
*/
typedef struct point {
	int xpos;
	int ypos;
} Point;

typedef struct circle {
	Point center;
	double rad;
} Circle;

void ShowCircleInfo(Circle* cptr) {
	printf("[%d, %d] \n", cptr->center.xpos, cptr->center.ypos); // 구조체 안의 구조체 멤버변수에 접근하는 방법
	printf("radius: %g \n\n", cptr->rad);
}

int main(void) {
	Circle c1 = { {1, 2}, 3.5 }; // 구조체의 중첩일 때에는 구조체 데이터를 중괄호를 묶어서 표현해도 된다.
	Circle c2 = { 2, 4, 3.9 };

	ShowCircleInfo(&c1);
	ShowCircleInfo(&c2);

	return 0;
}
