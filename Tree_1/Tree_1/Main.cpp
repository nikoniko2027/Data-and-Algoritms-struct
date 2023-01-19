#include <iostream>

using namespace std;

int search = 0;

struct tree { // ��������� ������
	int i; // ��������
	tree* left; // ��������� �� ������ �������
	tree* right; // ��������� �� ������� �������
	tree* parent; // ��������� �� ��������
};

tree* node(int x) { // ��������� �����
	tree* X = new tree; // ������� ����� �������
	X->i = x; // ����������� ��������
	X->left = NULL; // �������� ������ � ������� �������, � ��� �� ��������
	X->right = NULL;
	X->parent = NULL;
	return X;
}

void P_obhod(tree* X) { // ������
	if (X) {
		cout << X->i << " ";
		P_obhod(X->left);
		P_obhod(X->right);
	}
}

void O_obhod(tree* X) { // ��������
	if (X) {
		O_obhod(X->left);
		O_obhod(X->right);
		cout << X->i << " ";
	}
}

void S_obhod(tree* X) { // ������������
	if (X) {
		S_obhod(X->left);
		cout << X->i << " ";
		S_obhod(X->right);
	}
}

void Push(tree*& X, int x) {
	tree *c = node(x); // ������� ������� ������
	if (!X) // ���� ������ �� ����������
		X = c; // ������ ������
	else {
		tree* a = X; // ������� ����� ��� ������
		while (a) { // ���� �� ����� �� �����
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

void AddDel(tree* A, tree* X) { // ������� ��� �������������� �����, �������� ������� ��� ������
	if (A) { // ���� ���. ����� ���������
		Push(X, A->i); // ������� ����������
		if (A->left) // ���� ���������� ����� �������, ��������� � ����
			AddDel(A->left, X);
		if (A->right) // ���� ���������� ������ �������, ��������� � ����
			AddDel(A->right, X);
	}
}

void Del(tree* X, int i) { // �������� ��������
	if (!X) // ���� ������� ������ �� ����������
		search -= 0; // ��������
	else if (X->i == i) {
		if (!X->left && !X->right && X->parent) { // ��� ������ � ��� ������� � ���� ��������
			if (X->parent->i > i)
				X->parent->left = NULL;
			else
				X->parent->right = NULL;
			search++; // ��������������� ���������� ��� ������������� ��������
			delete X;
		}
		else if (X->left && !X->right && X->parent) { // ���� ���� ������ ����� � ���� ��������
			X->parent->left = X->left;
			search++;
			delete X;
		}
		else if (!X->left && X->right && X->parent) { // ���� ���� ������ ������ � ���� ��������
			X->parent->right = X->right;
			search++;
			delete X;
		}
		else if (X->left && X->right && X->parent) { // ���� ���� � �����, � ������ � ���� ��������
			tree* A = X->left;
			if (X->parent->i > i) // ���� �������� �������� ������ �������� ��������
				X->parent->left = X->right; // � �������� � ����� ����� ��������� ������ ����� �������� ��������
			else
				X->parent->right = X->right;
			X = X->parent;
			AddDel(A, X);	
		}
		else if (X->left && X->right && !X->parent) { // ���� ���� ����� � ������, �� ��� �������� / (������)
			tree* L = X->left; // ������� �������� ����� �����
			tree* R = X->right; // � ������
			X->i = R->i; // �������� ���������� ������ ����� ��� ��������
			X->left = R->left;
			X->right = R->right;
			search++;
			AddDel(L, X); // � �� ��� ������� �������� 
		}
		else if (!X->left && X->right && !X->parent) { // ���� ��� ������ � ��������, �� ���� ������ / (������)
			tree* R = X->right;
			X->i = R->i;
			X->left = NULL;
			X->right = R->right;
			search++;
		}
		else if (X->left && !X->right && !X->parent) { // ���� ��� ������� � ��������, �� ���� ����� / (������)
			tree* L = X->left;
			X->i = L->i;
			X->left = L->left;
			X->right = NULL;
			search++;
		}
	}
		else { // ����� ���������� � ������ �������� ������
			Del(X->left, i);
			Del(X->right, i);
		}
}


int main() {
	setlocale(LC_ALL, "RUS"); // ������� ����
	tree* X = NULL; // �������������� ������
	int c, cc;
	cout << "������� ���������� ��������� � ������: ";
	cin >> c;
	system("cls"); // ������� ����� �������
	for (int i = 0; i < c; i++) { // ��������� ������
		cout << "������� [" << i << "] ������� ������: ";
		cin >> cc;
		Push(X, cc);
	}
	bool fl = false;
	do { // ����
		system("cls");
		cout << "===�������� ��������===" << endl;
		cout << "\n1 - ������ �����\n2 - �������� �����\n3 - ������������ �����\n4 - ����� �������\n5 - ������� �������\n6 - ������� ���������\n��� �����: ";
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
			cout << "������� ������� �������: ";
			cin >> cc;
			search = 0;
			Search(X, cc);
			if (search > 0)
				cout << "������� [" << cc << "] ������" << endl;
			else
				cout << "������� [" << cc << "] �� ������" << endl;
			break;
		case 5:
			cout << "������� ��������� �������: ";
			cin >> cc;
			search = 0;
			Del(X, cc);
			if (search > 0)
				cout << "������� [" << cc << "] ������� ������" << endl;
			else
				cout << "������� [" << cc << "] �� ������" << endl;
			break;
		case 6:
			fl = true;
			break;
		}
		system("pause");
	} while (fl == false);
	return 0;
}