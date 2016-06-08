// <> ���谡 ������ �⺻ �����Ǵ� ���̺귯�� ���
#include <iostream>
#include <string>
// �̰� ���������� ���� �� (�ڱⰡ ���� ��)
#include "outerns.h" 

namespace abc { // abc��� �̸� ������ ����
	const double PI = 3.14; // abc��� �̸� ���� ���ο� ��� ����
	int add(int x, int y) { // abc��� �̸� ���� ���ο� �Լ� ����
		return x + y;
	}
}

// �Լ� ���� (��� ���� ���� �ʿ� ����)
void sayHello() {
	using namespace std; // std �̸� ������ ��� (�� ���� scope���� ��ȿ��)
	cout << "Hello" << endl;
}

// ���� ���� (�Լ� �ñ״��� ����)
void func1(int); // �̷��� ���൵ ������
int func2(int a, int b); // ���� ���� �̸� ���൵ �� (���� �̸� ���� �ʿ� ����)

// main�� Ư���� ��Ʈ�� ����Ʈ �Լ�
// https://ko.wikipedia.org/wiki/%EC%97%94%ED%8A%B8%EB%A6%AC_%ED%8F%AC%EC%9D%B8%ED%8A%B8
// void�� ���൵ �ǰ� �Ƚ��൵ �� (void ���� C�� ȣȯ���� �������ٰ� ��)
// http://stackoverflow.com/questions/8024790/understanding-the-exact-meaning-of-the-void-keyword-in-c-c
// http://www.learncpp.com/cpp-tutorial/2-2-void/
int main(void) {
// int main() { // �̷��� ���°� �� �� �ֽ� ���
	std::cout << "start main function " << std::endl;
	std::cout << "(8 << 1) : " << (8 << 1) << std::endl; // ������ ��Ʈ ����Ʈ �������ε� cout���� << �����ڸ� �����ε��Ͽ� Ư���ϰ� ���̴� ��! (������ �����ε��� ���߿� ����)
	std::cout << "(8 >> 1) : " << (8 >> 1) << std::endl;

	// �� ��� scope�� ����
	{
		using namespace std;
		// '::' �� ���� ���� �����ڷ� �ַ� ����
		cout << "std:: �Ⱥ��̰� cout ȣ��" << endl; // �Ⱥٿ��� �ǰ� (using �����ϱ�~)
		std::cout << "outer::a " << outer::a << std::endl; // �ٿ��� �ᵵ ��
		cout << "inner::a " << outer::inner::a << endl;
	}
	// �ٸ� ��� scope ����
	{
		using namespace outer;
		std::cout << "outer::inner::a " << outer::inner::a << std::endl;
		std::cout << "inner::a " << inner::a << std::endl;
	}
	{
		using std::cout; // cout�� std�� �������� �ʰ� �� �� �ְ� �ϰ� ���� ��� (using�� ����Ѵٴ� ���� ����)
		// outer ������ inner�� using���� ����
		// (���� �� ������ ���鿡 :: ������ ���� ������ ����, inner�� ���ӽ����̽��̹Ƿ� using namespace ������ ���)
		using namespace outer::inner;
		cout << "outer::inner::a " << a << std::endl; // cout�� std:: ���� ��� ����
	}
	std::cout << "std:: ���̰� cout ȣ��" << std::endl;
	
	sayHello();
	func1(1000);
	std::cout << func2(1, 2) << std::endl;

	// ������ ������ namespace ����
	std::cout << "abc::PI " << abc::PI << std::endl;
	std::cout << "abc::add(1, 2) " << abc::add(1, 2) << std::endl;

	// Q) �� ��� scope ����� using Ű����� abc �Ƚᵵ pi, add ȣ���� �� �ְ� �غ���

	// cin ����
	// �ڷ����� ���� ������ >> ������ �����ε��� �Ǿ� �־ �׳� >> �Է°����� ������ �������ָ� OK
	int a;
	std::cout << "int �� �Է� : ";
	std::cin >> a;
	std::cout << "�Է°��� : " << a << std::endl;
	double b;
	std::cout << "double �� �Է� : ";
	std::cin >> b;
	std::cout << "�Է°��� : " << b << std::endl;
	std::string str; 
	std::cout << "string �� �Է� : ";
	std::cin >> str;
	std::cout << "�Է°��� : " << str << std::endl;

	// Q) å ���α׷��� ���� ���� Ǯ���(2��, 5��, �Լ� ���� �����ϴ� ���·� ¥����)

	return 0;
}

/*
	�Լ� ����

	��ȯ�� �Լ��̸�(��ȯŸ��1 �̸�1, ��ȯŸ��2 �̸�2, ...)
	{
		�Լ� ��ü ...

		(��ȯ���� �ִٸ�) ���Ϲ�;
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