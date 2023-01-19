#include <iostream>
#include <vector>

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

int KMP(string X, string Y) { // �������� ����� � ������� � ������
    if (Y.size() == 0) // ���� ������-������� ������
        return 0;
    vector <int> A = Prefix(Y); // �������� �������-������� �� ������-������� 
    int k = 0;
    for (int i = 0; i < X.size(); i++) // ����������� �� ������
        while (true) {
            if (Y.substr(k, 1) == X.substr(i, 1)) { // ���� ����� ������-������� ����� ����� ������
                k++;
                if (k == Y.size()) // ���� ��������������� ���������� ����� ������� ������-�������
                    return i + 1 - Y.size(); // ���������� ����� �������� + 1 - ������ ������-�������
                break; // ������������� ����
            }
            if (k == 0) // ���� �� �������
                break; // ������������� ����
            k = A[k - 1];
        }
    return -1;
}

int main() {
    setlocale(LC_ALL, "RUS");
    string X, Y;
    cout << "������� ������: ";
    cin >> X;
    cout << "������� ������-�������: ";
    cin >> Y;
    cout << "���������: " << KMP(X, Y) << endl;
    cout << endl;
    system("pause");
    return 0;
}