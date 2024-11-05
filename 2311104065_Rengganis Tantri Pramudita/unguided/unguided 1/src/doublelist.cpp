#include "doublelist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

ElmList* alokasi(const Kendaraan &x) {
    ElmList* P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(ElmList* &P) {
    delete P;
    P = nullptr;
}

void printInfo(const List &L) {
    ElmList* P = L.First;
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->next;
    }
}

void insertLast(List &L, ElmList* P) {
    if (L.First == nullptr) {  // Jika list kosong
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

ElmList* findElm(const List &L, const string &nopol) {
    ElmList* P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;  // Mengembalikan pointer ke elemen yang ditemukan
        }
        P = P->next;
    }
    return nullptr;  // Mengembalikan nullptr jika elemen tidak ditemukan
}

void deleteFirst(List &L, ElmList* &P) {
    if (L.First != nullptr) {
        P = L.First;
        if (L.First == L.Last) {  // Jika hanya satu elemen
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.First = L.First->next;
            L.First->prev = nullptr;
        }
        P->next = nullptr;
    }
}

void deleteLast(List &L, ElmList* &P) {
    if (L.Last != nullptr) {
        P = L.Last;
        if (L.First == L.Last) {  // Jika hanya satu elemen
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = nullptr;
        }
        P->prev = nullptr;
    }
}

void deleteAfter(ElmList* Prec, ElmList* &P) {
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
