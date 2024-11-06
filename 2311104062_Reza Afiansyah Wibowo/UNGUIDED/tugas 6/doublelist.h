// doublelist.h
#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>

// Tipe data infotype (kendaraan)
struct Kendaraan {
    std::string nopol;
    std::string warna;
    int thnBuat;
};
typedef Kendaraan infotype;

// Tipe data address (pointer to ElmList)
typedef struct ElmList *address;

// Tipe data ElmList
struct ElmList {
    infotype info;
    address next;
    address prev;
};

// Tipe data List
struct List {
    address first;
    address last;
};

// Prototipe fungsi dan prosedur
void createList(List& L);
address alokasi(infotype x);
void dealokasi(address& P);
void printInfo(List L);
void insertLast(List& L, address P);

#endif // DOUBLELIST_H
