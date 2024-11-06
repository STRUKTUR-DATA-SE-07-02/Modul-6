#include "doublelist.h"
#include <iostream>

using namespace std;

void createList(List& L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(const Kendaraan& x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address& P) {
    delete P;
    P = nullptr;
}

void printInfo(const List& L) {
    if (L.First == nullptr) {
        cout << "List Kosong" << endl;
        return;
    }

    address P = L.First;
    cout << "\nIsi List : " << endl;
    while (P != nullptr) {
        cout << "Nomor Polisi  : " << P->info.nopol << endl;
        cout << "Warna         : " << P->info.warna << endl;
        cout << "Tahun Pembuatan: " << P->info.thnBuat << endl;
        cout << "------------------------" << endl;
        P = P->next;
    }
}

void insertLast(List& L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(const List& L, const string& nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void deleteFirst(List& L, address& P) {
    if (L.First == nullptr) {
        cout << "List Kosong" << endl;
        return;
    }

    P = L.First;
    if (L.First == L.Last) {
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        L.First = L.First->next;
        L.First->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLast(List& L, address& P) {
    if (L.First == nullptr) {
        cout << "List Kosong" << endl;
        return;
    }

    P = L.Last;
    if (L.First == L.Last) {
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        L.Last = L.Last->prev;
        L.Last->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfter(List& L, address Prec, address& P) {
    if (Prec == nullptr || Prec->next == nullptr) {
        cout << "Tidak ada elemen yang bisa dihapus" << endl;
        return;
    }

    P = Prec->next;
    Prec->next = P->next;
    
    if (P->next != nullptr) {
        P->next->prev = Prec;
    } else {
        L.Last = Prec;  // Update Last jika menghapus elemen terakhir
    }
    
    P->next = nullptr;
    P->prev = nullptr;
}