#include <stdio.h>

/*
* 예제 코드 설명: fscanf함수를 통한 텍스트 데이터와 바이너리 데이터를 동시에 읽어들이기 예제
*
* 1. fscanf는 파일로부터 바이너리 데이터와 텍스트 데이터를 동시에 읽어들여 주는 함수이다.
* 2. scanf와 사용법은 똑같지만, 파일을 스트림을 대상으로써 첫번째 인자로 넘겨줘야한다.
* 3. fscanf함수는 파일의 끝에 도달하거나 오류가 발생하면 EOF를 반환한다.
*/
int main(void) {
	char name[10];
	char sex;
	int age;

	FILE* fp = fopen("friend.txt", "rt");
	int ret;

	while (1) {
		ret = fscanf(fp, "%s %c %d", name, &sex, &age);
		if (ret == EOF)	
			break;
		printf("%s %c %d \n", name, sex, age);
	}
	
	fclose(fp);
	return 0;
}
