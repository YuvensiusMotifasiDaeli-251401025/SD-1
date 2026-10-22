
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, key, posisi = -1;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah data harus lebih dari 0." << endl;
        return 0;
    }

    vector<int> data(n);

    cout << "Masukkan elemen data:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i << ": ";
        cin >> data[i];
    }

    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> key;

    // Proses pencarian sequential/linear
    for (int i = 0; i < n; i++) {
        if (data[i] == key) {
            posisi = i;
            break;
        }
    }

    // Output hasil
    if (posisi != -1) {
        cout << "\nData ditemukan di indeks ke-" << posisi << endl;
    } else {
        cout << "\nData tidak ditemukan" << endl;
    }

    return 0;
}
