#include "doublelist.h"
#include <iostream>

void createList(List& L) {
    L.first = nullptr;
    L.last = nullptr;
}

address alokasi(infotype x) {
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

void printInfo(List L) {
    address P = L.first;
    while (P != nullptr) {
        std::cout << "Nomor Polisi: " << P->info.nopol << std::endl;
        std::cout << "Warna: " << P->info.warna << std::endl;
        std::cout << "Tahun Buat: " << P->info.thnBuat << std::endl;
        std::cout << std::endl;
        P = P->next;
    }
}

void insertLast(List& L, address P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != nullptr) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
