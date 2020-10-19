#include <stdio.h>
#include <stdlib.h>

/**
* 예제 코드 설명: 병합 정렬(Merge Sort)  예제
* 
* 1. 병합 정렬은 분할 정복(Divide and Conquer)이라는 알고리즘 디자인 기법에 근거하여 만들어진 정렬 알고리즘이다.
* 2. 병합 정렬의 알고리즘 전략
*    ① 모든 데이터는 우선 분할의 과정을 거치며, 요소가 한 개가 될 때까지 분할한다. (분할을 할 때에는 정렬을 고려하지 않고 그저 분할만 하면 된다.)
*    ② 분할이 완료되었다면 병합을 시작하는데, 병합을 할 때부터 정렬순서를 고려해서 묶는다.
*
* 3. 분할과 병합은 재귀적 성질을 가진다.    
* 
* 4. 병합 정렬의 시간 복잡도
*    ① 비교연산에 의한 시간복잡도: O(N*logN)
*    ② 데이터 이동연산에 의한 시간복잡도: O(N*logN)
*    * 정렬의 대상인 데이터의 수가 n개 일 때, 각 병합의 단계마다 최대 n번의 비교연산이 진행된다.
*    * 데이터의 수가 8개 일 땐 병합의 과정이 3번, 데이터의 수가 16개 일 땐 병합의 과정이4번이므로 logN에 따른다고 할 수 있다.
*    * 한 단계의 최대 비교연산 * 병합의 과정 = N * logN 
*/

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx = left;    // 왼쪽 영역의 시작 위치
    int rIdx = mid + 1; // 오른쪽 영역의 시작 위치
    int i;

    int *sortArr = (int *)malloc(sizeof(int) * (right + 1)); // 병합할 결과를 담을 배열 동적할당
    int sIdx = left;

    // 왼쪽 영역과 오른쪽 영역 둘 중 하나의 영역의 탐색이 끝날 때까지 반복
    while (fIdx <= mid && rIdx <= right)
    {
        // 병합할 두 영역의 데이터 비교후, 정렬순서대로 sortArr에 하나씩 삽입
        if (arr[fIdx] <= arr[rIdx])
            sortArr[sIdx++] = arr[fIdx++];
        else
            sortArr[sIdx++] = arr[rIdx++];
    }

    if (fIdx > mid)
    {
        // 왼쪽 영역의 탐색이 끝났다면, 오른쪽 영역의 데이터를 순차적으로 넣어준다.
        for (i = rIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    else
    {
        // 오른쪽 영역의 탐색이 끝났다면, 왼쪽 영역의 데이터를 순차적으로 넣어준다.
        for (i = fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }

    // 정렬한 데이터를 원본데이터에 저장
    for (i = left; i <= right; i++)
        arr[i] = sortArr[i];

    free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
    int mid;

    if (left < right)
    {
        // 영역의 중간 지점 계산
        mid = (left + right) / 2;

        // 둘로 나눠서 각각을 정렬 (재귀적 요소)
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // 정렬된 두 영역을 병합
        MergeTwoArea(arr, left, mid, right);
    }
}

int main()
{
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    int i;

    MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

    for (i = 0; i < 7; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}