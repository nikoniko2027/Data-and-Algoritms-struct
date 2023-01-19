#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

    // Пирамидальная сортировка 

void Heap(vector<int>& a, int i, int n) {
    int max = i;
    for (int j = 1; j > 0; j++) {
        int c = 2 * i + 1; 
        if (c < n && a[c] > a[max])
            max = c;
        c++;
        if (c < n && a[c]> a[max])
            max = c;
        if (max == i)
            break;
        else {
            swap(a[max], a[i]);
            i = max;
        }
    }
}

    
void HeapSort(vector<int>& a) {
    for (int i = a.size() / 2; i >= 0; i--)
        Heap(a, i, a.size());
    for (int i = a.size() - 1; i >= 1; i--) {
        swap(a[0], a[i]);
        Heap(a, 0, i);
    }

}



    // Быстрая сортировка 

void quicksort(vector <int> &a, int l, int r) {
    int x = a[l], ll = l, rr = r;
    for (int i = l; i < r; i++) {
        while ((a[r] >= x) && (l < r))
            r--; 
        if (l != r) {
            a[l] = a[r]; 
            l++;
        }
        while ((a[l] <= x) && (l < r))
            l++; 
        if (l != r) {
            a[r] = a[l]; 
            r--; 
        }
    }
    a[l] = x;
    x = l;
    l = ll;
    r = rr;
    if (l < x) 
        quicksort(a, l, x - 1);
    if (r > x)
        quicksort(a, x + 1, r);
}




    // Сортировка слиянием

vector<int> merge(vector<int> left, vector<int> right) {
    int l = 0, r = 0;
    vector<int> res;
    while (l < left.size() && r < right.size())
        if (left[l] < right[r])
            res.push_back(left[l++]);
        else
            res.push_back(right[r++]);
    while (l < left.size())
        res.push_back(left[l++]);
    while (r < right.size())
        res.push_back(right[r++]);
    return res;
}

vector<int> mergeSort(vector<int>& b) {
    if (b.size() <= 1)
        return b;
    vector<int> left(b.begin(), b.begin() + b.size() / 2);
    vector<int> right(b.begin() + b.size() / 2, b.end());
    return merge(mergeSort(left), mergeSort(right));
}




int main() {
	setlocale(LC_ALL, "RUS");
	vector <int> arr, a, b, x, c;
    c.push_back(5000); 
    c.push_back(10000);
    c.push_back(50000);
    c.push_back(100000);

    for (int j = 0; j < c.size(); j++) {
        cout << "\nСортировки массива размерностью " << c[j] << " элементов\n" << endl;
        for (int i = 0; i < c[j]; i++) 
            arr.push_back(rand() % 100);
        a = arr;
        b = arr;
        x = arr;
        /*for (int i = 0; i < c; i++)
            cout << arr[i] << " ";
        cout << endl;*/

        int start_time = clock(); // начальное время
        quicksort(a, 0, arr.size() - 1);
        int end_time = clock(); // конечное время
        cout << "Быстрая сортировка - " << end_time - start_time << " мс" << endl;

        start_time = 0;
        end_time = 0;

        start_time = clock();
        b = mergeSort(b);
        end_time = clock(); // конечное время
        cout << "Сортировка слиянием - " << end_time - start_time << " мс" << endl;

        start_time = 0;
        end_time = 0;

        start_time = clock();
        HeapSort(x);
        end_time = clock(); // конечное время
        cout << "Пирамидальная сортировка - " << end_time - start_time << " мс" << endl;
        //for (int i = 0; i < arr.size(); i++)
        //    cout << arr[i] << " ";
        cout << endl;
        arr.clear();
        a.clear();
        b.clear();
        x.clear();
    }
	system("pause");
	return 0;
}

// int start_time = clock(); // начальное время
// int end_time = clock(); // конечное время
// int search_time = end_time - start_time; // искомое время
//cout << "\n\n\n" << search_time << endl;