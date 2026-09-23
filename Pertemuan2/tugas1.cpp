#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void tambahDiAwal(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = head;
    head = baru;
}

void tambahDiAkhir(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
        return;
    }

    Node* bantu = head;
    while (bantu->next != nullptr) {
        bantu = bantu->next;
    }
    bantu->next = baru;
}

void tambahSetelahNilai(int nilaiBaru, int nilaiCari) {
    Node* bantu = head;
    while (bantu != nullptr && bantu->data != nilaiCari) {
        bantu = bantu->next;
    }

    if (bantu == nullptr) {
        cout << "Nilai " << nilaiCari << " tidak ditemukan dalam list!" << endl;
        return;
    }

    Node* baru = new Node();
    baru->data = nilaiBaru;
    baru->next = bantu->next;
    bantu->next = baru;
}

void hapusBerdasarkanNilai(int nilai) {
    if (head == nullptr) {
        cout << "Linked List kosong, tidak ada yang dihapus!" << endl;
        return;
    }

    if (head->data == nilai) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* bantu = head;
    while (bantu->next != nullptr && bantu->next->data != nilai) {
        bantu = bantu->next;
    }

    if (bantu->next == nullptr) {
        cout << "Nilai " << nilai << " tidak ditemukan dalam list!" << endl;
        return;
    }

    Node* hapus = bantu->next;
    bantu->next = hapus->next;
    delete hapus;
}

void tampilkanList() {
    cout << "Isi Linked List: ";
    Node* bantu = head;
    while (bantu != nullptr) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int pilihan, nilai, nilaiCari;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====" << endl;
        cout << "1. Tambah di awal" << endl;
        cout << "2. Tambah di akhir" << endl;
        cout << "3. Tambah setelah nilai tertentu" << endl;
        cout << "4. Hapus berdasarkan nilai" << endl;
        cout << "5. Tampilkan Linked List" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahDiAwal(nilai);
                tampilkanList();
                break;

            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahDiAkhir(nilai);
                tampilkanList();
                break;

            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiCari;
                tambahSetelahNilai(nilai, nilaiCari);
                tampilkanList();
                break;

            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusBerdasarkanNilai(nilai);
                tampilkanList();
                break;

            case 5:
                tampilkanList();
                system("pause");
                break;

            case 6:
                cout << "Keluar dari program..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 6);

    return 0;
}