#include <stdio.h>

/**
* 예제 코드 설명: 버블정렬(BubbleSort)  예제
* 
* 1. 버블정렬은 인접한 두 개의 데이터를 비교해가면서 정렬을 진행하는 정렬 알고리즘이다.
* 2. 버블정렬의 알고리즘 전략 (오름차순일 경우)
*    ① 첫번째 요소부터 인접한 데이터를 비교하여, 정렬 순서상 위치가 바뀌어야하는 경우 두 데이터의 위치를 바꾼다.  
*    ② 정렬이 완료된 배열의 끝에 위치한 데이터를 제외하고 나머지를 대상으로 비교와 교환을 다시 진행한다.
* 
*    위의 과정이 반복되면 데이터가 정렬된다.
* 
* 3. 버블 정렬의 시간 복잡도
*    ① 비교연산에 의한 시간복잡도 : O(n^2)
*    ② 데이터 이동연산에 의한 시간복잡도: O(n^2)
*/

void BubbleSort(int arr[], int n)
{
    int i, j;
    int temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - i) - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[4] = {3, 2, 4, 1};
    int i;

    BubbleSort(arr, sizeof(arr) / sizeof(int));

    for (i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}