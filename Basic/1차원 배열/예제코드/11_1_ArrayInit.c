#include <stdio.h>

/*
* 예제 코드 설명: 배열의 초기화 3가지 방법 예제
*/
int main() {
	int arr1[5] = { 1, 2, 3, 4, 5 };            // (정석) 배열의 길이 선언, 길이에 맞춰 초기화
	int arr2[ ] = { 1, 2, 3, 4, 5, 6, 7 };      // 배열의 길이를 지정하지 않으면, 초기화의 길에 맞춰 자동으로 할당해준다.
	int arr3[5] = { 1, 2 };                     // 배열의 길이만큼 초기값이 주어지지 않으면, 나머지는 0으로 자동 초기화 된다.
	int arr1Len, arr2Len, arr3Len, i;

	printf("배열 arr1의 크기: %d \n", sizeof(arr1));
	printf("배열 arr2의 크기: %d \n", sizeof(arr2));
	printf("배열 arr3의 크기: %d \n", sizeof(arr3));

	arr1Len = sizeof(arr1) / sizeof(int);
	arr2Len = sizeof(arr2) / sizeof(int);
	arr3Len = sizeof(arr3) / sizeof(int);

	for (i = 0; i < arr1Len; i++)
		printf("%d ", arr1[i]);
	printf("\n");

	for (i = 0; i < arr2Len; i++)
		printf("%d ", arr2[i]);
	printf("\n");

	for (i = 0; i < arr3Len; i++)
		printf("%d ", arr3[i]);
	printf("\n");

	return 0;
}