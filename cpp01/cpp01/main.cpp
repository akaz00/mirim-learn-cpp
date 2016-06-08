// <> 꺽쇠가 붙으면 기본 제공되는 라이브러리 헤더
#include <iostream>
#include <string>
// 이건 내부적으로 쓰는 것 (자기가 만든 거)
#include "outerns.h" 

namespace abc { // abc라는 이름 공간을 선언
	const double PI = 3.14; // abc라는 이름 공간 내부에 상수 선언
	int add(int x, int y) { // abc라는 이름 공간 내부에 함수 선언
		return x + y;
	}
}

// 함수 선언 (얘는 전방 선언 필요 없음)
void sayHello() {
	using namespace std; // std 이름 공간을 사용 (이 로컬 scope에서 유효함)
	cout << "Hello" << endl;
}

// 전방 선언 (함수 시그니쳐 선언)
void func1(int); // 이렇게 써줘도 무방함
int func2(int a, int b); // 받을 변수 이름 써줘도 됨 (구지 이름 같을 필요 없음)

// main은 특수한 엔트리 포인트 함수
// https://ko.wikipedia.org/wiki/%EC%97%94%ED%8A%B8%EB%A6%AC_%ED%8F%AC%EC%9D%B8%ED%8A%B8
// void를 써줘도 되고 안써줘도 됨 (void 쓰면 C와 호환성이 높아진다고 함)
// http://stackoverflow.com/questions/8024790/understanding-the-exact-meaning-of-the-void-keyword-in-c-c
// http://www.learncpp.com/cpp-tutorial/2-2-void/
int main(void) {
// int main() { // 이렇게 쓰는게 좀 더 최신 방법
	std::cout << "start main function " << std::endl;
	std::cout << "(8 << 1) : " << (8 << 1) << std::endl; // 원래는 비트 쉬프트 연산자인데 cout에서 << 연산자를 오버로딩하여 특수하게 쓰이는 것! (연산자 오버로딩은 나중에 보기)
	std::cout << "(8 >> 1) : " << (8 >> 1) << std::endl;

	// 새 블록 scope를 선언
	{
		using namespace std;
		// '::' 는 범위 지정 연산자로 주로 쓰임
		cout << "std:: 안붙이고 cout 호출" << endl; // 안붙여도 되고 (using 썼으니까~)
		std::cout << "outer::a " << outer::a << std::endl; // 붙여서 써도 됨
		cout << "inner::a " << outer::inner::a << endl;
	}
	// 다른 블록 scope 선언
	{
		using namespace outer;
		std::cout << "outer::inner::a " << outer::inner::a << std::endl;
		std::cout << "inner::a " << inner::a << std::endl;
	}
	{
		using std::cout; // cout만 std에 접근하지 않고 쓸 수 있게 하고 싶은 경우 (using만 사용한다는 것의 주의)
		// outer 내부의 inner를 using으로 지정
		// (이제 그 내부의 값들에 :: 연산자 없이 접근이 가능, inner는 네임스페이스이므로 using namespace 구문을 사용)
		using namespace outer::inner;
		cout << "outer::inner::a " << a << std::endl; // cout만 std:: 없이 사용 가능
	}
	std::cout << "std:: 붙이고 cout 호출" << std::endl;
	
	sayHello();
	func1(1000);
	std::cout << func2(1, 2) << std::endl;

	// 위에서 정의한 namespace 접근
	std::cout << "abc::PI " << abc::PI << std::endl;
	std::cout << "abc::add(1, 2) " << abc::add(1, 2) << std::endl;

	// Q) 새 블록 scope 만들고 using 키워드로 abc 안써도 pi, add 호출할 수 있게 해보기

	// cin 사용법
	// 자료형에 따라 적절히 >> 연산자 오버로딩이 되어 있어서 그냥 >> 입력값으로 변수만 전달해주면 OK
	int a;
	std::cout << "int 값 입력 : ";
	std::cin >> a;
	std::cout << "입력값은 : " << a << std::endl;
	double b;
	std::cout << "double 값 입력 : ";
	std::cin >> b;
	std::cout << "입력값은 : " << b << std::endl;
	std::string str; 
	std::cout << "string 값 입력 : ";
	std::cin >> str;
	std::cout << "입력값은 : " << str << std::endl;

	// Q) 책 프로그래밍 연습 문제 풀어보기(2번, 5번, 함수 전방 선언하는 형태로 짜보기)

	return 0;
}

/*
	함수 정의

	반환값 함수이름(반환타입1 이름1, 반환타입2 이름2, ...)
	{
		함수 몸체 ...

		(반환값이 있다면) 리턴문;
	}
*/

void func1(int x) {
	using namespace std;

	cout << "call func 1" << endl;
	cout << x << endl;
}

int func2(int x, int y) {
	using namespace std;

	cout << "call func 2" << endl;
	return (x + y) * 2;
}