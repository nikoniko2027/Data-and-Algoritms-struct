#include <iostream> 

using namespace std;

struct tree{
    int i;
    tree* left;
    tree* right;
    int h;
};

tree* X = NULL; // ��������������� ������

tree* node(int i) {
    tree* x = new tree();
    x->i = i;
    x->left = NULL;
    x->right = NULL;
    x->h = 1;
    return(x);
}

int GetMax(int a, int b) { // ���������� ������������ ������
    if (a > b)
        return a;
    else
        return b;
}

int Height(tree* n) { // ���������� ������
    if (n == NULL)
        return 0;
    return n->h;
}

int GetBal(tree* A) { // ���������� ������� ������ ������ � �������
    if (A == NULL)
        return 0;
    return Height(A->left) - Height(A->right);
}

tree* RotateR(tree* y) { // ������ �������
    tree* x = y->left;
    tree* r = x->right;
    x->right = y; // �������
    y->left = r;
    y->h = GetMax(Height(y->left), Height(y->right)) + 1; // ������ �������� ������
    x->h = GetMax(Height(x->left), Height(x->right)) + 1;
    return x;
}

tree* RotateL(tree* x) { // ����� �������
    tree* y = x->right;
    tree* l = y->left;
    y->left = x;
    x->right = l;
    x->h = GetMax(Height(x->left), Height(x->right)) + 1;
    y->h = GetMax(Height(y->left), Height(y->right)) + 1;
    return y;
}

tree* Push(tree* x, int i) { // �������
    if (x == NULL) // ���� ������ ������
        return(node(i));
    if (i < x->i) // ���� ������ ��������, �����
        x->left = Push(x->left, i);
    else if (i > x->i) // ���� ������ ��������, ������
        x->right = Push(x->right, i);
    else // ���� ����� �� �������, �� �� ���������
        return x;
    x->h = 1 + GetMax(Height(x->left), Height(x->right)); // ����������� ������ ��������

    int b = GetBal(x); // ������� ������� ����� ����� � ������
 
    if (b > 1 && i < x->left->i) // ���� ������ ���������� ������, ��� �� 1, � �������� ������ ������ �������� (�����, �����)
        return RotateR(x); // ������ ����

    if (b < -1 && i > x->right->i) // (������, ������)
        return RotateL(x);
    if (b > 1 && i > x->left->i) { // (�����, ������)
        x->left = RotateL(x->left);
        return RotateR(x);
    }
    if (b < -1 && i < x->right->i) { // (������, �����)
        x->right = RotateR(x->right);
        return RotateL(x);
    }
    return x;
}

void Print(tree* A) { // ����� �� �����
    if (A != NULL) {
        cout << A->i << " ";
        Print(A->left);
        Print(A->right);
    }
}

void Del(tree* A, int i) { // �������� ��������
    if (A != NULL) {
        if (A->i != i) // ���� ������� �� ����� ����������, �� ��������� �������� � ������ �
           X = Push(X, A->i);
        Del(A->left, i);
        Del(A->right, i);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    tree* A = NULL;
    int c, x;
    cout << "������� ���������� ��������� � ������: ";
    cin >> c;
    for (int i = 0; i < c; i++) {
        cout << "������� [" << i << "] �������: ";
        cin >> x;
        A = Push(A, x);
    }
    do {
        system("cls");
        cout << "=== ���� ===\n1 - �������\n2 - ��������\n3 - �����\n4 - ���������� ���������\n ��� �����: ";
        cin >> c;
        cout << endl;
        switch (c) {
        case 1:
            cout << "������� ����������� �������: ";
            cin >> x;
            A = Push(A, x);
            break;
        case 2:
            X = NULL;
            cout << "������� ��������� �������: ";
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