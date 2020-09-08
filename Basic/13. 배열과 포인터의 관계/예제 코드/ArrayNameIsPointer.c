#include <stdio.h>

/*
* 예제 코드 설명: 배열 이름도 포인터이기 때문에, 배열을 포인터처럼, 포인터를 배열처럼 사용할 수 있다.
*/
int main() {
	int arr[3] = {15,25, 35};
	int * ptr = arr;

	printf("포인터를 배열처럼 사용하기 \n");
	printf("%d %d \n", ptr[0], arr[0]);
	printf("%d %d \n", ptr[1], arr[1]);
	printf("%d %d \n", ptr[2], arr[2]);
	printf("\n");

	printf("배열을 포인터처럼 사용하기 \n");
	printf("%d %d \n", *(ptr+0), *(arr + 0));
	printf("%d %d \n", *(ptr+1), *(arr + 1));
	printf("%d %d \n", *(ptr+2), *(arr + 2));

    // 단, 위와 같이 배열의 이름을 포인터 변수처럼 사용하거나, 포인터 변수를 배열의 이름처럼 사용하는 일은 거의 없다.
    // 어디까지나 포인터와 배열의 관계를 이해하기 위한 예제이다.
    
	return 0;
}