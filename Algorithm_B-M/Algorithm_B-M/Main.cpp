#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> Prefix(string X) { // �������-�������
	vector <int> A;
	for (int i = 0; i < 256; i++) // �������� 256 ��������� ��� ��������
		A.push_back(-1); // � ��������
	for (int i = 0; i < X.size(); i++) // � ������ ����� �������� ������� ��������
		A[X[i]] = i;
	return A;
}

void BM(string X, string Y) { // �������� ������ � ����
	int i = 0;
	vector <int> A;
	if (Y.size() > X.size()) // ���� ������ ������� ������ ������
		cout << "������-������� ������ ������!" << endl;
	else {
		A = Prefix(Y);
		while (i <= (X.size() - Y.size())) { // ����������� �� ������
			int j = Y.size() - 1;
			while (j >= 0 && Y[j] == X[i + j]) // ������� ���������� � ��������� �� ������ �����
				j--;
			if (j < 0) { // ���� �������, ������� �����
				cout << i << " ";
				if (i + Y.size() < X.size()) 
					i += Y.size() - A[X[i + Y.size()]]; // � ������� ������� ��� ��������
				else // ����� ������ ��������� � ���������� �������
					i++;
			}
			else // ����� ���������� �������� ��� �������� ������ + ��������
				i += 1 > j - A[X[i + j]] ? 1 : j - A[X[i + j]]; 
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	string X, Y;
	cout << "������� ������: ";
	cin >> X;
	cout << "������� ������-�������: ";
	cin >> Y;
	cout << "���������: ";
	BM(X, Y);
	cout << endl;
	system("pause");
	return 0;
}