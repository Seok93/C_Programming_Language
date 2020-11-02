#include <stdio.h>

/*
*
* 예제 코드 설명 : 보간 탐색(Interpolation Search) 예제
*
* 1. 보간 탐색은 이진 탐색을 보완하여 만든 탐색 알고리즘이다.
* 2. 이진 탐색은 탐색 대상을 반씩 줄여가며 탐색하지만, 보간 탐색은  탐색 대상의 상대적 위치에 따라 앞이나 뒤부터 찾아 들어간다. 때문에 이진 탐색보다 좀 더 빠르게 대상을 찾는다.
* 3. 보간 탐색 알고리즘의 탐색 위치 판정 공식
*    s = ((double)(x-arr[low]) / (arr[high]-arr[low]) * (high-low)) + low  → s가 탐색 위치가 된다.
* 4. 소스코드로 구현하면, 이진탐색과 다른 점은 탐색 위치를 조정해 가는 부분과 탈출을 위한 조건문이 달라진다.
*/

int ISearch(int arr[], int first, int last, int target)
{
    int s;

    if (arr[first] > target || target > arr[last])
        return -1;

    s = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

    if (arr[s] == target)
        return s;
    else if (target < arr[s])
        return ISearch(arr, first, s - 1, target);
    else
        return ISearch(arr, s + 1, last, target);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
    if (idx == -1)
        printf("탐색 실패 \n");
    else
        printf("타겟 저장 인덱스: %d \n", idx);

    idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 10);
    if (idx == -1)
        printf("탐색 실패 \n");
    else
        printf("타겟 저장 인덱스: %d \n", idx);

    idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
    if (idx == -1)
        printf("탐색 실패 \n");
    else
        printf("타겟 저장 인덱스: %d \n", idx);

    return 0;
}