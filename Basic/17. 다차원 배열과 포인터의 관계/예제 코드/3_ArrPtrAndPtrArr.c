#include <stdio.h>

/*
* 예제 코드 설명: 배열포인터와 포인터배열 예제
* 
* 1. 배열포인터는 포인터로 2차원 배열을 위한 특수한 포인터이다.
* 2. 포인터배열은 배열로 포인터를 저장하기 위한 배열이다.
*/
int main(void) {
	int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
	int arr2d[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int i, j;

	int* whoA[4] = { &num1, &num2, &num3, &num4 };	// 포인터 배열, 포인터 저장을 위한 배열
	int (*whoB)[4] = arr2d;	// 배열 포인터, 2차원 배열을 위한 포인터

	printf("%d %d %d %d \n", *whoA[0], *whoA[1], *whoA[2], *whoA[3]);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", whoB[i][j]);
		}
		printf("\n");
	}

	return 0;
}