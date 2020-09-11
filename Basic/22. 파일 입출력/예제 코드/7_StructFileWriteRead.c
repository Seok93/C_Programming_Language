#include <stdio.h>

/*
* 예제 코드 설명: fread와 fwrite함수를 이용한 구조체 데이터의 파일 입출력 처리 예제
*
* 1. 구조체는 텍스트와 바이너리 데이터의 집합체이다.
* 2. 구조체 변수의 입출력엔 fread와 fwrite함수가 쓰인다. 두 종류의 데이터(바이너리, 텍스트)를 한 번에 저장하거나, 출력할 수 있다. 
*/
typedef struct fren {
	char name[10];
	char sex;
	int age;
}Friend;

int main(void) {
	FILE* fp;
	Friend myfren1;
	Friend myfren2;

	/*** file write with struct ***/
	fp = fopen("friend.bin", "wb");
	printf("이름, 성별, 나이 순 입력: ");
	scanf("%s %c %d", myfren1.name, &myfren1.sex, &myfren1.age);
	fwrite((void*)&myfren1, sizeof(myfren1), 1, fp);	// fwrite를 이용하여 구조체 변수 데이터를 바이너리 파일에 저장해준다.
	fclose(fp);

	/*** file read with struct ***/
	fp = fopen("friend.bin", "rb");
	fread((void*) &myfren2, sizeof(myfren2), 1, fp);	// fread를 이용하여 구조체 변수 데이터를 바이너리 파일로부터 읽어들인다.
	printf("%s %c %d", myfren2.name, myfren2.sex, myfren2.age);
	fclose(fp);

	return 0;
}
