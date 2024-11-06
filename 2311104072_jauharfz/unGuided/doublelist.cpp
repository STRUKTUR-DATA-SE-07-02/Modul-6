#include "doublelist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.First;
    if(P == NULL) {
        cout << "List Kosong" << endl;
        return;
    }

    while(P != NULL) {
        cout << "Nomor Polisi: " << P->info.nopol << endl;
        cout << "Warna: " << P->info.warna << endl;
        cout << "Tahun Pembuatan: " << P->info.thnBuat << endl;
        cout << "------------------------" << endl;
        P = P->next;
    }
}

void insertLast(List &L, address P) {
    if(L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;
    while(P != NULL) {
        if(P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst(List &L, address &P) {
    if(L.First == NULL) {
        P = NULL;
        return;
    }

    P = L.First;
    if(L.First == L.Last) {
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.First = L.First->next;
        L.First->prev = NULL;
        P->next = NULL;
    }
}
