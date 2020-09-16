#include <stdio.h>

/*
* 예제 코드 설명: 피보나치 수열 예제
* 
* 1. 피보나치 수열은 앞에 있는 2개의 숫자를 더해 현재의 수를 만들어가는 수열이다. 
* 2. 첫 번째와 두 번째 항의 수는 주어지고 시작한다. (0, 1)
* 3. 피보나치 예시 : 0 1 1 2 3 5 8 13 21 34 ....
*/
int Fibo(int n);

int main()
{
    int i;
    int range;

    printf("몇 번째 항까지 구하겠습니까? : ");
    scanf("%d", &range);

    for (i = 0; i < range; i++)
        printf("%d ", Fibo(i));

    return 0;
}

int Fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibo(n - 1) + Fibo(n - 2);
}