#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>
using namespace std;

// Definisi struktur kendaraan
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

// Struktur elemen list
struct ElmList {
    infotype info;
    address next;
    address prev;
};

// Struktur List
struct List {
    address First;
    address Last;
};

// Deklarasi fungsi dan prosedur
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, string nopol);  // Menambahkan deklarasi findElm
void deleteFirst(List &L, address &P);  // Menambahkan deklarasi deleteFirst

#endif
