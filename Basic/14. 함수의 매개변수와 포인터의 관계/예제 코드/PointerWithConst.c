#include <stdio.h>

/*
* 예제 코드 설명: 포인터에서 const 키워드 위치에 따른 의미 예제
*/

int main() {
	int num1 = 10, num2 = 20;
	const int* ptr1 = &num1; // ptr1이 가리키는 변수에 저장된 값을 변경하는 것을 불허한다.
	int* const ptr2 = &num1; // ptr2에 저장된 주소값을 변경하는 것을 불허한다.

	// 포인터형 앞 const의 의미
	printf("ptr1을 통한 값 변경 전: %d \n", *ptr1);
	// *ptr1 += 2; // ptr1을 통해 가리키는 변수의 값을 변경하려고 했기에 컴파일 에러발생
	printf("ptr1을 통한 값 변경 후: %d \n", *ptr1);



	// 포인터 변수명 앞 const의 의미
	printf("ptr2에 저장된 주소값 변경 전: %d \n", *ptr1);
	// ptr2 = &num2; // ptr2에 저장된 주소값을 변경하려고 했기에 컴파일 에러 발생
	printf("ptr2에 저장된 주소값 변경 후: %d \n", *ptr1);

	return 0;
}