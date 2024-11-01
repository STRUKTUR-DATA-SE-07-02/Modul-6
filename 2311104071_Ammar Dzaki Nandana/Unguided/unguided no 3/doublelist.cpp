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
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
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

// Menghapus elemen pertama
void deleteFirst(List &L, ElmList* &P) {
    if (L.First != nullptr) {
        P = L.First;
        if (L.First == L.Last) { // Hanya satu elemen
            L.First = nullptr;
            L.Last = nullptr;
        } else { // Lebih dari satu elemen
            L.First = L.First->next;
            L.First->prev = nullptr;
        }
        P->next = nullptr;
        dealokasi(P);
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, ElmList* &P) {
    if (L.Last != nullptr) {
        P = L.Last;
        if (L.First == L.Last) { // Hanya satu elemen
            L.First = nullptr;
            L.Last = nullptr;
        } else { // Lebih dari satu elemen
            L.Last = L.Last->prev;
            L.Last->next = nullptr;
        }
        P->prev = nullptr;
        dealokasi(P);
    }
}

// Menghapus elemen setelah elemen tertentu
void deleteAfter(ElmList* Prec, ElmList* &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
        dealokasi(P);
    }
}
