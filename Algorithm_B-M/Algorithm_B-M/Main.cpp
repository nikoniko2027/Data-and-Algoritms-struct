#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> Prefix(string X) { // Префикс-Функция
	vector <int> A;
	for (int i = 0; i < 256; i++) // Создадим 256 элементов для символов
		A.push_back(-1); // И заполним
	for (int i = 0; i < X.size(); i++) // В нужный номер элемента запишем смещение
		A[X[i]] = i;
	return A;
}

void BM(string X, string Y) { // Алгоритм Бойера — Мура
	int i = 0;
	vector <int> A;
	if (Y.size() > X.size()) // Если строка образец больше строки
		cout << "Строка-образец больше строки!" << endl;
	else {
		A = Prefix(Y);
		while (i <= (X.size() - Y.size())) { // Пробегаемся по строке
			int j = Y.size() - 1;
			while (j >= 0 && Y[j] == X[i + j]) // Смотрим совпадения и смещяемся на символ назад
				j--;
			if (j < 0) { // Если нашлось, выводим номер
				cout << i << " ";
				if (i + Y.size() < X.size()) 
					i += Y.size() - A[X[i + Y.size()]]; // И смещаем каретку для проверки
				else // Иначе просто переходим к следующему символу
					i++;
			}
			else // Иначе прибавляем единичку или разность номера + смещение
				i += 1 > j - A[X[i + j]] ? 1 : j - A[X[i + j]]; 
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	string X, Y;
	cout << "Введите строку: ";
	cin >> X;
	cout << "Введите строку-образец: ";
	cin >> Y;
	cout << "Результат: ";
	BM(X, Y);
	cout << endl;
	system("pause");
	return 0;
}