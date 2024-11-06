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
