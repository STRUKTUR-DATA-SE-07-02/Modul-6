#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <string>

using namespace std;

typedef struct kendaraan {
    string nopol;
    string warna;
    int tahun;
} infotype;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// Function Prototypes
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &p);
void printInfo(List L);
void insertLast(List &L, address p);

#endif
