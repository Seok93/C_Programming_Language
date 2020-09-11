#include <stdio.h>

/*
* 예제 코드 설명: fread, fwrite함수를 통한 바이너리 파일 복사 예제
* 
* 1. fread함수는 바이너리 파일로부터 데이터를 읽어들이는 함수이다.
* 2. fwrite함수는 파일에 바이너리 데이터를 쓰는 함수이다.
*/
int main(void) {
	FILE* src = fopen("src.bin", "rb"); // 파일로부터 읽어들이니 입력스트림이다.
	FILE* des = fopen("dst.bin", "wb"); // 파일에 데이터를 쓰기 위한 출력스트림이다.
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) { // 파일스트림 생성이 문제없이 되었다 확인
		puts("파일 오픈 실패!");
		return -1;
	}

	while (1) {
		readCnt = fread((void*)buf, sizeof(char), sizeof(buf), src);

		if (readCnt < sizeof(buf)) { // buf보다 작다는 것은 읽기 중 실패 또는 파일의 끝에 도달했다는 의미이다.
			if(feof(src) != 0) { // fread함수를 통해 정상적으로 파일의 끝에 도달했는지 확인
				fwrite((void*)buf, sizeof(char), readCnt, des); // 파일에서 읽어들인 마지막 데이터까지 확실하게 옮겨준다.
				puts("파일 복사 완료");
				break;
			}
			else {
				puts("파일 복사 실패");
			}
		}

		fwrite((void*)buf, sizeof(char), sizeof(buf), des);
	}

	fclose(src);
	fclose(des);
	return 0;
}
