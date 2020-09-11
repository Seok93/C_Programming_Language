#include <stdio.h>

/*
* 예제 코드 설명: feof함수를 통한 문자열 단위 파일 복사 예제
* 
* 1. rt모드는 파일이 없으면 에러를 발생함으로 반드시 파일이 만들어두거나, 파일이 없으면 만들어주는 코드를 추가해줘야한다.
* 2. fgets함수는 문자열 단위로 읽어드리며, 파일의 끝에 도달하거나 함수호출 실패 시 NULL 포인터 반환한다.
* 3. feof함수는 파일의 끝을 확인해주는 함수로, fgets함수가 파일을 다 읽어서 NULL을 반환했는지, 무언가 문제가 있어서 NULL을 반환했는지 알수 있다.
*/
int main(void) {
	FILE* src = fopen("src.txt", "rt"); // 파일로부터 읽어들이니 입력스트림이다.
	FILE* des = fopen("dst.txt", "wt"); // 파일에 데이터를 쓰기 위한 출력스트림이다.
	char str[20];

	if (src == NULL || des == NULL) { // 파일스트림 생성이 문제없이 되었다 확인
		puts("파일 오픈 실패!");
		return -1;
	}

	while ( fgets(str, sizeof(str), src) != NULL) // NULL가 반환될 때까지 계속 읽어들임
		fputs(str, des);

	if (feof(src) != 0)	// feof함수는 파일이 끝에 도달해 있을 경우 0이 아닌 값을 반환한다.
		puts("파일복사 완료!");
	else
		puts("파일 복사 실패!");

	fclose(src);
	fclose(des);
	return 0;
}
