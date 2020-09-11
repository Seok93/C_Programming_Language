#include <stdio.h>

/*
* 예제 코드 설명: fprintf함수를 통한 텍스트 데이터와 바이너리 데이터를 동시에 파일에 저장하기 예제
*
* 1. fprintf는 바이너리 데이터와 텍스트 데이터를 동시에 받아들여 파일에 출력이 가능하게 해주는 함수이다.
* 2. printf와 사용법은 똑같지만, 파일을 스트림의 대상으로써 첫번째 인자에 넘겨줘야한다.
* 3. scanf는 엔터 키의 입력을 읽어들이지 않고 입력버퍼에 남겨둔다.
*/
int main(void) {
	char name[10];
	char sex;
	int age;

	FILE* fp = fopen("friend.txt", "wt");
	int i;

	for (i = 0; i < 3; i++) {
		printf("이름 성별 나이 순 입력: ");
		scanf("%s %c %d", name, &sex, &age); // scanf함수는 엔터 키의 입력을 읽어들이지 않고 입력 버퍼에 남겨둔다.
		getchar(); // 버퍼에 남아있는 \n의 소멸을 위해서
		fprintf(fp, "%s %c %d", name, sex, age); // 텍스트/바이너리 데이터를 모두 텍스트 데이터로 만들어 저장한다.
	}

	fclose(fp);
	return 0;
}
