#include <stdio.h>

/*
* 예제 코드 설명: 널 문자의 역할
*/
int main() {
	char str[50] = "I like C programming";
	printf("문자열 출력: %s \n", str);

	str[8] = '\0';
	printf("문자열 출력: %s \n", str);	// str[8] 뒤에도 데이터가 들어가 있지만, 널 문자까지가 문자열로 인식됨을 알 수 있다.

	str[6] = 0;		// \0(널 문자)의 아스키 코드값은 0이기 때문에 같은 표기법이다.
	printf("문자열 출력: %s \n", str);

	str[1] = 0;
	printf("문자열 출력: %s \n", str);

	return 0;
}