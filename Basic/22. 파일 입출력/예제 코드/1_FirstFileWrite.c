#include <stdio.h>


/*
* 예제 코드 설명: 파일 출력스트림 예제
* 
*/
int main(void) {
	FILE* fp = fopen("data.txt", "wt"); // 파일 출력스트림 생성

	if (fp == NULL) {
		puts("파일 오픈 실패!");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);

	fclose(fp);	// 파일스트림은 운영체제에서 자동으로 관리해주지 않기 때문에 작업이 끝났다면 항상 인위적으로 닫아줘야한다. 

	return 0;
}
