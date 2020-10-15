#include <stdio.h>

/**
* 예제 코드 설명: 선택정렬(SelectionSort)  예제
* 
* 1. 선택정렬은 최솟값을 찾아서 첫 번째부터 마지막 요소까지 순차적으로 정렬하는 알고리즘이다.
* 2. 선택정렬의 알고리즘 전략
*    ① 첫 번째 요소가 가장 작은 값이라 가정한다.
*    ② 두 번째 요소부터 마지막 요소까지 순차적으로 비교하여 최솟값을 찾는다.
*    ③ 최솟값이 위치한 요소와 첫 번째 요소의 위치를 변경한다.
* 
*    ④ 두 번째 요소가 가장 작은 값이라고 가정한다.
*    ⑤ 세 번째 요소부터 마지막 요소까지 순차적으로 비교하여 최솟값을 찾는다.
*    ⑥ 최솟값이 위치한 요소와 두 번째 요소의 위치를 변경한다.
* 
*    ⑦ 세 번째 요소가 가장 작은 값이라고 가정한다.
*    ⑧ 네 번째 요소부터 마지막 요소까지 순차적으로 비교하여 최솟값을 찾는다.
*    ⑨ 최솟값이 위치한 요소와 세 번째 요소의 위치를 변경한다.
* 
*    위의 세가지 과정이 반복됨을 알 수 있다. 이 과정은 정렬이 끝날 때까지 반복된다.
* 
* 3. 선택 정렬의 시간 복잡도
*    ① 비교연산에 의한 시간복잡도 : O(n^2)
*    ② 데이터 이동연산에 의한 시간복잡도: O(n)
*/

void SelectionSort(int arr[], int n)
{
    int i, j;
    int maxIdx;
    int temp;

    for (i = 0; i < n - 1; i++)
    {
        maxIdx = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[maxIdx])
                maxIdx = j;
        }

        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

int main()
{
    int arr[4] = {3, 2, 4, 1};
    int i;

    SelectionSort(arr, sizeof(arr) / sizeof(int));

    for (i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}