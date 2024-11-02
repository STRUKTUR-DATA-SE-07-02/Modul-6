#include "doublelist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void printInfo(List L) {
    address P = L.First;
    cout << "\nDATA LIST" << endl;
    while (P != nullptr) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List &L, infotype x) {
    address P;
    bool found = false;

    P = L.First;
    while ((P != nullptr) && (!found)) {
        if (P->info.nopol == x.nopol) {
            found = true;
        } else {
            P = P->next;
        }
    }
    return P;
}

void deleteFirst(List &L, address &P) {
    if (L.First != nullptr) {
        P = L.First;
        if (L.First == L.Last) {
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.First = P->next;
            L.First->prev = nullptr;
            P->next = nullptr;
        }
    }
}

void deleteLast(List &L, address &P) {
    if (L.First != nullptr) {
        P = L.Last;
        if (L.First == L.Last) {
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.Last = P->prev;
            L.Last->next = nullptr;
            P->prev = nullptr;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != nullptr) {
        P = Prec->next;
        if (P != nullptr) {
            if (P->next == nullptr) { // P adalah elemen terakhir
                Prec->next = nullptr;
                P->prev = nullptr;
            } else {
                Prec->next = P->next;
                P->next->prev = Prec;
                P->next = nullptr;
                P->prev = nullptr;
            }
        }
    }
}

void deleteElm(List &L, string nopol) {
    address P;
    infotype x;
    x.nopol = nopol;

    P = findElm(L, x);
    if (P != nullptr) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(Prec, P);
        }
        dealokasi(P);
        cout << "Data berhasil dihapus" << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}
