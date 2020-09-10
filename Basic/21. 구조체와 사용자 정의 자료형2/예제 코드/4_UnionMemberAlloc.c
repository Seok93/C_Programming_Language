#include <stdio.h>


/*
* 예제 코드 설명: 공용체 선언방법과 의미 예제
*
* 1. 공용체의 선언 방법은 구조체의 선언방법과 같지만, 메모리적으로 의미하는 바가 다르다.
* 2. 구조체는 멤버변수만큼 메모리를 할당하여 각 멤버변수를 독립적으로 관리하지만, 공용체는 멤버변수중 가장큰 자료형의 크기만큼 메모리공간을 할당하고, 모든 멤버변수가 같은 메모리를 공유한다.
*/

typedef union ubox { // 공용체 정의
	int mem1;
	int mem2;
	double mem3;
} UBox;

typedef struct sbox { // 구조체 정의
	int mem1;
	int mem2;
	double mem3;
} SBox;

int main(void) {
	SBox sbx;
	UBox ubx;

	printf("구조체의 각 멤버별 메모리공간: %p %p %p \n", &sbx.mem1, &sbx.mem2, &sbx.mem3);	// 멤버변수 별로 메모리공간을 별도로 소유하고 있음을 알 수 있다.
	printf("공용체의 각 멤버별 메모리공간: %p %p %p \n", &ubx.mem1, &ubx.mem2, &ubx.mem3);	// 메모리공간을 공유하고 있음을 알 수 있다.

	return 0;
}
