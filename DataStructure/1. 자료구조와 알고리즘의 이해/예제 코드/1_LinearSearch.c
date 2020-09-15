#include <stdio.h>

/*
* 예제 코드 설명: 순차탐색(Linear Search) 알고리즘 예제
* 
* 1. 순차탐색 알고리즘은 맨 앞에서부터 순서대로 탐색을 진행하는 알고리즘이다.
* 2. 탐색알고리즘은 동등비교를 적게 수행하는게 좋은 알고리즘이다. 즉 탐색의 횟수가 알고리즘의 속도를 좌우한다.
* 3. 시간복잡도: 최악의 경우 인자의 개수 n만큼 수행하므로 T(n) = n의 시간복잡도를 가진다.
*/
int LinearSerach(int ar[], int len, int target) {	// 순차 탐색 알고리즘 적용된 함수
	int i;
	for (i = 0; i < len; i++) {
		if (ar[i] == target)
			return i;	// 찾은 대상의 인덱스 값 반환
	}
	return -1; // 찾지 못했음을 의미하는 값 반환(= EOF)
}

int main() {
	int arr[] = {3, 5, 2, 4, 0};
	int idx;

	idx = LinearSerach(arr, sizeof(arr)/sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	idx = LinearSerach(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}