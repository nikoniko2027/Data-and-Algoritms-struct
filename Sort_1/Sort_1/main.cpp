#include <iostream>
#include "ClassSort.h" // ���������� �����

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	Sort A;
	bool fl = false;
	int c, x, y, a;

	do { // ������ ����������� �������
		system("cls");
		cout << "������� ���������� ��������� � �������: ";
		cin >> a;
	} while (a < 1);


	do { // ������ ����������� ����� � �������
		system("cls");
		cout << "����������� ������������ �����: ";
		cin >> x;
	} while (x < 1 || x > 998);

	do { // ������ ������������ ����� � �������
		system("cls");
		cout << "������������ ������������ ����� (�� 1000): ";
		cin >> y;
	} while (y < x || y > 999);

	A.Generate(a, x, y); // ���������� ������
	A.Print(); // ������� ������ �� �����
	system("pause");

	do { // ���� 
		do { // ������ ����� � ���� � ���������
		system("cls");
		cout << "===���� ����������===" << endl;
		cout << "1 - ���������� ���������\n2 - ����������� ����������\n3 - ������� ���������\n��� �����: ";
		cin >> c;
		} while (c < 1 && c > 3);
		switch (c) {
		case 1:
			A.SortCounting(y); // �������� ���������� ���������
			break;
		case 2:
			A.SortRadix(y); // �������� ����������� ����������
			break;
		case 3:
			return 0; // ��������� ���������
			break;
		}
	} while (fl == false);
}