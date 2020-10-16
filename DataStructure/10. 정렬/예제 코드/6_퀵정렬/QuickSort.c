#include <stdio.h>

/**
* 예제 코드 설명: 퀵 정렬(Quicl Sort)  예제
* 
* 1. 퀵 정렬은 분할 정복(Divide and Conquer)이라는 알고리즘 디자인 기법에 근거하여 만들어진 정렬 알고리즘이다.
* 2. 퀵 정렬의 용어 정리
*    ① pivot: 정렬을 진행하는데 필요한 일종의 기준이다. (pivot을 기준으로 left와 right의 값을 변경한다.)
*    ② left: 정렬 대상의 가장 왼쪽 지점
*    ③ right: 정렬 대상의 가장 오른쪽 지점
*    ④ low: 피벗을 제외한 가장 왼쪽에 위치한 지점
*    ⑤ high: 피벗을 제외한 가장 오른쪽에 위치한 지점
* 
* 3. 퀵 정렬의 알고리즘 전략 (오름차순)
*    ① pivot을 하나 정한다. (pivot은 개발자가 정하기 나름이지만, 중간 값을 정하는게 성능이 가장 좋다.)
*    ② low는 오른쪽으로, high는 왼쪽으로 이동하며, low는 pivot보다 정렬의 우선순위가 낮은 데이터를 만날 때까지, high는 pivot보다 정렬의 우선순위가 높은 데이터를 만날 때까지 이동한다.
*    ③ low와 high의 값을 교환해준다.
*    ④ 왼쪽에서 시작한 row가 오른쪽에서 시작한 high보다 커질 때까지 위의 작업을 반복한다. 
*    ⑤ (low > high)일 경우 high의 위치에 pivot을 놓아두고, pivot을 기준으로 왼쪽 영역과 오른쪽 영역을 다시 퀵정렬 함수에 넣어준다.(재귀적 특성 이용)
* 
* 4. 퀵 정렬의 시간 복잡도
*    ① 비교연산에 의한 시간복잡도: O(N*logN)
*/

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int low = left + 1;
    int high = right;

    while (low <= high)
    {
        while (pivot >= arr[low] && low <= right)
            low++;
        while (pivot <= arr[high] && high >= (left + 1))
            high--;

        if (low <= high)
            Swap(arr, low, high);
    }

    Swap(arr, left, high);
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}

int main()
{
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    int len = sizeof(arr) / sizeof(int);
    int i;

    QuickSort(arr, 0, len - 1);

    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}