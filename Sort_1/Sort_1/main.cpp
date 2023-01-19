#include <iostream>
#include "ClassSort.h" // Подключаем класс

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	Sort A;
	bool fl = false;
	int c, x, y, a;

	do { // Вводим размерность массива
		system("cls");
		cout << "Введите количество элементов в массиве: ";
		cin >> a;
	} while (a < 1);


	do { // Вводим минимальное число в массиве
		system("cls");
		cout << "Минимальное генерируемое число: ";
		cin >> x;
	} while (x < 1 || x > 998);

	do { // Вводим максимальное число в массиве
		system("cls");
		cout << "Максимальное генерируемое число (до 1000): ";
		cin >> y;
	} while (y < x || y > 999);

	A.Generate(a, x, y); // Генерируем массив
	A.Print(); // Выводим массив на экран
	system("pause");

	do { // Меню 
		do { // Вводим пункт в меню с проверкой
		system("cls");
		cout << "===Меню сортировки===" << endl;
		cout << "1 - Сортировка Подсчетом\n2 - Поразрядная сортировка\n3 - Закрыть программу\nВаш ответ: ";
		cin >> c;
		} while (c < 1 && c > 3);
		switch (c) {
		case 1:
			A.SortCounting(y); // Вызываем Сортировку подсчетом
			break;
		case 2:
			A.SortRadix(y); // Вызываем Поразрядную сортировку
			break;
		case 3:
			return 0; // Завершаем программу
			break;
		}
	} while (fl == false);
}