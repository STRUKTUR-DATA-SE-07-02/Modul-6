#include "doublelist.h"

// Membuat list kosong
void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

// Mengalokasikan elemen baru
address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

// Dealokasi elemen
void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// Menampilkan informasi list
void printInfo(List L) {
    address P = L.first;
    while (P != nullptr) {
        cout << "Nopol: " << P->info.nopol << ", Warna: " << P->info.warna << ", Tahun: " << P->info.thnBuat << endl;
        P = P->next;
    }
}

// Menambahkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

// Mencari elemen berdasarkan nomor polisi
address findElm(List L, string nopol) {
    address P = L.first;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

// Menghapus elemen berdasarkan nomor polisi
void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == nullptr) {
        cout << "Elemen dengan nopol " << nopol << " tidak ditemukan." << endl;
        return;
    }

    if (P == L.first && P == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else if (P == L.first) {
        L.first = P->next;
        L.first->prev = nullptr;
    } else if (P == L.last) {
        L.last = P->prev;
        L.last->next = nullptr;
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }
    dealokasi(P);
}
