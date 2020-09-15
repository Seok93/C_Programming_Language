#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_LEN 20
#define LIST_LEN 30

#define DATA_FILE "BookList.txt"

typedef struct book {
	char auth[CHAR_LEN];
	char phone[CHAR_LEN];
} Book;

// 문자열과 버퍼를 위한 유틸리티 관련 함수
void ClearLineBuffer();
void ChangeNullString(char* const target);

// 데이터 파일 입・출력 관련 함수
void ReadData(Book** const list);
void WriteData(Book** const list);

// 프로그램 메뉴 관련 함수
void PrintfMene();
void ChooseItem(int* item);

// 프로그램 기능 관련 함수
void InsertData(Book** const list);
void DeleteData(Book** const list);
void SearchData(Book** const list);
void PrintfAll(Book** const list);
void SaveAndExit(Book** const list);

int main(void) {
	Book* list[LIST_LEN] = { 0 };
	int item = 0;
	int i;

	ReadData(list);

	while(1) {
		PrintfMene();
		ChooseItem(&item);

		switch (item) {
		case 1:
			InsertData(list);
			break;
		case 2:
			DeleteData(list);
			break;
		case 3:
			SearchData(list);
			break;
		case 4:
			PrintfAll(list);
			break;
		case 5:
			SaveAndExit(list);
			break;
		default:
			puts("Please choose item within the range.");
		}
		printf("\n");
	}

	for (i = 0; i < LIST_LEN; i++)
		free(list[i]);

	return 0;
}

/*
* 표준입력스트림 버퍼 fflush
*/
void ClearLineBuffer() {
	while (getchar() != '\n');
}

/*
* 문자열 마지막 부분을 널문자로 치환
*/
void ChangeNullString(char* const target) {
	target[strlen(target) - 1] = 0;
}

/*
* 파일로부터 데이터 읽어오기
*/
void ReadData(Book** const list) {
	int i = 0;
	int ret;
	Book readBuf;
	Book* data = NULL;
	FILE* fp = NULL;
	
	// 데이터 파일 읽어오기
	fp = fopen(DATA_FILE, "rt");
	if (fp == NULL) {
		puts("Failed to open file...");
		exit(0);
	}

	while (1) {
		
		ret = fscanf(fp, "%s %s ", readBuf.auth, readBuf.phone);

		if (ret == EOF) break;

		data = (Book*)malloc(sizeof(Book) * 1);
		strcpy(data->auth, readBuf.auth);
		strcpy(data->phone, readBuf.phone);
		list[i++] = data;
	}

	fclose(fp);
}

/*
* 데이터를 파일에 저장
*/
void WriteData(Book** const list) {
	int i;
	FILE* fp = fopen(DATA_FILE, "wt");

	if (fp == NULL) {
		puts("Failed to open file...");
		exit(0);
	}

	for (i = 0; i < LIST_LEN; i++) {
		if (list[i] == NULL) continue;
		fprintf(fp, "%s %s ", list[i]->auth, list[i]->phone);
	}

	fclose(fp);
}

/*
* 메뉴출력
*/
void PrintfMene() {
	puts("***** Menu *****");
	puts("1. Insert");
	puts("2. Delete");
	puts("3. Search");
	puts("4. Print All");
	puts("5. Exit");
}

/*
* 메뉴 선택
*/
void ChooseItem(int* item) {
	fputs("Choose the item: ", stdout);
	scanf("%d", item);
	ClearLineBuffer();
}

/*
* 데이터 삽입
*/
void InsertData(Book** const list) {
	int i;

	for (i = 0; i < LIST_LEN; i++) {
		if (list[i] != NULL) continue;

		list[i] = (Book*)malloc(sizeof(Book) * 1);

		puts("[Insert]");
		fputs("Input Name: ", stdout);
		fgets(list[i]->auth, CHAR_LEN, stdin);
		ChangeNullString(list[i]->auth);

		fputs("Input Tel Number: ", stdout);
		fgets(list[i]->phone, CHAR_LEN, stdin);
		ChangeNullString(list[i]->phone);

		printf("\t\t Data Inserted \n");

		return;
	}

	puts("The book list is full...");
}

/*
* 데이터 삭제
*/
void DeleteData(Book** const list) {
	char str[CHAR_LEN];
	int i;

	puts("[Delete]");
	fputs("Delete Name:", stdout);
	fgets(str, CHAR_LEN, stdin);
	ChangeNullString(str);

	for (i = 0; i < LIST_LEN; i++) {
		if (list[i] == NULL) continue;

		if (strcmp(str, list[i]->auth) == 0) {
			free(list[i]);
			list[i] = NULL;
			return;
		}
	}

	printf("I can't find %s data... \n", str);
}

/*
* 데이터 검색
*/
void SearchData(Book** const list) {
	char str[CHAR_LEN];
	int i;

	puts("[Search]");
	fputs("Search Name:", stdout);
	fgets(str, CHAR_LEN, stdin);
	ChangeNullString(str);

	for (i = 0; i < LIST_LEN; i++) {
		if (list[i] == NULL) continue;

		if (strcmp(str, list[i]->auth) == 0) {
			printf("Name: %s \t Tel: %s \n", list[i]->auth, list[i]->phone);
			return;
		}
	}

	printf("I can't find %s data... \n", str);
}

/*
* 데이터 전체 출력
*/
void PrintfAll(Book** const list) {
	int i;

	puts("[Printf All]");
	for (i = 0; i < LIST_LEN; i++) {
		if (list[i] == NULL) continue;
		printf("Name: %s \t Tel: %s \n", list[i]->auth, list[i]->phone);
	}
}

/*
* 데이터 저장 및 종료
*/
void SaveAndExit(Book** const list) {
	puts("[Exit]");
	puts("Saving Data...");
	WriteData(list);
	puts("Program Exit...");
	exit(0);
}