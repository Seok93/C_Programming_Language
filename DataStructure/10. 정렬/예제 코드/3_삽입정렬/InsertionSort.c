#include <stdio.h>

/**
* 예제 코드 설명: 삽입정렬(Insertion Sort)  예제
* 
* 1. 삽입정렬은 정렬 대상을 2부분으로 나눠서, 정렬안된 부분에 있는 데이터를 정렬된 부분의 특정 위치에 삽입해 가면서 정렬을 진행하는 알고리즘이다.
* 2. 삽입정렬의 알고리즘 전략
*    ① 정렬이 완료된 영역의 다음에 위치한 데이터가 그 다음 정렬대상이다.
*    ② 정렬대상이 정렬이 완료된 영역의 요소들과 하나씩 비교하며 자기가 정렬될 위치를 찾는다. (비교하여 데이터를 한 칸씩 뒤로 밀면서 위치를 찾는다.)
* 
*    위의 과정이 반복되면 데이터가 정렬된다.
* 
* 3. 삽입 정렬의 시간 복잡도
*    ① 비교연산에 의한 시간복잡도- 최선의 경우: O(0) 최악의 경우: O(n^2)
*    ② 데이터 이동연산에 의한 시간복잡도- 최선의 경우: O(0) 최악의 경우: O(n^2)
*/

void InsertionSort(int arr[], int n)
{
    int i, j;
    int insData;

    for (i = 1; i < n; i++)
    {
        insData = arr[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > insData)
                arr[j + 1] = arr[j];
            else
                break;
        }

        arr[j + 1] = insData;
    }
}

int main()
{
    int arr[4] = {3, 2, 4, 1};
    int i;

    InsertionSort(arr, sizeof(arr) / sizeof(int));

    for (i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}