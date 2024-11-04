#include "doublelist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

address allocate(infotype x) {
    address newElement = new ElmList;
    newElement->info = x;
    newElement->next = nullptr;
    newElement->prev = nullptr;
    return newElement;
}

void deallocate(address &P) {
    delete P;
    P = nullptr;
}

bool isNopolExists(const List &L, const string &nopol) {
    address P = L.first;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void printInfo(const List &L) {
    address P = L.first;
    int index = 1;
    cout << "DATA LIST " << index++ << endl;
    while (P != nullptr) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.tahun << endl;
        cout << "--------------------------" << endl;
        P = P->next;
    }
}

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
