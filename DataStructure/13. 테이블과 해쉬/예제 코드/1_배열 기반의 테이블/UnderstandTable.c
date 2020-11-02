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

void Input(EmpInfo *ei)
{
    printf("사번과 나이 입력: ");
    scanf("%d %d", &(ei->empNum), &(ei->age));
    ClearLineFromReadBuffer();
}

void Search(EmpInfo arr[], int size)
{
    int eNum;

    printf("확인하고픈 직원의 사번 입력: ");
    scanf("%d", &eNum);
    ClearLineFromReadBuffer();

    if (eNum > size || eNum < 0)
        return;

    printf("사번: %d, 나이: %d \n", arr[eNum].empNum, arr[eNum].age);
}

int main()
{
    EmpInfo empInfoArr[1000]; // 단순히 배열의 선언은 Table의 역할을 수행할 수 없음, Key를 통해 대상을 한 번에 찾을 수 있어야 한다. O(1)
    EmpInfo ei;
    char anwser;
    int eNum;

    while (TRUE)
    {
        Input(&ei);
        empInfoArr[ei.empNum] = ei;

        printf("계속 입력 받으시겠습니까? (Y/N):");
        scanf("%c", &anwser);
        ClearLineFromReadBuffer();

        if (anwser == 'N' || anwser == 'n')
            break;
    }

    Search(empInfoArr, sizeof(empInfoArr) / sizeof(EmpInfo));

    return 0;
}