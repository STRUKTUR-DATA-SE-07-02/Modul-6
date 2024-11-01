#include "doublelist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

// Alokasi elemen baru
ElmList* alokasi(kendaraan x) {
    ElmList* P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

// Dealokasi elemen
void dealokasi(ElmList* &P) {
    delete P;
    P = nullptr;
}

// Menampilkan informasi kendaraan di list
void printInfo(const List &L) {
    ElmList* P = L.Last;
    cout << "DATA LIST 1" << endl;
    while (P != nullptr) {
        cout << "no polisi: " << P->info.nopol << endl;
        cout << "warna    : " << P->info.warna << endl;
        cout << "tahun    : " << P->info.thnBuat << endl;
        P = P->prev;
        if (P != nullptr) cout << endl;
    }
}

// Menambahkan elemen di akhir list
void insertLast(List &L, ElmList* P) {
    if (L.First == nullptr) { // List kosong
        L.First = P;
        L.Last = P;
    } else { // List tidak kosong
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

// Fungsi untuk mencari elemen berdasarkan nomor polisi
ElmList* findElm(List &L, const string &nopol) {
    ElmList* P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P; // Elemen ditemukan
        }
        P = P->next;
    }
    return nullptr; // Elemen tidak ditemukan
}
