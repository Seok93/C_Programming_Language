#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

/**
* 예제 코드 설명: 기수 정렬(Radix Sort)  예제
*
* 1. 기수 정렬은 정렬 순서를 비교하지 않고 정렬하는 방법이다.
* 2. 용어정리
*    ① 기수(Radix)란 주어진 데이터를 구성하는 기본 요소를 의미한다. (ex: 10진법은 0~9까지의 수로 구성되므로 0~9가 기본요소이자 기수이다.)
*    ② 버킷(Bucket)은 기수를 저장하기 위한 저장 공간이다. 보통 큐로 구현하여 저장한다.
* 3. 기수 정렬의 방법으로 LSD와 MSD가 존재한다.
*    ① LSD (Least Significant Digit): 덜 중요한 자릿수부터 정렬을 진행하는 방법으로, 일의 자리부터 비교해나가는 방법이다.
*    ② MSD (Most Significant Digit): 가장 중요한 자릿수부터 정렬을 진행하는 방법으로, 제일 높은 자릿수부터 비교해나가는 방법이다.
* 4. LSD는 일의 자리부터 기수를 분석하여 버킷에 담고, 버킷의 순서에 따라 출력하여 배열에 저장하는 방법으로 정렬을 한다.
*
* 5. 기수 정렬의 알고리즘 전략 (오름차순)
*    ① 타겟 숫자에서 일의 자리수의 숫자를 추출한다.
*    ② 추출한 일의 자리수의 기수를 판단하여 버킷에 저장한다. 모든 정렬 대상을 대상으로 진행한다.
*    ③ 버킷의 순서에 따라 데이터를 추출하여 배열에 저장한다.
*    ④ 정렬 대상중 가장 긴 데이터에 맞춰서 자릿수 비교를 한다. 
*    * 위의 과정이 끝나면 정렬이 완료된다.
*
* 6. 퀵 정렬의 시간 복잡도
*    ① 데이터 삽입과 추출의 빈도수에 의한 시간복잡도: O(n)
*/

void RadixSort(int arr[], int num, int maxLen)
{
    Queue buckets[BUCKET_NUM]; // 매개변수 maxLen에는 정렬 대상 중 가장 긴 데이터의 길이 정보가 전달
    int bi;                    // bucket index, 버킷
    int pos;                   // position, 자릿수
    int di;                    // digit, 10진수 숫자 기호
    int radix;                 // 각 position의 digit 저장
    int divfac = 1;

    // 총 10개의 버킷 초기화
    for (bi = 0; bi < BUCKET_NUM; bi++)
        QueueInit(&buckets[bi]);

    // 가장 긴 데이터의 길이만큼 반복
    for (pos = 0; pos < maxLen; pos++)
    {
        // 정렬 대상의 수만큼 반복
        for (di = 0; di < num; di++)
        {
            // N번째 자리의 숫자 추출
            radix = (arr[di] / divfac) % 10;

            // 추출한 숫자를 근거로 버킷에 데이터 저장
            Enqueue(&buckets[radix], arr[di]);
        }

        // 버킷 수만큼 반복
        for (bi = 0, di = 0; bi < BUCKET_NUM; bi++)
        {
            // 버킷에 저장된 것 순서대로 다 꺼내서 다시 arr에 저장
            while (!QIsEmpty(&buckets[bi]))
                arr[di++] = Dequeue(&buckets[bi]);
        }

        // N번째 자리의 숫자 추출을 위한 피제수의 증가
        divfac *= 10;
    }
}

int main()
{
    int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};

    int len = sizeof(arr) / sizeof(int);
    int i;

    RadixSort(arr, len, 5);

    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}