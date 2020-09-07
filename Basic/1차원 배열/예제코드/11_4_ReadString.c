#include <stdio.h>

/*
* 예제 코드 설명: 문자열 입력과 널 문자의 활용 예제
*/
int main() {
	char str[50];
	int idx = 0;

	printf("문자열 입력: ");
	scanf_s("%s", str, sizeof(str)/sizeof(char));	// 참고로 scanf 계열의 함수는 공백을 기준으로 데이터를 구분하기 때문에, 문자열 입력에 적합하지 않다.
	printf("입력 받은 문자열: %s \n", str);

	printf("문자 단위 출력: ");
	while (str[idx] != '\0') {  // 널 문자를 통해 문자열의 끝을 판단한다.
		printf("%c", str[idx]);
		idx++;
	}
	printf("\n");

	return 0;
}