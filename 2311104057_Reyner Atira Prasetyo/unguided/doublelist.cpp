#include "doublelist.h"
#include <iostream>

using namespace std;
// Prosedur CreateList
void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

// Fungsi alokasi
address alokasi(kendaraan x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;
}

// Prosedur dealokasi
void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// Fungsi isDuplicate
bool isDuplicate(const List &L, const kendaraan &x) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == x.nopol) {
            return true; // Ditemukan duplikat berdasarkan nopol
        }
        P = P->next;
    }
    return false;
}

// Prosedur printInfo
void printInfo(const List &L) {
    address P = L.First;
    while (P != nullptr) {
        cout << "Nopol: " << P->info.nopol 
             << "\nWarna: " << P->info.warna 
             << "\nTahun: " << P->info.thnBuat << "\n" << endl;
        P = P->next;
    }
}

// Prosedur insertLast
void insertLast(List &L, address P) {
    if (P == nullptr) return;

    if (isDuplicate(L, P->info)){
        cout << "Nopol: " << P->info.nopol << " sudah terdaftar. Data tidak ditambahkan.\n" << endl;
        dealokasi(P);
        return;
    }

    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

// Fungsi untuk mencari elemen dalam list
address findElm(const List &L, const string &nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P; // Ditemukan
        }
        P = P->next;
    }
    return nullptr; // Tidak ditemukan
}

// Prosedur untuk menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First == nullptr) {
        cout << "List kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }
    P = L.First; // Simpan elemen pertama
    L.First = L.First->next;
    if (L.First != nullptr) {
        L.First->prev = nullptr;
    } else {
        L.Last = nullptr; // Jika list menjadi kosong
    }
    dealokasi(P); // Hapus elemen
    cout << "Elemen pertama dihapus." << endl;
}

// Prosedur untuk menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.Last == nullptr) {
        cout << "List kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }
    P = L.Last; // Simpan elemen terakhir
    L.Last = L.Last->prev;
    if (L.Last != nullptr) {
        L.Last->next = nullptr;
    } else {
        L.First = nullptr; // Jika list menjadi kosong
    }
    dealokasi(P); // Hapus elemen
    cout << "Elemen terakhir dihapus." << endl;
}

// Prosedur untuk menghapus elemen setelah elemen tertentu
void deleteAfter(List &L, ElmList* prec, address &P) {
    if (prec == nullptr || prec->next == nullptr) {
        cout << "Tidak ada elemen setelah elemen yang diberikan." << endl;
        return;
    }
    P = prec->next; // Simpan elemen setelah
    prec->next = P->next;
    if (P->next != nullptr) {
        P->next->prev = prec;
    } else {
        L.Last = prec; // Jika dihapus adalah elemen terakhir
    }
    dealokasi(P); // Hapus elemen
    cout << "Elemen setelah elemen yang diberikan dihapus." << endl;
}