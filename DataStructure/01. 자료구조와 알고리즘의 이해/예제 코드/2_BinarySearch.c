#include <stdio.h>

/*
* 예제 코드 설명: 이진탐색(BinarySearch) 알고리즘 예제
*
* 1. 순차탐색 알고리즘을 적용하기에 앞서 '배열에 저장된 데이터는 정렬되어 있어야 한다'라는 조건을 충족해야한다.
* 2. 이진탐색 알고리즘은 주어진 데이터를 2등분해서 찾는 데이터가 어느 그룹에 속해있는지 정하고, 나머지 그룹은 버리면서 탐색한다. (탐색 대상을 계속 반씩 줄여나간다.)
* 3. 데이터를 찾았거나 first가 last보다 큰 경우 탐색은 종료되며, 후자의 경우를 탐색에 실패 했음을 뜻한다.
* 4. 시간복잡도: 최악의 경우 log(2)N+1이므로 시간복잡도 Q(n) = log(2)N이다. 로그적으로 증가한다는 사실이 중요하다.
*/
int BinarySearch(int ar[], int len, int target) {
	int first = 0;      // 탐색 대상의 시작 인덱스 값
	int last = len - 1; // 탐색 대상의 마지막 인덱스 값
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;   // 탐색 대상의 중앙을 찾는다.

		if (target == ar[mid]) {    // 중앙에 저장된 값이 타겟이라면
			return mid;             // 탐색 완료
		}else {
			if (target < ar[mid])   // 타겟이 아니라면 탐색 대상을 반으로 줄인다.
				last = mid - 1;     // mid값은 더이상 탐색 대상이 아니므로 index 이동 (중요)
			else
				first = mid + 1;
		}
	}

	return -1; // 찾지 못했을 때 반환 되는 값 -1(= EOF)
}

int main() {
	int arr[] = {1, 3, 5, 7, 9};
	int idx;

	idx = BinarySearch(arr, sizeof(arr)/sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	idx = BinarySearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}