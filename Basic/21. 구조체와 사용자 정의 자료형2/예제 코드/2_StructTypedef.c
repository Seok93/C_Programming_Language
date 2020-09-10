#include <stdio.h>


/*
* 예제 코드 설명: typedef를 이용한 구조체 선언 방법 예제
*
* 1. typedef를 이용하여 구조체에도 별칭을 줄 수 있다.
*/
struct point {
	int xpos;
	int ypos;
};

typedef struct point Point;

typedef struct person {
	char name[20];
	char phone[20];
	int age;
} Person;

int main(void) {
	Point pos = {10, 20};
	Person man = { "이승기", "010-1234-5123", 21 };

	printf("%d %d \n", pos.xpos, pos.ypos);
	printf("%s %s %d \n", man.name, man.phone, man.age);

	return 0;
}
