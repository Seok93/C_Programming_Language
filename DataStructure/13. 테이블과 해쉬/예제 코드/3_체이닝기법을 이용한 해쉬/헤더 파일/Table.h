#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"
#include "DLinkedList.h"

#define MAX_TBL 100

typedef int HashFunc(Key k);
typedef struct _table
{
    List tbl[MAX_TBL];
    HashFunc *hf;
} Table;

void TBLInit(Table *pt, HashFunc *f);      // 테이블 초기화
void TBLInsert(Table *pt, Key k, Value v); // 테이블에 키와 값을 저장
Value TBLDelete(Table *pt, Key k);         // 키를 근거로 테이블에서 데이터 삭제
Value TBLSearch(Table *pt, Key k);         // 키를 근거로 테이블에서 데이터 탐색

#endif
