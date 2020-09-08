#include <stdio.h>

/*
* 예제 코드 설명: 배열 이름에 포인터 연산자(*)를 사용하여 연산해보기
*/
int main() {
	int arr1[3] = {1, 2, 3};
	double arr2[3] = {1.1, 2.2, 3.3};

	printf("%d %g \n", *arr1, *arr2);		// 배열 이름은 상수 형태의 포인터이므로, 포인터 연산자 *를 사용할 수 있다.
	*arr1 += 100;
	*arr2 += 120.5;
	printf("%d %g \n", arr1[0], arr2[0]);

	return 0;
}