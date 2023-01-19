#include <iostream>

using namespace std;

int search = 0;

struct tree { // Структура дерева
	int i; // Значение
	tree* left; // Указатель на левого ребенка
	tree* right; // Указатель на правого ребенка
	tree* parent; // Указатель на родителя
};

tree* node(int x) { // Структура листа
	tree* X = new tree; // Создаем новый элемент
	X->i = x; // Присваиваем значение
	X->left = NULL; // Обнуляем левого и правого ребенка, а так же родителя
	X->right = NULL;
	X->parent = NULL;
	return X;
}

void P_obhod(tree* X) { // Прямой
	if (X) {
		cout << X->i << " ";
		P_obhod(X->left);
		P_obhod(X->right);
	}
}

void O_obhod(tree* X) { // Обратный
	if (X) {
		O_obhod(X->left);
		O_obhod(X->right);
		cout << X->i << " ";
	}
}

void S_obhod(tree* X) { // Симметричный
	if (X) {
		S_obhod(X->left);
		cout << X->i << " ";
		S_obhod(X->right);
	}
}

void Push(tree*& X, int x) {
	tree *c = node(x); // Создаем элемент дерева
	if (!X) // Если дерево не существует
		X = c; // Делаем корень
	else {
		tree* a = X; // Создаем копию для обхода
		while (a) { // Пока не дошли до конца
			if (a->i > x) {
				if (a->left)
					a = a->left;
				else {
					a->left = c;
					c->parent = a;
					break;
				}
			}
			else if (a->right)
				a = a->right;
			else {
				a->right = c;
				c->parent = a;
				break;
			}
		}
	}
}


void Search(tree* X, int i) {
	if (X) {
		if (X->i == i)
			search++;
		else {
			Search(X->left, i);
			Search(X->right, i);
		}
	}
}

void AddDel(tree* A, tree* X) { // Функция для восстановления ветки, родитель которой был удален
	if (A) { // Если доп. ветка существет
		Push(X, A->i); // Функция добавления
		if (A->left) // Если существует левый ребенок, смещаемся к нему
			AddDel(A->left, X);
		if (A->right) // Если существует правый ребенок, смещаемся к нему
			AddDel(A->right, X);
	}
}

void Del(tree* X, int i) { // Удаление элемента
	if (!X) // Если элемент дерева не существует
		search -= 0; // Заглушка
	else if (X->i == i) {
		if (!X->left && !X->right && X->parent) { // Нет левого и нет правого и есть родитель
			if (X->parent->i > i)
				X->parent->left = NULL;
			else
				X->parent->right = NULL;
			search++; // Вспомогательная переменная для идентификации удаления
			delete X;
		}
		else if (X->left && !X->right && X->parent) { // Если есть только левый и есть родитель
			X->parent->left = X->left;
			search++;
			delete X;
		}
		else if (!X->left && X->right && X->parent) { // Если есть только правый и есть родитель
			X->parent->right = X->right;
			search++;
			delete X;
		}
		else if (X->left && X->right && X->parent) { // Если есть и левый, и правый и есть родитель
			tree* A = X->left;
			if (X->parent->i > i) // Если значение родителя больше искомого элемента
				X->parent->left = X->right; // У родителя в левую ветку вставляем правую ветку текущего элемента
			else
				X->parent->right = X->right;
			X = X->parent;
			AddDel(A, X);	
		}
		else if (X->left && X->right && !X->parent) { // Если есть левый и правый, но нет родителя / (Корень)
			tree* L = X->left; // Создаем дубликат левой ветки
			tree* R = X->right; // И правой
			X->i = R->i; // Копируем информацию правой ветки как основную
			X->left = R->left;
			X->right = R->right;
			search++;
			AddDel(L, X); // И на нее цепляем значение 
		}
		else if (!X->left && X->right && !X->parent) { // Если нет левого и родителя, но есть правый / (Корень)
			tree* R = X->right;
			X->i = R->i;
			X->left = NULL;
			X->right = R->right;
			search++;
		}
		else if (X->left && !X->right && !X->parent) { // Если нет правого и родителя, но есть левый / (Корень)
			tree* L = X->left;
			X->i = L->i;
			X->left = L->left;
			X->right = NULL;
			search++;
		}
	}
		else { // Иначе сдвигаемся и делаем проверку заново
			Del(X->left, i);
			Del(X->right, i);
		}
}


int main() {
	setlocale(LC_ALL, "RUS"); // Русский язык
	tree* X = NULL; // Инициализируем дерево
	int c, cc;
	cout << "Введите количество элементов в дереве: ";
	cin >> c;
	system("cls"); // Очищаем экран консоли
	for (int i = 0; i < c; i++) { // Заполняем дерево
		cout << "Введите [" << i << "] элемент дерева: ";
		cin >> cc;
		Push(X, cc);
	}
	bool fl = false;
	do { // Меню
		system("cls");
		cout << "===Выберите действие===" << endl;
		cout << "\n1 - Прямой обход\n2 - Обратный обход\n3 - Симметричный обход\n4 - Найти элемент\n5 - Удалить элемент\n6 - Закрыть программу\nВаш ответ: ";
		cin >> c;
		cout << "\n\n";
		switch (c) {
		case 1:
			P_obhod(X);
			cout << endl;
			break;
		case 2:
			O_obhod(X);
			cout << endl;
			break;
		case 3:
			S_obhod(X);
			cout << endl;
			break;
		case 4:
			cout << "Введите искомый элемент: ";
			cin >> cc;
			search = 0;
			Search(X, cc);
			if (search > 0)
				cout << "Элемент [" << cc << "] найден" << endl;
			else
				cout << "Элемент [" << cc << "] не найден" << endl;
			break;
		case 5:
			cout << "Введите удаляемый элемент: ";
			cin >> cc;
			search = 0;
			Del(X, cc);
			if (search > 0)
				cout << "Элемент [" << cc << "] успешно удален" << endl;
			else
				cout << "Элемент [" << cc << "] не найден" << endl;
			break;
		case 6:
			fl = true;
			break;
		}
		system("pause");
	} while (fl == false);
	return 0;
}