#include <stdio.h>

/*
* 예제 코드 설명: 배열의 인덱스 범위를 벗어났을 때 예제
*/
int main() {
	int oneDimArr[4] = { 1, 2, 3, 4 };

	// oneDimArr의 배열의 길이는 4이므로, i의 범위를 4로 설정하는게 맞지만, 일부로 범위를 벗어나게 설정
	for (int i = 0; i < 5; i++) {
		printf("%d번째 값 : %d \n", i + 1, oneDimArr[i]);
	}

	return 0;
}