#include <stdio.h>


/*
* 예제 코드 설명: 열거형의 정의 방법과 의미 예제
* 
* 1. 열거형의 선언 방법은 구조체와 동일하지만, struct키워드 대신 enum키워드를 사용한다.
* 2. 열거형은 연관이 있는 상수데이터에 의미있는 이름을 부여하여 프로그램의 가독성을 증가시켜준다.
* 3. enum을 정의하면 열거형 내부의 멤버변수의 이름을 통해 어디서든 사용이 가능하다.
*/

typedef enum syllable {
	Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Si=7
} Syllable;

void Sound(Syllable sy) {
	switch (sy) {
		case Do:
			puts("도는 하얀 도라지 ♪"); 
			return;
		case Re:
			puts("레는 둥근 레코드 ♩");
			return;
		case Mi:
			puts("미는 파란 미나리 ♩♪");
			return;
		case Fa:
			puts("파는 예쁜 파랑새 ♪♭");
			return;
		case So:
			puts("솔은 작은 솔방울 ♩♪♪");
			return;
		case La:
			puts("라는 라디오고요~ ♪♩♭♩");
			return;
		case Si:
			puts("시는 졸졸 시냇물 ♩♭♩♪");
			return;
	}
	puts("다 함께 부르세~ 도레미파 솔라시도 솔 도~ 짠~");
}

int main(void) {
	Syllable tone;
	for (tone = Do; tone <= Si; tone++) {	// enum을 정의하면 내부의 멤버변수의 이름을 통해 어디서든 사용이 가능하다.
		Sound(tone);
	}

	return 0;
}
