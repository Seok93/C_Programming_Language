#include <stdio.h>

/*
* 예제 코드 설명: ftell을 통해 현재 파일 위치 지시자의 위치를 기억하도록 하는 예제
*
*/
int main(void) {
	long fpos;
	int i;

	/* 파일생성 */
	FILE* fp = fopen("text.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);

	/* 파일 개방 */
	fp = fopen("text.txt", "rt");

	for (i = 0; i < 4; i++) {
		putchar(fgetc(fp));
		fpos = ftell(fp);
		fseek(fp, -1, SEEK_END);
		putchar(fgetc(fp));
		fseek(fp, fpos, SEEK_SET);
	}
	fclose(fp);

	return 0;
}
