#include <stdio.h>

/*
* 예제 코드 설명: fseek함수를 이용하여 파일 위치 지시자 이동 예제
*
* 1. fseek함수는 파일 위치 지시자를 이동시킬 때 사용하는 함수이다.
* 2. SEEK_SET: 파일의 맨 앞에서부터 이동 시작
* 3. SEEK_CUR: 현재 위치에서부터 이동 시작
* 4. SEEK_END: 파일의 맨 마지막(EOF)에서부터 이동 시작
* 5. fseek의 2번째 인자는 음수도 가능하며, 음수인 경우 왼쪽으로 이동이 이루어진다.
*/
int main(void) {
	/* 파일생성 */
	FILE* fp = fopen("text.txt", "wt");
	fputs("123456789", fp);
	fclose(fp);

	/* 파일 개방 */
	fp = fopen("text.txt", "rt");

	/* SEEK_END test */
	fseek(fp, -2, SEEK_END); // 
	putchar(fgetc(fp));

	/* SEEK_SET test */
	fseek(fp, 2, SEEK_SET);
	putchar(fgetc(fp));

	/* SEEK_CUR test */
	fseek(fp, 2, SEEK_CUR);
	putchar(fgetc(fp));

	return 0;
}
