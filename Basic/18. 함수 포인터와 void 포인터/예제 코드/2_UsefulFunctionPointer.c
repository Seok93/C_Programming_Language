#include <stdio.h>

/*
* 예제 코드 설명: 함수의 매개변수에 함수포인터를 선언하여 유용하게 사용하기 예제
*/

int WhoIsFirst(int age1, int age2, int (*cmp)(int, int)) {	
	return cmp(age1, age2);	// 넘겨받은 함수에 따라 다양하게 실행가능하다.
}

int OlderFirst(int age1, int age2) {
	if (age1 > age2)
		return age1;
	else if (age1 < age2)
		return age2;
	else
		return 0;
}

int YoungerFirst(int age1, int age2) {
	if (age1 < age2)
		return age1;
	else if (age1 > age2)
		return age2;
	else
		return 0;
}

int main(void) {
	int age1 = 20;
	int age2 = 30;
	int first;

	printf("입장 순서 1 \n");
	first = WhoIsFirst(age1, age2, OlderFirst);	// 전달 인자로 함수의 주소값을 넘겨주고 있다.
	printf("%d세와 %d세 중 %d가 먼저 입장! \n\n", age1, age2, first);

	printf("입장 순서 2 \n");
	first = WhoIsFirst(age1, age2, YoungerFirst);
	printf("%d세와 %d세 중 %d가 먼저 입장! \n\n", age1, age2, first);

	return 0;
}