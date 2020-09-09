#include <stdio.h>

/*
* 예제 코드 설명: 2차원 배열을 함수에 전달하는 방법 예제
* 
* 1. int (*arr)[4]와 int arr[][4]는 같은 표현이며, 2차원 배열을 받을 때 사용한다.
* 2. int arr[][4] 표현법은 매개변수에서만 사용할 수 있다.
* 3. sizeof(2차원 배열이름)은 전체 배열의 크기, sizeof(2차원 배열이름[0])은 한 행의 크기를 의미한다.
* 4. sizeof(2차원 배열이름)/sizeof(2차원 배열이름[0])은 행의 길이를 의미한다.
* 5. sizeof(2차원 배열이름[0])/sizeof(자료형)은 열의 길이를 의미한다.
*/
void ShowArr2DStyle(int (*arr)[4], int column) {  // int (*arr)[4]을 통해 int형 변수를 받는 2차원 배열을 전달받는다.
	int i, j;
	int row = sizeof(arr[0]) / sizeof(int);	// sizeof(arr[0]) / sizeof(int) = 한 행의 전체 크기 / 자료형의 크기 = 열의 길이

	for (i = 0; i < column; i++) {
		for (j = 0; j < row; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int Sum2DArr(int arr[][4], int column) { // int arr[][4]을 통해 int형 변수를 받는 2차원 배열을 전달받는다.
	int i, j, sum = 0;
	int row = sizeof(arr[0]) / sizeof(int);

	for (i = 0; i < column; i++) {
		for (j = 0; j < row; j++) {
			sum += arr[i][j];
		}
	}

	return sum;
}

int main(void) {
	int arr1[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr2[3][4] = {1, 1, 1, 1, 3, 3, 3, 3, 5, 5, 5, 5};

	ShowArr2DStyle(arr1, sizeof(arr1) / sizeof(arr1[0]));	// sizeof(arr1) / sizeof(arr1[0]) = 배열전체크기 / 한 행의 크기 = 행의 길이
	ShowArr2DStyle(arr2, sizeof(arr2) / sizeof(arr2[0]));
	printf("arr1의 합: %d \n", Sum2DArr(arr1, sizeof(arr1) / sizeof(arr1[0])));
	printf("arr2의 합: %d \n", Sum2DArr(arr2, sizeof(arr2) / sizeof(arr2[0])));

	return 0;
}