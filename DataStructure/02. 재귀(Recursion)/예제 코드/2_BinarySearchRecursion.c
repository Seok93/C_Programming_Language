#include <stdio.h>

/*
* 예제 코드 설명: 이진탐색 알고리즘 예제
* 
* 1. 이진탐색을 사용하기 위한 조건: 탐색 대상이 정렬되어 있는 배열이어야 한다.
* 2. 이진탐색 알고리즘의 패턴
*   * 정렬되어 있는 배열의 중간 값을 찾는다.
*   * 탐색 대상과 중간 값을 비교한다.
*   * 탐색실패 조건: 탐색 범위의 시작위치를 의미하는 first와 탐색 위치의 끝을 의미하는 last보다 커지는 경우
*/
int BinarySearch(int arr[], int first, int last, int target)
{
    int mid;

    // 탈출 조건 선행
    if (first > last)
        return -1; // 데이터 탐색 실패

    mid = (last + first) / 2;

    if (target == arr[mid])
        return mid;
    else if (target < arr[mid])
        return BinarySearch(arr, first, last - 1, target);
    else
        return BinarySearch(arr, mid + 1, last, target);
}

int main()
{
    int arr[100];
    int target;
    int idx;
    int i;

    // 배열 초기화
    for (i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        arr[i] = (i * 2) + 1;
    }

    fputs("탐색할 숫자 입력: ", stdout);
    scanf("%d", &target);

    idx = BinarySearch(arr, 0, sizeof(arr) / sizeof(int) - 1, target);

    if (idx == -1)
        puts("탐색 실패");
    else
        printf("타겟 저장 인덱스: %d \n", idx);

    return 0;
}