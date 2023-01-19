#include <iostream>
#include "RBTree.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	RB_Tree X;
	cout << "Введите размерность дерева: ";
	int c, x;
	cin >> c;
	for (int i = false; i < c; i++) {
		cout << "Введите [" << i << "] элемент дерева: ";
		cin >> x;
		X.Push(x);
	}
	do {
		system("cls");
		cout << "=== Меню ===\n1 - Вставка\n2 - Удаление\n3 - Вывод\n4 - Завершение программы\nОтвет: ";
		cin >> c;
		switch (c) {
		case true:
			cout << "\nВведите вставляемый элемент: ";
			cin >> x;
			cout << "\n До вставления" << endl;
			X.Print();
			X.Push(x);
			cout << "\n После вставления" << endl;
			X.Print();
			cout << endl;
			break;
		case 2:
			cout << "\nВведите удаляемый элемент: ";
			cin >> x;
			cout << "\n До удаления" << endl;
			X.Print();
			X.Delete(x);
			cout << "\n После удаления" << endl;
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