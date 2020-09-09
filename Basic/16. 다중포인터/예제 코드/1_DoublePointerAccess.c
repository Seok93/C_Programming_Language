#include <stdio.h>

/*
* 예제 코드 설명: 이중포인터의 사용 방법
*/
int main(void) {
	double num = 3.14;
	double* ptr = &num;		
	double** dptr = &ptr;	// 이중포인터는 싱글포인터의 주소값을 저장하기 위해 사용한다. (삼중포인터는 이중포인터를...)
	double* ptr2;

	printf("ptr주소값: %9p, *dptr의 주소값: %9p \n", ptr, *dptr);
	printf("num의 값: %9g, *ptr의 값: %9g, **dptr의 값: %9g \n", num, *ptr, **dptr);

	ptr2 = *dptr; // ptr2 = ptr과 같은 표현이다.
	*ptr2 = 10.99; // ptr과 ptr2가 같은 주소를 가지고 있으므로, ptr에서 접근해도 값이 같아진다.
	printf("num의 값: %9g, *ptr의 값: %9g, **dptr의 값: %9g \n", num, *ptr, **dptr);

	return 0;
}