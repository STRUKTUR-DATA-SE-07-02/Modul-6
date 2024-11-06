#include "doublelist.h"

void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

address alokasi(infotype x) {
    address p = new ElmList;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = nullptr;
}

void insertLast(List &L, address p) {
    if (L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

void printInfo(List L) {
    address p = L.first; 
    int i = 1;
    while (p != nullptr) {
        cout << "DATA LIST " << i << endl;
        cout << "no polisi : " << p->info.nopol << endl;
        cout << "warna     : " << p->info.warna << endl;
        cout << "tahun     : " << p->info.tahun << endl << endl;
        p = p->next;
        i++;
    }
}

address findElm(List L, string nopol) {
    address p = L.first;
    while (p != nullptr) {
        if (p->info.nopol == nopol) {
            return p; 
        }
        p = p->next;
    }
    return nullptr;
}

void deleteFirst(List &L, address &p) {
    if (L.first != nullptr) {
        p = L.first;
        if (L.first == L.last) { 
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = L.first->next;
            L.first->prev = nullptr;
        }
        p->next = nullptr;
    }
}

void deleteLast(List &L, address &p) {
    if (L.last != nullptr) {
        p = L.last;
        if (L.first == L.last) { 
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.last = L.last->prev;
            L.last->next = nullptr;
        }
        p->prev = nullptr;
    }
}

void deleteAfter(address Prec, address &p) {
    if (Prec != nullptr && Prec->next != nullptr) {
        p = Prec->next;
        Prec->next = p->next;
        if (p->next != nullptr) {
            p->next->prev = Prec;
        }
        p->next = nullptr;
        p->prev = nullptr;
    }
}
