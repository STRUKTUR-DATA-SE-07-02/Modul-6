#include "doublelist.h"

// Prosedur untuk membuat List baru (List kosong)
void createList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

// Fungsi untuk mengalokasikan elemen baru dengan data kendaraan
address alokasi(Kendaraan x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

// Prosedur untuk mengdealokasi elemen (menghapus node)
void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// Prosedur untuk mencetak seluruh informasi dalam List
void printInfo(const List &L) {
    address P = L.First;
    if (P == nullptr) {
        cout << "List kosong" << endl;
    } else {
        cout << "DATA LIST" << endl;
        int i = 1;
        while (P != nullptr) {
            cout << i << ".\n";
            cout << "No polisi : " << P->info.nopol << endl;
            cout << "Warna     : " << P->info.warna << endl;
            cout << "Tahun     : " << P->info.thnBuat << endl;
            P = P->next;
            i++;
        }
    }
}

// Prosedur untuk memasukkan elemen baru di akhir List
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

// Fungsi untuk memeriksa apakah nomor polisi sudah ada di dalam List
bool isNopolExist(const List &L, const string &nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

// Fungsi untuk mencari elemen berdasarkan nomor polisi
address findElm(const List &L, const string &nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

// Prosedur untuk menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First != nullptr) {
        P = L.First;
        if (L.First == L.Last) { // Jika hanya ada satu elemen
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.First = L.First->next;
            L.First->prev = nullptr;
        }
        P->next = nullptr;
    }
}

// Prosedur untuk menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.Last != nullptr) {
        P = L.Last;
        if (L.First == L.Last) { // Jika hanya ada satu elemen
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = nullptr;
        }
        P->prev = nullptr;
    }
}

// Prosedur untuk menghapus elemen setelah Prec
void deleteAfter(address Prec, address &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
}
