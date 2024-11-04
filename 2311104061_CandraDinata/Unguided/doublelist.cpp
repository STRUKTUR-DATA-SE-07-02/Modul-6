#include "doublelist.h"
#include <iostream>

using namespace std;

// Initialize the list
void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

// Allocate a new element
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

// Deallocate an element
void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// Insert an element at the end of the list
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

// Print all elements in the list
void printInfo(const List &L) {
    address P = L.First;
    while (P != nullptr) {
        cout << "Nomor Polisi: " << P->info.nopol << endl;
        cout << "Warna: " << P->info.warna << endl;
        cout << "Tahun: " << P->info.thnBuat << endl << endl;
        P = P->next;
    }
}

// Find an element by nopol
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

// Delete the first element
void deleteFirst(List &L) {
    if (L.First != nullptr) {
        address P = L.First;
        if (L.First == L.Last) {
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.First = L.First->next;
            L.First->prev = nullptr;
        }
        dealokasi(P);
    }
}

// Delete the last element
void deleteLast(List &L) {
    if (L.Last != nullptr) {
        address P = L.Last;
        if (L.First == L.Last) {
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = nullptr;
        }
        dealokasi(P);
    }
}

// Delete a specific element after a given element
void deleteAfter(List &L, address P) {
    if (P != nullptr && P->next != nullptr) {
        address Q = P->next;
        P->next = Q->next;
        if (Q->next != nullptr) {
            Q->next->prev = P;
        } else {
            L.Last = P;
        }
        dealokasi(Q);
    }
}