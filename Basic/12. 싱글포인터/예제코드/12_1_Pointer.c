#include <stdio.h>

/*
* 예제 코드 설명:포인터의 역할, 포인터의 메모리 크기, 선언과 사용방법 등의 예제
*/
int main() {
	int num1 = 100;
	double num2 = 8.25;
	int * pnum1 = NULL;		// 포인터 변수는 반드시 초기화가 이루어져야 한다.
	double * pnum2 = NULL;
	
	pnum1 = &num1;			// &연산자를 통해 num1의 주소값을 pnum1에 저장하고 있다.
	pnum2 = &num2;

	printf("(int 자료형)             num1의 주소 : %p, num1의 메모리크기: %d, num1의 값: %d \n", &num1, sizeof(num1), num1);
	printf("(double 자료형)          num2의 주소 : %p, num2의 메모리크기: %d, num2의 값: %.2f \n", &num2, sizeof(num2), num2);

	// pnum1의 값과 num1의 주소값이 같다.	→ pnum1은 포인터로 주소값을 저장하기 때문에 일반 값을 출력하면 주소값이 나온다.
	// *pnum1의 값과 num1의 값이 같다.		→ *연산자는 참조하는 메모리공간에 저장된 값을 반환함으로 pnum1이 참조하는 num1의 값과 같다. 
	printf("(int 싱글포인터형)       pnum1의 주소 : %p, pnum1의 메모리크기: %d, pnum1의 값: %p, *pnum1의 값: %d, *pnum1의 주소: %p \n", &pnum1, sizeof(pnum1), pnum1, *pnum1, &(*pnum1));

	// pnum2의 값과 num2의 주소값이 같다.
	// *pnum2의 값과 num2의 값이 같다.
	printf("(double 싱글포인터형)    pnum2의 주소 : %p, pnum2의 메모리크기: %d, pnum2의 값: %p, *pnum2의 값: %.2f, *pnum2의 주소: %p \n", &pnum2, sizeof(pnum2), pnum2, *pnum2, &(*pnum2));

	return 0;
}