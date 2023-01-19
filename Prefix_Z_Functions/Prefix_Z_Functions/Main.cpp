#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> Prefix(string x) { // Префикс-Функция
	vector<int> X(x.size()); // Вспомогательный вектор размером количества символов в строке
	for (int i = 1; i < x.size(); i++) { // Пробегаемся по строке
		int j = X[i - 1];
		while (j > 0 && x[i] != x[j]) // Пока начало больше 0 и элементы не одинаковы
			j = X[j - 1]; // Присваиваем предыдущий
		if (x[i] == x[j]) // Если значения равны
			j++; // То перемещаем на 1 дальше
		X[i] = j; // Передаем полученное значение в элемент массива
	}
	return X;
}

vector<int> Z(string x) { // Z-Функция
	vector<int> X(x.size()); // Вспомогательный вектор размером количества символов в строке
	for (int i = 1, l = 0, r = 0; i < x.size(); i++) { // Пробегаемся по строке
		if (i <= r) // Если входит в отрезок
			X[i] = min(r - i + 1, X[i - l]); // Присваиваем наименьший
		while (i + X[i] < x.size() && x[X[i]] == x[i + X[i]]) // Пока смещение + наименьший менее размера строки и элемент по значению равен элементу по смещению + значению
			X[i]++; // Прибавляем единичку 
		if (i + X[i] - 1 > r) // Если лежит за пределами
			l = i, 
			r = i + X[i] - 1;
	}
	return X;
}

int main() {
	setlocale(LC_ALL, "RUS");
	vector<int> X;
	string x;
	int c;
	cout << "Введите строку: ";
	cin >> x;
	do {
		system("cls");
		cout << "Строка: " << x << endl;
		cout << "\n=== Меню ===\n1 - Префикс-функция\n2 - Z-функция\n3 - Изменить строку\n4 - Завершить программу\nВаш ответ: ";
		cin >> c;
		cout << endl;
		X.clear();
		switch (c) {
		case 1:
			X = Prefix(x);
			for (int i = 0; i < X.size(); i++)
				cout << X[i] << " ";
			break;
		case 2:
			X = Z(x);
			for (int i = 0; i < X.size(); i++)
				cout << X[i] << " ";
			break;
		case 3:
			system("cls");
			cout << "Введите новую строку: ";
			cin >> x;
			break;
		}
		cout << endl;
		system("pause");
	} while (c != 4);
	return 0;
}