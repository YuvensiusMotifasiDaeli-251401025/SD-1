#include <iostream>
#include <vector>
using namespace std;

// TODO : Fungsi Bergabung Kembali
void merge(vector<int>& arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;

    vector<int> temp;

    // Membandingkan dan menggabungkan kedua bagian
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    //Memasukkan sisa elemen bagian kiri
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    //Memasukkan sisa elemen bagian kanan
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Menyalin hasil penggabungan ke array asli
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}


// TODO : Memecah Barisan
void mergeSort(vector<int>& arr, int left, int right) {
    if(left >= right){
        return;
    }

    // menentukan titik tengah
    int mid = left + (right - left) / 2;

    // memecah bagian kiri
    mergeSort(arr, left, mid);

    // memecah bagian kanan
    mergeSort(arr, mid + 1, right);

    // menggabungkan kedua bagian
    merge(arr, left, mid, right);
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   
    mergeSort(data, 0, n - 1);
   
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;
}