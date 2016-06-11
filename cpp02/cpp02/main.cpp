#include <iostream>
#include <climits>
#include <Windows.h>
#include <bitset>
#define SOME_CONSTANT_VALUE 1234; // #define 구문 이용하여 상수 선언
using namespace std;

template<int n>
void showBitsetToByte(std::bitset<n> bs) {
	cout << "showBitsetToByte" << endl;
	int bytes = n / 8;
	cout << "bytes : " << bytes << endl;

	/*
	for (int i = 0; i < n; i++) {
		cout << bs[i];
		if (((i + 1) % 8) == 0) {
			cout << endl;
		}
	}
	*/

	for (int i = n - 1; i >= 0; i--) {
		cout << bs[i];
		if ((i % 8) == 0) {
			cout << endl;
		}
	}
	cout << "-----" << endl;
}

float myDiv(float x, float y) {
	return x / y;
}

int main() {
	// 정수 자료형
	short shotValue1 = SHRT_MAX;
	showBitsetToByte<16>(shotValue1);

	int intValue1 = 12345; // 기본적으로 signed가 생략되어 있음
	int intMaxValue = INT_MAX;
	// 실제 저장 bit 출력
	std::bitset<32> intMaxValueBitSet(intMaxValue);
	cout << intMaxValueBitSet << endl;
	showBitsetToByte<32>(intMaxValueBitSet);

	unsigned int unsignedIntMaxValue = UINT_MAX;
	std::bitset<32> unsignedIntMaxValueBitSet(unsignedIntMaxValue);
	cout << unsignedIntMaxValueBitSet << endl;

	// 변수 선언 하고 나중에 초기화 가능
	int lazyInitVal1, lazyInitVal2;
	lazyInitVal1 = 100;
	lazyInitVal2 = 200;

	// 실수 자료형
	float floatVal = 3.14F;
	std::bitset<sizeof(float)*CHAR_BIT> floatValueBitSet(*reinterpret_cast<unsigned long*>(&floatVal));
	showBitsetToByte<sizeof(float)*CHAR_BIT>(floatValueBitSet);

	double doubleVal = 3.14;

	// signed, unsigned

	// bool 형
	bool boolVal = true;
	boolVal = false;

	// sizeof 연산자
	cout << "size of bool : " << sizeof(boolVal) << endl; // 변수 이름 사용 가능
	cout << "size of bool : " << sizeof(bool) << endl; // 타입 이름도 사용 가능
	cout << "size of bool : " << sizeof(int) << endl; // 타입 이름도 사용 가능

	// 상수 선언 (const)
	const int MY_CONST_VALUE = 1234; // const 키워드 사용하여 상수 선언
	int constValueByDefine = SOME_CONSTANT_VALUE;
	cout << MY_CONST_VALUE << endl;
	cout << SOME_CONSTANT_VALUE;
	cout << constValueByDefine << endl;

	// 이스케이프 시퀀스
	const char* escapeSeqDemo = "\a\a\a\\\n\"안\t녕하\b\babc\b세\0요.\"";
	cout << escapeSeqDemo << endl;

	/*
	const char* ch = "가abc";
	cout << "ch : " << ch << endl;
	// cp949 형식으로 저장됨
	cout << "ch[0] : " << hex << (int) ch[0] << endl;
	cout << "ch[1] : " << hex << (int) ch[1] << endl;
	cout << "ch[2] hex : " << hex << (int) ch[2] << endl;
	cout << "ch[3] hex : " << hex << (int) ch[3] << endl;
	cout << "ch[4] hex : " << hex << (int) ch[4] << endl;
	cout << "ch[2] : " << ch[2] << endl;
	cout << "ch[3] : " << ch[3] << endl;
	cout << "ch[4] : " << ch[4] << endl;

	// wchar_t 형을 이용하여 한글 출력
	std::wcout.imbue(std::locale("korean")); // 한글 표시 위해서 필요

	wchar_t* st = L"안녕하세요.";
	wchar_t s = L'가';
	// 윈도우 환경에서는 utf-16을 이용한다고 하면 무방
	// http://stackoverflow.com/questions/10439680/wchar-t-and-encoding
	wchar_t utf16s = L'\uAC00';
	
	wcout << st << endl;
	wcout << s << endl;
	wcout << utf16s << endl;
	wcout << "utf16s size : " << sizeof(utf16s) << endl;
	wcout << "(int) utf16s in hex : " << hex << (int) utf16s << endl;
	std::bitset<16> x(utf16s);
	cout << x << endl;
	*/
	
	// static_cast
	// http://stackoverflow.com/questions/103512/in-c-why-use-static-castintx-instead-of-intx
	float staticCastFloatVal = static_cast<float>(1);
	int staticCastIntVal = static_cast<int>(3.5);
	cout << "staticCastFloatVal : " << staticCastFloatVal << endl;
	cout << "staticCastIntVal : " << staticCastIntVal << endl;

	// C 스타일 캐스팅
	float anotherCastFloatVal = (float) 1;
	int anotherCastIntVal = (int) 3.5;
	cout << "anotherCastFloatVal : " << anotherCastFloatVal << endl;
	cout << "anotherCastIntVal : " << anotherCastIntVal << endl;

	// auto 키워드를 이용한 타입 추론
	auto autoVal1 = 1; // int로 추론
	auto autoVal2 = 1.3f; // float으로 추론
	auto autoVal3 = 1 + 1.3; // double로 추론

	cout << "typeid(autoVal1).name() : " << typeid(autoVal1).name() << endl;
	cout << "typeid(autoVal2).name() : " << typeid(autoVal2).name() << endl;
	cout << "typeid(autoVal3).name() : " << typeid(autoVal3).name() << endl;

	// 조심해야 할 연산 실수
	float div = 1 / 3;
	cout << div << endl;

	div = (float) 1 / 3;
	cout << div << endl;

	div = 1 / (float) 3;
	cout << div << endl;

	div = (float) (1 / 3); // 소용 없음
	cout << div << endl;

	div = 1.0 / 3;
	cout << div << endl;

	div = 1 / static_cast<float>(3);
	cout << div << endl;

	// 이 경우 함수 파라미터에서 원하는 타입으로 자동으로 캐스팅되어 들어감
	cout << "myDiv(1, 3) : " << myDiv(1, 3) << endl;

	return 0;
}