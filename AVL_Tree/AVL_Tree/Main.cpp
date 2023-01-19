#include <iostream> 

using namespace std;

struct tree{
    int i;
    tree* left;
    tree* right;
    int h;
};

tree* X = NULL; // Вспомогательное дерево

tree* node(int i) {
    tree* x = new tree();
    x->i = i;
    x->left = NULL;
    x->right = NULL;
    x->h = 1;
    return(x);
}

int GetMax(int a, int b) { // Возвращает максимальную высоту
    if (a > b)
        return a;
    else
        return b;
}

int Height(tree* n) { // Возвращает высоту
    if (n == NULL)
        return 0;
    return n->h;
}

int GetBal(tree* A) { // Возвращаем разницу высоты левого и правого
    if (A == NULL)
        return 0;
    return Height(A->left) - Height(A->right);
}

tree* RotateR(tree* y) { // Правый поворот
    tree* x = y->left;
    tree* r = x->right;
    x->right = y; // Вращаем
    y->left = r;
    y->h = GetMax(Height(y->left), Height(y->right)) + 1; // Меняем значение высоты
    x->h = GetMax(Height(x->left), Height(x->right)) + 1;
    return x;
}

tree* RotateL(tree* x) { // Левый поворот
    tree* y = x->right;
    tree* l = y->left;
    y->left = x;
    x->right = l;
    x->h = GetMax(Height(x->left), Height(x->right)) + 1;
    y->h = GetMax(Height(y->left), Height(y->right)) + 1;
    return y;
}

tree* Push(tree* x, int i) { // Вставка
    if (x == NULL) // Если дерево пустое
        return(node(i));
    if (i < x->i) // Если меньше родителя, левый
        x->left = Push(x->left, i);
    else if (i > x->i) // Если больше родителя, правый
        x->right = Push(x->right, i);
    else // Если такой же элемент, то не добавляем
        return x;
    x->h = 1 + GetMax(Height(x->left), Height(x->right)); // Присваиваем высоту родителю

    int b = GetBal(x); // Находим разницу между левым и правым
 
    if (b > 1 && i < x->left->i) // Если высота отличается больше, чем на 1, и значение левого больше элемента (левый, левый)
        return RotateR(x); // Крутим узел

    if (b < -1 && i > x->right->i) // (правый, правый)
        return RotateL(x);
    if (b > 1 && i > x->left->i) { // (левый, правый)
        x->left = RotateL(x->left);
        return RotateR(x);
    }
    if (b < -1 && i < x->right->i) { // (правый, левый)
        x->right = RotateR(x->right);
        return RotateL(x);
    }
    return x;
}

void Print(tree* A) { // Вывод на экран
    if (A != NULL) {
        cout << A->i << " ";
        Print(A->left);
        Print(A->right);
    }
}

void Del(tree* A, int i) { // Удаление элемента
    if (A != NULL) {
        if (A->i != i) // Если элемент не равен удаляемому, то переносим значение в дерево Х
           X = Push(X, A->i);
        Del(A->left, i);
        Del(A->right, i);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    tree* A = NULL;
    int c, x;
    cout << "Введите количество элементов в дереве: ";
    cin >> c;
    for (int i = 0; i < c; i++) {
        cout << "Введите [" << i << "] элемент: ";
        cin >> x;
        A = Push(A, x);
    }
    do {
        system("cls");
        cout << "=== Меню ===\n1 - Вставка\n2 - Удаление\n3 - Вывод\n4 - Завершение программы\n Ваш ответ: ";
        cin >> c;
        cout << endl;
        switch (c) {
        case 1:
            cout << "Введите вставляемый элемент: ";
            cin >> x;
            A = Push(A, x);
            break;
        case 2:
            X = NULL;
            cout << "Введите удаляемый элемент: ";
            cin >> x;
            Del(A, x);
            A = X;
            break;
        case 3:
            Print(A);
            break;
        }
        system("pause");
    } while (c != 4);
    return 0;
}