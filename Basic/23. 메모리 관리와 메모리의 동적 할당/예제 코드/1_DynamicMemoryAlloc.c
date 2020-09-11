#include <stdio.h>
#include <stdlib.h>

/*
* 예제 코드 설명: malloc과 free함수를 이용한 메모리 동적 할당 예제
*
* 1. malloc 함수를 통해 힙 영역의 메모리공간을 할당받아 사용할 수 있다. (= 메모리 동적할당)
* 2. free 함수를 이용하여 힙 영역의 메모리공간을 해제할 수 있다.
* 3. malloc함수는 void*형 주소값을 반환하기 때문에 포인터형 변환을 해줄 필요가 있다.
*/
int main(void) {
	int* ptr1 = (int*)malloc(sizeof(int));
	int* ptr2 = (int*)malloc(sizeof(int) * 7); // malloc은 void*형 주소값을 반환하기 때문에, 포인터 형변환을 통해 메모리공간의 해석법을 제공해야한다.
	int i;

	*ptr1 = 20;
	for (i = 0; i < 7; i++)
		ptr2[i] = i + 1; // 힙 영역의 메모리공간을 순차적으로 접근한다.

	printf("%d \n", *ptr1);
	for (i = 0; i < 7; i++)
		printf("%d ", ptr2[i]);

	free(ptr1);
	free(ptr2);

	return 0;
}
