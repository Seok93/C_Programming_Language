#include <stdio.h>

/*
* 예제 코드 설명: &연산자와 *연산자의 역할
*/
int main() {
	int num1 = 100, num2 = 200;
	int * pnum;

	pnum = &num1;	// 포인터변수 pnum에 &연산자를 이용하여 num1의 주소값을 저장
	*pnum += 30;	// *연산자를 이용하여, 참조중인 num1의 값을 변경, num1 += 30; 과 동일하다.

	pnum = &num2;	// 포인터변수 pnum에 &연산자를 이용하여 num2의 주소값을 저장
	*pnum -= 30;	// *연산자를 이용하여, 참조중인 num2의 값을 변경, num2 -= 30; 과 동일하다.

	printf("num1: %d, num2: %d \n", num1, num2);

	return 0;
}