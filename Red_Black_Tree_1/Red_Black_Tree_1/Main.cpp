#include <iostream>
#include "RBTree.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	RB_Tree X;
	cout << "������� ����������� ������: ";
	int c, x;
	cin >> c;
	for (int i = false; i < c; i++) {
		cout << "������� [" << i << "] ������� ������: ";
		cin >> x;
		X.Push(x);
	}
	do {
		system("cls");
		cout << "=== ���� ===\n1 - �������\n2 - ��������\n3 - �����\n4 - ���������� ���������\n�����: ";
		cin >> c;
		switch (c) {
		case true:
			cout << "\n������� ����������� �������: ";
			cin >> x;
			cout << "\n �� ����������" << endl;
			X.Print();
			X.Push(x);
			cout << "\n ����� ����������" << endl;
			X.Print();
			cout << endl;
			break;
		case 2:
			cout << "\n������� ��������� �������: ";
			cin >> x;
			cout << "\n �� ��������" << endl;
			X.Print();
			X.Delete(x);
			cout << "\n ����� ��������" << endl;
			X.Print();
			cout << endl;
			break;
		case 3:
			cout << endl;
			X.Print();
			cout << endl;
			break;
		case 4:
			c = 4;
			break;
		}
		if (c > 0 && c < 4)
			system("pause");
	} while (c != 4);
	return 0;
}