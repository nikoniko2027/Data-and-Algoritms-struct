#include <iostream>
#include <vector>

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

int KMP(string X, string Y) { // Алгоритм Кнута — Морриса — Пратта
    if (Y.size() == 0) // Если строка-образец пустая
        return 0;
    vector <int> A = Prefix(Y); // Получаем Префикс-Фукнцию по строке-образце 
    int k = 0;
    for (int i = 0; i < X.size(); i++) // Пробегаемся по строке
        while (true) {
            if (Y.substr(k, 1) == X.substr(i, 1)) { // Если буква строки-образца равна букве строки
                k++;
                if (k == Y.size()) // Если вспомогательная переменная равна размеру строки-образца
                    return i + 1 - Y.size(); // Возвращаем номер элемента + 1 - размер строки-образца
                break; // Останавливаем цикл
            }
            if (k == 0) // Если не нашлось
                break; // Останавливаем цикл
            k = A[k - 1];
        }
    return -1;
}

int main() {
    setlocale(LC_ALL, "RUS");
    string X, Y;
    cout << "Введите строку: ";
    cin >> X;
    cout << "Введите строку-образец: ";
    cin >> Y;
    cout << "Результат: " << KMP(X, Y) << endl;
    cout << endl;
    system("pause");
    return 0;
}