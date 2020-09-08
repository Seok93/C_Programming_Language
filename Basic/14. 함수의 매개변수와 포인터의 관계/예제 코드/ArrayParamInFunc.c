#include <stdio.h>

/*
* 예제 코드 설명: 함수 내부에서 전달받은 배열에 접근하는 방법
*/

void ShowArayElem(int* param, int len) {	// 배열을 통째로 받을 방법은 존재하지 않기 때문에, 배열의 시작주소와 배열의 길이를 통해 순차적으로 접근한다.
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", param[i]);
	printf("\n");
}
int main() {
	int arr1[3] = { 1, 2, 3 };
	int arr2[5] = { 4, 5, 6, 7, 8 };

	ShowArayElem(arr1, sizeof(arr1) / sizeof(int));
	ShowArayElem(arr2, sizeof(arr2) / sizeof(int));

	return 0;
}