#include <stdio.h>

/*
* 예제 코드 설명: 포인터를 이용한 문자열과 배열을 이용한 문자열의 차이
*/
int main() {
	char str1[] = "My String";
	char * str2 = "Your String";

	str2 = "Our String";
	printf("%s %s \n", str1, str2);

	str1[0] = 'X';	// 배열을 이용한 문자열은 변경이 가능하다.
	str2[0] = 'X';	// 포인터를 이용한 문자열은 변경이 불가능하다. 컴파일상 에러는 아니지만, 에러가 발생한다.
	printf("%s %s \n", str1, str2);

	return 0;
}