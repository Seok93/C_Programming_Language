#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct _empInfo
{
    int empNum; // 직원의 고유번호	: Table Key
    int age;    // 직원의 나이		: Table Value
} EmpInfo;

void ClearLineFromReadBuffer()
{
    while (getchar() != '\n')
        ;
}

int GetHashValue(int empNum)
{
    return empNum % 1000; // 이 방법으로 해쉬를 적용하면, 해쉬값 충돌이라는 문제가 발생한다.
}

void Input(EmpInfo *ei)
{
    printf("사번과 나이 입력: ");
    scanf("%d %d", &(ei->empNum), &(ei->age));
    // 사원번호: 20120003, 나이: 42 입력
    // 사원번호: 20120012, 나이: 33 입력
    // 사원번호: 20120049, 나이: 27 입력
    ClearLineFromReadBuffer();
}

void Search(EmpInfo arr[], int size)
{
    int eNum, hNum;

    printf("확인하고픈 직원의 사번 입력: ");
    scanf("%d", &eNum);
    ClearLineFromReadBuffer();

    hNum = GetHashValue(eNum);
    printf("사번: %d, 나이: %d \n", arr[hNum].empNum, arr[hNum].age);
}

int main()
{
    EmpInfo empInfoArr[1000]; // 테이블 방식으로 저장한다면, 인덱스의 범위가  엄청 넓어야할 때도 있고, 특정 key(ex 사원번호)에 따라 사용하는 인덱스 범위만 적용하기가 쉽지 않다.
    EmpInfo ei;
    char anwser;
    int eNum;

    while (TRUE)
    {
        Input(&ei);
        // key(사원번호)를 인덱스 값으로 이용해서 저장
        empInfoArr[GetHashValue(ei.empNum)] = ei;

        printf("계속 입력 받으시겠습니까? (Y/N):");
        scanf("%c", &anwser);
        ClearLineFromReadBuffer();

        if (anwser == 'N' || anwser == 'n')
            break;
    }

    Search(empInfoArr, sizeof(empInfoArr) / sizeof(EmpInfo));

    return 0;
}
