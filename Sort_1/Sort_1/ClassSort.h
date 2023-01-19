#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Sort {  // Класс сортировки
private:
	vector <int> main; // Главный массив, в котором находится сгенерированный массив
public:

	void Generate(int a, int x, int y) {  // Генерация массива
		for (int i = 0; i < a; i++)
			main.push_back(x + rand() % (y - x));
	}

	void Print() { // Выводим сгенерированный массив на экран
		system("cls");
		cout << "===Первоначальный массив===\n" << endl;
		for (int i = 0; i < main.size(); i++)
			cout << main[i] << " ";
		cout << "\n" << endl;
	}

	void PrintSort(vector<int>sort, int c) { // Общий метод класса для вывода отсортированного массива
		system("cls");

		cout << "===Первоначальный массив===\n" << endl;
		for (int i = 0; i < main.size(); i++)
			cout << main[i] << " ";
		cout << "\n" << endl;

		cout << "===Отсортированный массив===\n" << endl;
		switch (c) {
		case 1: // Выводим на экран Сортировку подсчетом
			for (int i = 0; i < sort.size(); i++)
				for (int j = 0; j < sort[i]; j++)
					cout << i << " ";
			break;
		case 2: // Выводим на экран Поразрядную сортировку
			for (int i = 0; i < sort.size(); i++)
				cout << sort[i] << " ";
			break;
		}
		cout << "\n" << endl;

		system("pause");
	}

	void SortCounting(int y) { // Сортировка подсчетом
		vector <int> sup;
		for (int i = 0; i <= y; i++)
			sup.push_back(0);
		for (int i = 0; i < main.size(); i++)
			sup[main[i]]++;
		PrintSort(sup, 1);
	}

	void SortRadix(int y) { // Поразрядная сортировка
		vector <int> sup1 = main;
		vector <vector<int>> sup2;
		int c = 1, m = 10;

		for (int i = 0; i < 10; i++)
			sup2.push_back(vector<int>());

		for (int i = 0; i < 3; i++) {

			for (int a = 0; a < main.size(); a++)
				sup2[(sup1[a] % m) / c].push_back(sup1[a]);

			sup1.clear();

			for (int a = 0; a < 10; a++)
				for (int j = 0; j < sup2[a].size(); j++)
					sup1.push_back(sup2[a][j]);

			for (int i = 0; i < sup2.size(); i++)
				sup2[i].clear();

			m *= 10;
			c *= 10;
		}
		PrintSort(sup1, 2);
	}
};