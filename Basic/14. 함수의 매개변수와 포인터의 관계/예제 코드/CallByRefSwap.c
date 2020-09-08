#include <stdio.h>

/*
* 예제 코드 설명: Call-by-reference 예제
*/
void Swap(int* ptr1, int* ptr2) {	// 포인터를 통해 메모리주소에 직접 접근이 가능해진다. (= Call-by-reference)
	int temp;
	
	temp = *ptr1;	
	*ptr1 = *ptr2;	// 메모리에 직접 접근하여 수를 변경한다.
	*ptr2 = temp;
}

int main() {
	int num1 = 10;
	int num2 = 20;

	printf("num1: %d , num2: %d \n", num1, num2);
	Swap(&num1, &num2);
	printf("num1: %d , num2: %d \n", num1, num2);

	return 0;
}
