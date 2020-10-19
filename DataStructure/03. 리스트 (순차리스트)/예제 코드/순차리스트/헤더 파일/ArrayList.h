#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1  // '참'을 표현하기 위한 매크로 정의
#define FALSE 0 // '거짓'을 표현하기 위한 매크로 정의

/*** ArrayList의 정의 ****/
#define LIST_LEN 100
typedef int LData;

typedef struct __ArrayList // 배열기반 리스트를 정의한 구조체 (= 순차리스트)
{
    LData arr[LIST_LEN]; // 순차리스트 저장소인 배열
    int numOfData;       // 저장된 데이터의 수
    int curPosition;     // 현재 데이터 참조 위치
} ArrayList;

/*** ArrayList와 관련된 연산들 ****/
typedef ArrayList List;

void ListInit(List *plist);            // 초기화
void LInsert(List *plist, LData data); // 데이터저장

int LFirst(List *plist, LData *pdata); // 첫 번째 데이터 참조
int LNext(List *plist, LData *pdata);  // 다음 데이터 참조

LData LRemove(List *plist); // 최근에 참조한 데이터 삭제
int LCount(List *plist);    // 저장된 데이터의 수 반환

#endif