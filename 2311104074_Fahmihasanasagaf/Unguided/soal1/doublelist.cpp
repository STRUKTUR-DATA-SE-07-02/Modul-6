#include "doublelist.h"
#include <iostream>
using namespace std;

// Membuat list baru dengan First dan Last bernilai null
void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

// Mengalokasikan memori untuk elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

// Menghapus alokasi memori
void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// Menambahkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

// Menampilkan semua elemen dari list
void printInfo(List L) {
    address P = L.First;
    while (P != nullptr) {
        cout << "Nopol: " << P->info.nopol << ", Warna: " << P->info.warna << ", Tahun Buat: " << P->info.thnBuat << endl;
        P = P->next;
    }
}

