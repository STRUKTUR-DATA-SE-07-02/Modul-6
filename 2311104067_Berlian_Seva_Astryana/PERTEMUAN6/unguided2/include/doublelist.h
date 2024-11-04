#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
struct ElmList {
    infotype info;
    ElmList *next;
    ElmList *prev;
};
typedef ElmList* address;

struct List {
    address First;
    address Last;
};

// Prosedur dan Fungsi
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
