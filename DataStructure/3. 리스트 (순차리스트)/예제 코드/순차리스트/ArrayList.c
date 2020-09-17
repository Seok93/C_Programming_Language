#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
    (plist->numOfData) = 0;    // 리스트에 저장된 데이터의 수는 0
    (plist->curPosition) = -1; // 현재 아무 위치(idx)도 가리키지 않음
}

void LInsert(List *plist, LData data)
{
    if (plist->numOfData > LIST_LEN) // 배열의 저장공간 확인
    {
        puts("저장이 불가능합니다.");
        return;
    }

    plist->arr[plist->numOfData] = data; // 받은 데이터 저장
    (plist->numOfData)++;                // 저장된 데이터의 수 증가
}

int LFirst(List *plist, LData *pdata)
{
    if (plist->numOfData == 0) // 저장된 데이터가 없다면
        return FALSE;

    (plist->curPosition) = 0; // 참조 위치의 초기화, 첫 번째 데이터의 참조
    *pdata = plist->arr[0];   // pdata가 가리키는 메모리에 첫 번째 데이터 저장
    return TRUE;
}

int LNext(List *plist, LData *pdata)
{
    if (plist->curPosition >= (plist->numOfData) - 1) // 더이상 참조할 데이터가 없다면
        return FALSE;

    (plist->curPosition)++;                  // 다음 데이터로 참조 위치 변경
    *pdata = plist->arr[plist->curPosition]; // 다음 데이터를 pdata가 가리키는 메모리에 저장
    return TRUE;
}

LData LRemove(List *plist)
{
    int rpos = plist->curPosition; // 삭제할 데이터의 인덱스 값 참조
    int num = plist->numOfData;    // 삭제 전 저장된 데이터의 수
    int i;
    LData rdata = plist->arr[rpos]; // 삭제할 데이터를 임시로 저장

    // ↓ 리스트는 데이터를 순차적으로 저장해야함으로 데이터 삭제 후, 뒤에 저장된 데이터 들을 한 칸 씩 앞으로 이동시켜서 그 빈 공간을 메운다.
    for (i = rpos; i < num - 1; i++)
        plist->arr[i] = plist->arr[i + 1];

    (plist->numOfData)--;   // 저장된 데이터의 수 감소
    (plist->curPosition)--; // 참조 위치를 하나 되돌린다.
    return rdata;           // 삭제된 데이터 반환
}

int LCount(List *plist)
{
    return plist->numOfData;
}