#include <stdio.h>

/*
* 예제 코드 설명: 다차원배열(2차원)을 활용한 예제
*/
int main(void) {
	int villa[4][2];		// 2차원배열 행x열구조, 각 차원은 하나의 카테고리로써 활용이 가능하다. 여기서 행 = 층수, 열 = 가구의 의미를 가지고 있다.
	int population, i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d층 %d호 인구수: ", i+1, j+1);
			scanf_s("%d", &villa[i][j]);
		}
	}

	for (i = 0; i < 4; i++) {
		population = 0;
		for (j = 0; j < 2; j++) {
			population += villa[i][j];
		}
		printf("%d층 인구수: %d \n", i + 1, population);
	}

	return 0;
}