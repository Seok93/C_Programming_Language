#include <stdio.h>

/*
* 예제 코드 설명: 함수 포인터 예제
* 
* 1. 함수의 이름은 주소값으로 변경이 불가능한 상수값이다.
* 2. 함수 포인터의 포인터형은 2가지를 신경쓰면 된다.
*   1) 반환형
*   2) 매개변수의 자료형과 개수
* 3. 반환형, 매개변수의 자료형과 개수 중 하나라도 다르면 같은 함수포인터형이 아니다.
* 4. 함수의 이름과 함수 포인터 변수의 차이는 상수냐 변수냐의 차이이다.
* 
*/
void SimpleAdder(int n1, int n2) {
	printf("%d + %d = %d \n", n1, n2, n1+n2);
}

void ShowString(char* str) {
	printf("%s \n", str); 
}

int main(void) {
	char* str = "Function Pointer";
	int num1 = 10, num2 = 20;

	void (*fptr1)(int, int) = SimpleAdder;	// 반환형은 void, 매개변수는 int형 2개를 갖는 함수의 주소를 저장할 수 있는 함수 포인터
	void (*fptr2)(char*) = ShowString;  // 반환형 void, 매개변수 char*형 1개를 갖는 함수의 주소를 저장할 수 있는 함수 포인터

	fptr1(num1, num2);
	fptr2(str);

	return 0;
}