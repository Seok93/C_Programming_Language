#include <stdio.h>

/*
* 예제 코드 설명: 포인터배열의 이해 예제
*/
int main(void) {
	int num1 = 10, num2 = 20, num3 = 30;
	int* ptr1 = &num1;	// ptr1은 싱글포인터
	int* ptr2 = &num2;
	int* ptr3 = &num3;

	int* ptrArr[3] = { ptr1, ptr2, ptr3 };	// ptrArr는 이중포인터, 배열의 차원 수+ 포인터 *의개수 = 1 + 1 = 더블포인터
	int** dptr = ptrArr;

	printf("%d %d %d \n", *ptrArr[0], *ptrArr[1], *ptrArr[2]);
	// 위와 같은 표현법, printf("%d %d %d \n", **(ptrArr + 0), **(ptrArr + 1), **(ptrArr + 2));

	printf("%d %d %d \n", *dptr[0], *dptr[1], *dptr[2]);
	// 위와 같은 표현법, printf("%d %d %d \n", **(dptr+0), **(dptr + 1), **(dptr + 2));

	return 0;
}