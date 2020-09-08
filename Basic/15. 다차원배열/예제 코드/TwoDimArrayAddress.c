#include <stdio.h>

/*
* 예제 코드 설명: 다차원배열(2차원)의 메모리구조 예제
*/
int main(void) {
	int arr[3][2];
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			printf("%p \n", &arr[i][j]);	// 차원에 상관없이 메모리에 나란히 저장되어 있음을 알 수 있다. (메모리가 1차원구조이기 때문)
		}
	}
	return 0;
}