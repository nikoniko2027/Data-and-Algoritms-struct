#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> Prefix(string x) { // �������-�������
	vector<int> X(x.size()); // ��������������� ������ �������� ���������� �������� � ������
	for (int i = 1; i < x.size(); i++) { // ����������� �� ������
		int j = X[i - 1];
		while (j > 0 && x[i] != x[j]) // ���� ������ ������ 0 � �������� �� ���������
			j = X[j - 1]; // ����������� ����������
		if (x[i] == x[j]) // ���� �������� �����
			j++; // �� ���������� �� 1 ������
		X[i] = j; // �������� ���������� �������� � ������� �������
	}
	return X;
}

vector<int> Z(string x) { // Z-�������
	vector<int> X(x.size()); // ��������������� ������ �������� ���������� �������� � ������
	for (int i = 1, l = 0, r = 0; i < x.size(); i++) { // ����������� �� ������
		if (i <= r) // ���� ������ � �������
			X[i] = min(r - i + 1, X[i - l]); // ����������� ����������
		while (i + X[i] < x.size() && x[X[i]] == x[i + X[i]]) // ���� �������� + ���������� ����� ������� ������ � ������� �� �������� ����� �������� �� �������� + ��������
			X[i]++; // ���������� �������� 
		if (i + X[i] - 1 > r) // ���� ����� �� ���������
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
	cout << "������� ������: ";
	cin >> x;
	do {
		system("cls");
		cout << "������: " << x << endl;
		cout << "\n=== ���� ===\n1 - �������-�������\n2 - Z-�������\n3 - �������� ������\n4 - ��������� ���������\n��� �����: ";
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
			cout << "������� ����� ������: ";
			cin >> x;
			break;
		}
		cout << endl;
		system("pause");
	} while (c != 4);
	return 0;
}