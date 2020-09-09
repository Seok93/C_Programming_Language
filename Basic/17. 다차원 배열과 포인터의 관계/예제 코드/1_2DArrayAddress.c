#include <stdio.h>

/*
* 예제 코드 설명: 2차원배열의 배열이름(arr2d)와 각 행(arr2d[0], arr2d[1], arr2d[2])의 의미
* 
* 1. 2차원 배열의 배열이름의 의미
* 2. 2차원 배열의 각 행의 시작 주소와 행의 크기 계산법
*/
int main(void) {
	int arr2d[3][3];

	printf("%p \n", arr2d);			// 2차원 배열의 배열이름 arr2d는 첫번째 요소를 가리킨다.
	printf("%p \n", arr2d[0]);		// arr2d[0]은 첫 번째 행의 시작 주소를 가리킨다.
	printf("%p \n\n", &arr2d[0][0]);

	printf("%p \n", arr2d[1]);		// arr2d[1]은 두 번째 행의 시작 주소를 가리킨다.
	printf("%p \n\n", &arr2d[1][0]);

	printf("%p \n", arr2d[2]);		// arr2d[2]은 세 번째 행의 시작 주소를 가리킨다.
	printf("%p \n\n", &arr2d[2][0]);

	printf("sizeof(arr2d): %d \n", sizeof(arr2d));			// arr2d는 배열 전체를 대상으로 한다.
	printf("sizeof(arr2d[0]): %d \n", sizeof(arr2d[0]));	// arr2d[0], arr2d[1], arr2d[2]는 각 행을 대상으로 한다. 
	printf("sizeof(arr2d[1]): %d \n", sizeof(arr2d[1]));
	printf("sizeof(arr2d[2]): %d \n", sizeof(arr2d[2]));

	// arr2d와 arr2d[0]의 결과 값은 같지만, 의미하는 바는 다르다

	return 0;
}